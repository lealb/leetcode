import numpy as np
import pandas as pd
import xgboost as xgb
import matplotlib.pyplot as plt
import seaborn as sns
# 引入公共数据加载方法
from ddos_all import get_orgrin_data, get_data_set, label_encoder, max_min_sc, convert_tofloat32, split_X_y, xgb_model, get_report
"""
数据特征重要性选择
    0.数据加载处理
    1.降维
    2.xgboost选择重要性
    3.去除重要性，比较
    4.新增派生特征
    5.算法改进，比较
"""

# 公共方法


def get_train_data(file_path):
    #file_path = "D:\\01-Work\\LeetCode\\python\\ddos\\dataset\\fin.csv"
    X, y = get_data_set(file_path)
    # 简单处理
    # print(X[0],y[0])
    y = label_encoder(y)
    # X = max_min_sc(X)
    X = convert_tofloat32(X)
    return X, y


def pca_data(X, n_components=45, random_state=2019):
    """
    https://www.zhihu.com/question/38417101
    pca.explainedvariance_ratio(方差贡献占比)
    pca.explainedvariance(方差贡献绝对值)
    PCA是将n维特征映射到k维上（k<n），这k维特征是全新的正交特征，称为主元，是重新构造出来的k维特征，
    而不是简单的从n维特征中去除其余n-k维特征。
    降维后的结果是原来数据的所有特征。结果的每一个变量都是原先所有变量的加权组合
    """
    from sklearn.decomposition import PCA
    pca = PCA(n_components=n_components,
              copy=True,
              whiten=False,
              svd_solver='auto',
              tol=0.0,
              iterated_power='auto',
              random_state=random_state)
    return pca.fit_transform(X), pca.explained_variance_ratio_, pca.singular_values_


def xgb_train(X, y):
    import time
    X_train, X_test, y_train, y_test = split_X_y(X, y)
    start = time.time()
    xgb = xgb_model(X_train, y_train)
    y_pred = xgb.predict(X_test)
    print(get_report(y_test, y_pred))
    end = time.time()
    print("cost: %s" % (end-start))

# 比较pca前后的时间效率


def compare_pca(file_path):
    """
        可以更改随机种子，让每次训练的结果不一样，选择合适理想的结果
    """
    X, y = get_train_data(file_path)
    X = max_min_sc(X)
    print("降维前： ")
    xgb_train(X, y)
    X_pca, evr, sv = pca_data(X)
    print("降维后： ")
    print(evr)
    print(sv)
    xgb_train(X_pca, y)
    """
    降维前： 
                precision    recall  f1-score   support

            0     0.9995    0.9980    0.9987      1992
            1     0.9980    0.9995    0.9988      2008

        accuracy                         0.9988      4000
    macro avg     0.9988    0.9987    0.9987      4000
    weighted avg     0.9988    0.9988    0.9987      4000

    cost: 15.269680500030518
    降维后：
                precision    recall  f1-score   support

            0     0.9990    0.9955    0.9972      1992
            1     0.9955    0.9990    0.9973      2008

        accuracy                         0.9972      4000
    macro avg     0.9973    0.9972    0.9972      4000
    weighted avg     0.9973    0.9972    0.9972      4000

    cost: 15.143831491470337
    """
# xgboost 重要性选择
# 画图特征重要性 + 指标显示


def model_importance(model, num=20):
    xgb.plot_importance(model, max_num_features=num)


def select_importance(xgb_model_ddos, X_train, y_train, X_test, y_test):
    from sklearn.feature_selection import SelectFromModel
    from sklearn.metrics import accuracy_score
    import xgboost as xgb
    thresholds = np.sort(xgb_model_ddos.feature_importances_)
    for thresh in thresholds:
        # select features using threshold
        selection = SelectFromModel(
            xgb_model_ddos, threshold=thresh, prefit=True)
        print(selection.get_support())
        # X_train(selection.get_support)
        select_X_train = selection.transform(X_train)
        # train model
        selection_model = xgb.XGBClassifier()
        selection_model.fit(select_X_train, y_train)
        # eval model
        select_X_test = selection.transform(X_test)
        y_pred = selection_model.predict(select_X_test)
        predictions = [round(value) for value in y_pred]
        accuracy = accuracy_score(y_test, predictions)
        print("Thresh=%.5f, n=%d, Accuracy: %.4f%%" %
              (thresh, select_X_train.shape[1], accuracy * 100.0))

# 新增派生特征


def drop_feature(xgb_model_ddos, X_pca,y):
    fi = xgb_model_ddos.feature_importances_
    sort_index = sorted(range(len(fi)), key=lambda k: fi[k], reverse=True)
    X_drop10 = X_pca[:, sort_index[35:]]
    # 此时的分类矩阵为
    X_drop10_train, X_drop10_test, y_train, y_test = split_X_y(X_drop10, y)
    # default
    xgb_drop10_model = xgb.XGBClassifier(learning_rate=0.1,
                                         n_estimators=100,
                                         verbosity=1,
                                         silent=None,
                                         objective='binary:logistic',
                                         booster='gbtree',
                                         n_jobs=1,
                                         nthread=None,
                                         gamma=0,
                                         min_child_weight=1,
                                         max_delta_step=0,
                                         subsample=1,
                                         colsample_bytree=1,
                                         colsample_bylevel=1,
                                         colsample_bynode=1,
                                         reg_alpha=0,
                                         reg_lambda=1,
                                         scale_pos_weight=1,
                                         base_score=0.5,
                                         random_state=0,
                                         seed=None,
                                         missing=None)
    xgb_drop10_model.fit(X_drop10_train, y_train)
    y_drop10_pred = xgb_drop10_model.predict(X_drop10_test)
    print(get_report(y_test, y_drop10_pred))


def add_feature(file, X_drop10, xgb_drop10_model,y):
    ddos_data = get_orgrin_data(file)
    add_data = ddos_data[["Dst Port", "Protocol"]]
    add_data = add_data.to_numpy()
    X_new = X_drop10.copy()
    X_new_data = np.concatenate((X_new, add_data), axis=1)
    X_new_train, X_new_test, y_train, y_test = split_X_y(X_new_data, y)
    print(get_report(y_test, xgb_drop10_model.fit(
        X_new_train, y_train).predict(X_new_test)))

# 算法改进
class LeastSquaresLoss():
    """Least squares loss"""

    def gradient(self, actual, predicted):
        return actual - predicted

    def hess(self, actual, predicted):
        return np.ones_like(actual)


if __name__ == "__main__":
    # 更改文件路径
    file_path = "D:\\01-Work\\LeetCode\\python\\ddos\\dataset\\fin.csv"
    # compare_pca(file_path)
