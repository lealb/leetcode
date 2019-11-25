import numpy as np
import pandas as pd
from ddos_all import get_data_set, get_orgrin_data, label_encoder


def get_corr_mat(ddos_data):
    ddos_data["Label"] = ddos_data["Label"].map({"Benign": 0, "ddos": 1})
    corr_matrix = ddos_data.corr()
    return np.abs(corr_matrix["Label"].values) <= 0.03


"""
Subflow Fwd Byts     0.008577
TotLen Fwd Pkts      0.008577
Fwd Act Data Pkts    0.008119
Tot Fwd Pkts         0.007819
Subflow Fwd Pkts     0.007819
Fwd Header Len       0.007591
FIN Flag Cnt         0.005962
Bwd IAT Std         -0.020736
Bwd Header Len      -0.022382
TotLen Bwd Pkts     -0.022731
Subflow Bwd Byts    -0.022731
Tot Bwd Pkts        -0.031383
Subflow Bwd Pkts    -0.031383
Flow IAT Min        -0.040002
"""


def get_train_data(ddos_data, X_label, y):
    X = ddos_data[X_label]
    X = X.to_numpy()
    X = np.nan_to_num(X)
    from sklearn.model_selection import train_test_split
    X_train, X_test, y_train, y_test = train_test_split(X,
                                                        y,
                                                        test_size=0.2)
    return X_train, X_test, y_train, y_test


def train_data(X_train, X_test, y_train, y_test):
    from sklearn.tree import DecisionTreeClassifier
    dt_tree = DecisionTreeClassifier()
    dt_tree.fit(X_train, y_train)
    y_pred = dt_tree.predict(X_test)
    from sklearn.metrics import classification_report
    print(classification_report(y_test, y_pred, digits=4))


if __name__ == "__main__":
    # 继续减少特征,取相关性不大的10个特征做判别，准确率降低2-3百分点，尤其是召回率下降得比较快
    # 通过增加以上特征，准确率将提高
    ddos_14 = [
        "Subflow Fwd Byts", "TotLen Fwd Pkts", "Fwd Act Data Pkts", "Tot Fwd Pkts",
        "Subflow Fwd Pkts", "Fwd Header Len", "FIN Flag Cnt", "Bwd IAT Std",
        "Bwd Header Len", "TotLen Bwd Pkts", "Subflow Bwd Byts", "Tot Bwd Pkts",
        "Subflow Bwd Pkts", "Flow IAT Min"
    ]
    ddos_10 = [
        "Fwd Act Data Pkts", "Tot Fwd Pkts",
        "Subflow Fwd Pkts", "Fwd Header Len", "FIN Flag Cnt", "Bwd IAT Std",
        "Bwd Header Len", "TotLen Bwd Pkts", "Subflow Bwd Byts", "Tot Bwd Pkts"
    ]

    file_path = "D:\\01-Work\\LeetCode\\python\\ddos\\dataset\\fin.csv"
    ddos_data = get_orgrin_data(file_path)
    y = ddos_data["Label"]
    y = label_encoder(y)
    X_train, X_test, y_train, y_test = get_train_data(ddos_data, ddos_14, y)
    train_data(X_train, X_test, y_train, y_test)
    X_train, X_test, y_train, y_test = get_train_data(ddos_data, ddos_10, y)
    train_data(X_train, X_test, y_train, y_test)
    """
                  precision    recall  f1-score   support

           0     0.9834    0.9819    0.9826      1986
           1     0.9822    0.9836    0.9829      2014

    accuracy                         0.9828      4000
   macro avg     0.9828    0.9827    0.9827      4000
weighted avg     0.9828    0.9828    0.9827      4000

              precision    recall  f1-score   support

           0     0.9880    0.9433    0.9652      2012
           1     0.9452    0.9884    0.9663      1988

    accuracy                         0.9657      4000
   macro avg     0.9666    0.9659    0.9657      4000
weighted avg     0.9667    0.9657    0.9657      4000
    """
