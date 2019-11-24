
# ddos 代码整理版

# 导入处理的相关包
from sklearn.metrics import roc_curve, auc
import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
# pd.set_option('display.max_columns', None)

# 公共函数


# 数据读取
def get_orgrin_data(file_path):
    return pd.read_csv(file_path, low_memory=False)


def get_data_set(file_path):
    """
        读取相关数据
    """
    ddos_data = pd.read_csv(file_path)
    # 暂时剔除无意义的特征
    del ddos_data['Row']
    # 删除非数值列
    other_data = ddos_data.drop([
        'Flow ID', 'Src IP', 'Src Port', 'Dst IP', 'Dst Port', 'Protocol',
        'Timestamp'
    ],
        axis=1)
    # 删除空值
    other_data = other_data.dropna(how='all')
    # 转换为numpy  aarray
    new_data = other_data.to_numpy()
    # 拆分特征列和目标列
    X, y = new_data[:, :-1], new_data[:, -1]
    # 数值型转换类型
    X = X.astype(float)
    return X, y

# 简单特征处理部分


def max_min_sc(X):
    # 特征归一化处理
    from sklearn.preprocessing import MinMaxScaler
    min_max_scaler = MinMaxScaler()
    return min_max_scaler.fit_transform(X)


def label_encoder(y):
    # 标签数值化，方便处理
    from sklearn.preprocessing import LabelEncoder
    le = LabelEncoder()
    return le.fit_transform(y)


def deal_nan_inf(X):
    """
    处理inf和nan
    """
    import numpy as np
    return np.nan_to_num(X)


def convert_tofloat32(X):
    """
    由于算法对数据集类型的不同，转换函数
    """
    dt_X = X.astype('float32')
    dt_X = np.nan_to_num(dt_X)
    return dt_X


def is_nan_inf(X):
    """
    判断是否有空值或者inf值
    """
    return np.isinf(X).any() or np.isnan(X).any()
# 数据集处理部分


def split_X_y(X, y):
    # 拆分数据集
    from sklearn.model_selection import train_test_split
    X_train, X_test, y_train, y_test = train_test_split(X,
                                                        y,
                                                        test_size=0.2,
                                                        random_state=2019)
    return X_train, X_test, y_train, y_test

# 模型部分


def knn_model(X_train, y_train):
    """
        K邻近
    """
    from sklearn.neighbors import KNeighborsClassifier
    # 需要全部转换为数值型
    knn = KNeighborsClassifier(n_neighbors=6,
                               weights='uniform',
                               algorithm='auto',
                               leaf_size=30,
                               p=2,
                               metric='minkowski',
                               metric_params=None,
                               n_jobs=10)
    knn.fit(X_train, y_train)
    return knn


def dt_model(X_train, y_train):
    """
        决策树
    """
    from sklearn.tree import DecisionTreeClassifier
    dec_tree = DecisionTreeClassifier(criterion='gini',
                                      splitter='best',
                                      max_depth=5,
                                      min_samples_split=2,
                                      min_samples_leaf=1,
                                      min_weight_fraction_leaf=0.0,
                                      max_features=None,
                                      random_state=None,
                                      max_leaf_nodes=None,
                                      min_impurity_decrease=0.0,
                                      min_impurity_split=None,
                                      class_weight=None,
                                      presort=False)
    dec_tree.fit(X_train, y_train)
    return dec_tree


def rf_model(X_train, y_train):
    """
        RF 随机森林
    """
    from sklearn.ensemble import RandomForestClassifier
    rf = RandomForestClassifier(
        n_estimators=200,
        criterion='gini',
        max_depth=5,  # 最大深度
        min_samples_split=2,
        min_samples_leaf=1,
        min_weight_fraction_leaf=0.0,
        max_features='auto',
        max_leaf_nodes=None,
        min_impurity_decrease=0.0,
        min_impurity_split=None,
        bootstrap=True,
        oob_score=False,
        n_jobs=30,
        random_state=None,
        verbose=0,
        warm_start=False,
        class_weight=None)
    rf.fit(X_train, y_train)
    return rf


def xgb_model_sk(X_train, y_train):
    # XGBoot
    from sklearn.ensemble import GradientBoostingClassifier
    xgb = GradientBoostingClassifier(learning_rate=0.2,
                                     n_estimators=100,
                                     subsample=1.0,
                                     criterion='friedman_mse',
                                     min_samples_split=2,
                                     min_samples_leaf=1,
                                     min_weight_fraction_leaf=0.0,
                                     max_depth=5,
                                     min_impurity_decrease=0.0,
                                     min_impurity_split=None,
                                     init=None,
                                     random_state=None,
                                     max_features=None,
                                     verbose=0,
                                     max_leaf_nodes=None,
                                     warm_start=False,
                                     presort='auto',
                                     validation_fraction=0.1,
                                     n_iter_no_change=None,
                                     tol=0.0001)
    xgb.fit(X_train, y_train)
    return xgb


def xgb_model(X_train, y_train):
    import xgboost as xgb
    xgb_model_sk = xgb.XGBClassifier(max_depth=5,
                                     learning_rate=0.1,
                                     n_estimators=160,
                                     verbosity=1,
                                     silent=True,
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
    xgb_model_sk.fit(X_train, y_train)
    return xgb_model_sk


def hmm_model(X_train, y_train):
    # HMM
    # 需要安装包 hmmlearn
    from hmmlearn import hmm
    h = hmm.GaussianHMM(n_components=5,
                        covariance_type='diag',
                        min_covar=0.001,
                        startprob_prior=1.0,
                        transmat_prior=1.0,
                        means_prior=0,
                        means_weight=0,
                        covars_prior=0.01,
                        covars_weight=1,
                        algorithm='viterbi',
                        random_state=None,
                        n_iter=10,
                        tol=0.01,
                        verbose=False,
                        params='stmc',
                        init_params='stmc')
    h.fit(X_train, y_train)
    return h
# 分类指标评估部分


def get_accuracy_score(y_test, y_pred):
    # 准确率
    from sklearn.metrics import accuracy_score
    return accuracy_score(y_test, y_pred)


def get_average_precision_score(y_test, y_pred):
    # 平均准确率
    from sklearn.metrics import average_precision_score
    return average_precision_score(y_test, y_pred)


def get_confusion_matrix(y_test, y_pred):
    # 测试集混淆矩阵
    from sklearn.metrics import confusion_matrix
    return confusion_matrix(y_true=y_test, y_pred=y_pred)


def get_report(y_test, y_pred):

    # F1-score
    from sklearn.metrics import classification_report
    return classification_report(y_test, y_pred,digits=4)


# 获得精确率与召回率
def get_acc_recall(y_test, y_pred):
    """
    获得精确率与召回率
    """
    con_mat = get_confusion_matrix(y_test, y_pred)
    return con_mat[0, 0] / (con_mat[0, 0] + con_mat[0, 1]), con_mat[0, 0] / (
        con_mat[0, 0] + con_mat[0, 1])


# AOC曲线
sns.set_style("whitegrid")
# %matplotlib inline


def get_aoc(y_test, y_pred):
    """
    y_test：实际的标签
    y_pred：预测的概率值
    """
    fpr, tpr, thresholds = roc_curve(y_test, y_pred)
    roc_auc = auc(fpr, tpr)
    # 画图，只需要plt.plot(fpr,tpr),变量roc_auc只是记录auc的值，通过auc()函数能计算出来
    plt.plot(fpr, tpr, lw=1, label='ROC(area = %0.4f)' % (roc_auc))
    plt.xlabel("FPR (False Positive Rate)")
    plt.ylabel("TPR (True Positive Rate)")
    plt.title("Receiver Operating Characteristic, ROC(AUC = %0.4f)" %
              (roc_auc))
    # plt.show()


def get_roc_score(y_test, y_pred):
    """
    计算roc score
    """
    from sklearn.metrics import roc_auc_score
    return roc_auc_score(y_test, y_pred)


def get_evaluation_index(y_test, y_pred):
    print("1.accuracy_score: %.4f" % get_accuracy_score(y_test, y_pred))
    print("2.average_precision_score: %.4f" %
          get_average_precision_score(y_test, y_pred))
    print("3.confusion_matrix:\n%s" % get_confusion_matrix(y_test, y_pred))
    print("4.acuracyc&recall: (%.4f,%.4f)" % get_acc_recall(y_test, y_pred))
    print("5.get_report:\n%s" % get_report(y_test, y_pred))
    print("6.roc_auc_score: %s" % get_roc_score(y_test, y_pred))
    #print("7.AUC:")
    #get_aoc(y_test, y_pred)


# 主函数
if __name__ == "__main__":
    file_path = "D:\\01-Work\\LeetCode\\python\\ddos\\dataset\\fin.csv"
    X, y = get_data_set(file_path)
    # 简单处理
    # print(X[0],y[0])
    y = label_encoder(y)
    X = convert_tofloat32(X)
    # 获得数据集
    X_train, X_test, y_train, y_test = split_X_y(X, y)
    # 训练
    dt = dt_model(X_train, y_train)
    dt_y_pred = dt.predict(X_test)
    # 评估
    # print("1.accuracy_score: %.4f" % get_accuracy_score(y_test, y_pred))
    #get_evaluation_index(y_test, dt_y_pred)
    """
    1.accuracy_score: 0.9910
    2.average_precision_score: 0.9857
    3.confusion_matrix:
    [[1970   22]
    [  14 1994]]
    4.acuracyc&recall: (0.9890,0.9890)
    5.get_report:
                precision    recall  f1-score   support

            0       0.99      0.99      0.99      1992
            1       0.99      0.99      0.99      2008

        accuracy                           0.99      4000
    macro avg       0.99      0.99      0.99      4000
    weighted avg       0.99      0.99      0.99      4000

    6.roc_auc_score: 0.9909918558696938
    """
    xgb = xgb_model(X_train, y_train)
    xgb_y_pred = xgb.predict(X_test)
    # get_evaluation_index(y_test, xgb_y_pred)
    """
    1.accuracy_score: 0.9988
    2.average_precision_score: 0.9978
    3.confusion_matrix:
    [[1988    4]
    [   1 2007]]
    4.acuracyc&recall: (0.9980,0.9980)
    5.get_report:
                precision    recall  f1-score   support

            0       1.00      1.00      1.00      1992
            1       1.00      1.00      1.00      2008

        accuracy                           1.00      4000
    macro avg       1.00      1.00      1.00      4000
    weighted avg       1.00      1.00      1.00      4000

    6.roc_auc_score: 0.9987469799516793
    """
    knn = knn_model(X_train, y_train)
    knn_y_pred = knn.predict(X_test)
    get_evaluation_index(y_test, knn_y_pred)
    """
    1.accuracy_score: 0.9800
    2.average_precision_score: 0.9722
    3.confusion_matrix:
    [[1959   33]
    [  47 1961]]
    4.acuracyc&recall: (0.9834,0.9834)
    5.get_report:
                precision    recall  f1-score   support

            0       0.98      0.98      0.98      1992
            1       0.98      0.98      0.98      2008

        accuracy                           0.98      4000
    macro avg       0.98      0.98      0.98      4000
    weighted avg       0.98      0.98      0.98      4000

6.roc_auc_score: 0.9800136802188835
    """
    rf = rf_model(X_train, y_train)
    rf_y_pred = rf.predict(X_test)
    get_evaluation_index(y_test, rf_y_pred)
    """
    1.accuracy_score: 0.9895
    2.average_precision_score: 0.9795
    3.confusion_matrix:
    [[1950   42]
    [   0 2008]]
    4.acuracyc&recall: (0.9789,0.9789)
    5.get_report:
                precision    recall  f1-score   support

            0       1.00      0.98      0.99      1992
            1       0.98      1.00      0.99      2008

        accuracy                           0.99      4000
    macro avg       0.99      0.99      0.99      4000
    weighted avg       0.99      0.99      0.99      4000

    6.roc_auc_score: 0.9894578313253012
    """
    # auc图形比较
    plt.figure()
    plt.subplot(221)
    get_aoc(y_test, dt_y_pred)
    plt.subplot(222)
    get_aoc(y_test, xgb_y_pred)
    plt.subplot(223)
    get_aoc(y_test, knn_y_pred)
    plt.subplot(224)
    get_aoc(y_test, rf_y_pred)
    plt.show()

