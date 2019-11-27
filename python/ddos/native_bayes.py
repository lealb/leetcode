
# 引入公共数据加载方法
from ddos_all import get_data_set, convert_tofloat32, label_encoder, max_min_sc,  split_X_y, get_evaluation_index

if __name__ == "__main__":
    file_path = "D:\\01-Work\\LeetCode\\python\\ddos\\dataset\\fin.csv"
    X, y = get_data_set(file_path)
    # 简单处理
    # print(X[0],y[0])
    y = label_encoder(y)
    X = convert_tofloat32(X)
    # 获得数据集
    X_train, X_test, y_train, y_test = split_X_y(X, y)
    from sklearn.naive_bayes import GaussianNB
    clf = GaussianNB()
    clf.fit(X_train, y_train)
    nb_y_pred = clf.predict(X_test)
    get_evaluation_index(y_test, nb_y_pred)
    """
    1.accuracy_score: 0.4980
    2.average_precision_score: 0.5020
    3.confusion_matrix:
    [[1992    0]
    [2008    0]]
    4.acuracyc&recall: (1.0000,1.0000)
    D:\Anaconda3\lib\site-packages\sklearn\metrics\classification.py:1437: UndefinedMetricWarning: Precision and F-score are ill-defined and being set to 0.0 in labels with no predicted samples.
    'precision', 'predicted', average, warn_for)
    5.get_report:
                precision    recall  f1-score   support

            0     0.4980    1.0000    0.6649      1992
            1     0.0000    0.0000    0.0000      2008

        accuracy                         0.4980      4000
    macro avg     0.2490    0.5000    0.3324      4000
    weighted avg     0.2480    0.4980    0.3311      4000
    """
