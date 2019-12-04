# -*- encoding: utf-8 -*-
'''
@File    :   perason.py
@Time    :   2019/12/04 11:25:32
@License :   (C)Copyright 2018-2019
@Desc    :   None
'''

# here put the import lib

import pandas as pd
import numpy as np
import math


class recommender(object):
    def o_distance(self, usr1, usr2):
        distance = 0
        for movie in usr1.keys():
            if movie in usr2.keys():
                distance += abs(usr1[movie]-usr2[movie])**2
        return math.sqrt(distance)

    def pearson_distance(self, usr1, usr2):
        """
            皮尔逊相关系数距离

        """
        sum_x_y = 0
        sum_x = 0
        sum_y = 0
        sum_x_2 = 0
        sum_y_2 = 0
        n = 0
        for movie in usr1.keys():
            if movie in usr2.keys():
                n += 1
                x = usr1[movie]
                y = usr2[movie]
                sum_x_y += x*y
                sum_x += x
                sum_y += y
                sum_x_2 += x**2
                sum_y_2 += y**2
        if n == 0:
            return 0
        denominator = math.sqrt(sum_x_2-float(sum_x**2)/n) * \
            math.sqrt(sum_y_2-float(sum_y**2)/n)
        if denominator == 0:
            return 0
        return (sum_x_y - float(sum_x*sum_y)/n)/denominator

    def k_nearst(self, k):
        distances = []
        for usr, rate in self.usr_rating.items():
            if not usr == self.usr:
                distance = self.pearson_distance(
                    self.usr_rating[self.usr], self.usr_rating[usr])
                if distance:
                    distances.append((usr, distance))
        distances.sort(key=lambda item: item[1], reverse=True)
        # print(distances)
        return distances[:k]

    def load_data(self, path):
        with open(path) as f:
            lines = f.readlines()
        usr_name = [i.strip('"') for i in lines[0].strip().split(',')[1:]]
        for line in lines[1:]:
            items = line.strip().split(',')
            movie = items[0].strip('"')
            for index in range(1, len(items)):
                if not items[index] == '':
                    if usr_name[index-1] not in self.usr_rating:
                        self.usr_rating[usr_name[index-1]
                                        ] = {movie: int(items[index])}
                    else:
                        self.usr_rating[usr_name[index-1]
                                        ][movie] = int(items[index])

    def recomend_k(self, nearst, k):
        recommend = {}
        total_distance = 0
        for item in nearst:
            total_distance += item[1]
        for item in nearst:
            u_name = item[0]
            weight = float(item[1])/total_distance
            for movie, rate in self.usr_rating[u_name].items():
                if movie not in self.usr_rating[self.usr].keys():
                    if movie not in recommend.keys():
                        recommend[movie] = rate*weight
                    else:
                        recommend[movie] += rate*weight
        print(recommend)
        top_k = list(recommend.items())
        top_k.sort(key=lambda x: x[1], reverse=True)
        if k > len(top_k):
            return top_k
        else:
            return top_k[:k]

    def __init__(self, path, usr):
        self.path = path
        self.usr = usr
        self.usr_rating = {}
        self.load_data(path)

    def run(self):
        nearst = self.k_nearst(5)
        print(nearst)
        top_k = self.recomend_k(nearst, 5)
        for item in top_k:
            print(item[0]+"\t"+str(item[1]))


def get_corr_mat(ddos_data):
    ddos_data["Label"] = ddos_data["Label"].map({"Benign": 0, "ddos": 1})
    corr_matrix = ddos_data.corr()
    return corr_matrix[np.abs(corr_matrix["Label"].values) <= 0.06]["Label"]


def get_corr(file_path):
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
    return other_data


if __name__ == "__main__":
    path = 'python/ddos/dataset/Movie_Ratings.csv'
    path1 = 'python/ddos/dataset/fin.csv'
    # r = recommender(path, 'vanessa')
    # r.run()
    ddos_data = get_corr(path1)
    print(get_corr_mat(ddos_data))
    """
    Flow Duration      -0.037632
    Tot Fwd Pkts        0.021519
    Tot Bwd Pkts        0.031197
    TotLen Bwd Pkts     0.029532
    Flow IAT Mean       0.009964
    Flow IAT Std        0.058401
    Flow IAT Max        0.051038
    Flow IAT Min       -0.003369
    Fwd IAT Std         0.032692
    Fwd IAT Max        -0.029881
    Bwd IAT Mean       -0.042183
    Bwd IAT Std         0.000678
    Bwd IAT Max        -0.027402
    Bwd PSH Flags      -0.013752
    Fwd Header Len      0.029048
    Bwd Header Len      0.033142
    Bwd Pkts/s          0.028105
    Subflow Fwd Pkts    0.021519
    Subflow Bwd Pkts    0.031197
    Subflow Bwd Byts    0.029532
    Active Mean        -0.004939
    Active Std          0.010592
    Active Max          0.002877
    Active Min         -0.009835
    Idle Std            0.017582
    """
    names_20 = ['TotLen Bwd Pkts', 'Flow IAT Mean', 'Flow IAT Std', 'Flow IAT Max', 'Flow IAT Min', 'Fwd IAT Std', 'Fwd IAT Max', 'Bwd IAT Mean', 'Bwd IAT Std',
                'Bwd IAT Max', 'Bwd PSH Flags', 'Fwd Header Len', 'Bwd Header Len', 'Bwd Pkts/s', 'Subflow Fwd Pkts', 'Subflow Bwd Pkts', 'Subflow Bwd Byts', 'Active Mean', 'Active Std', 'Active Max', 'Label']
    names_25 = ['Flow Duration', 'Tot Fwd Pkts', 'Tot Bwd Pkts', 'TotLen Bwd Pkts', 'Flow IAT Mean', 'Flow IAT Std', 'Flow IAT Max', 'Flow IAT Min', 'Fwd IAT Std', 'Fwd IAT Max', 'Bwd IAT Mean', 'Bwd IAT Std',
                'Bwd IAT Max', 'Bwd PSH Flags', 'Fwd Header Len', 'Bwd Header Len', 'Bwd Pkts/s', 'Subflow Fwd Pkts', 'Subflow Bwd Pkts', 'Subflow Bwd Byts', 'Active Mean', 'Active Std', 'Active Max', 'Active Min', 'Idle Std', 'Label']
    banaled_ddos = "C:\\Users\\leal\\Desktop\\Tmp\\balanced_ddos_test.csv"
    unbanaled_ddos = "C:\\Users\\leal\\Desktop\\Tmp\\unbalanced_ddos_test.csv"
    # save
    pd.read_csv(banaled_ddos)[names_20].to_csv(
        "C:\\Users\\leal\\Desktop\\Tmp\\balanced_ddos_test_corr_20.csv", index=False)
    pd.read_csv(banaled_ddos)[names_25].to_csv(
        "C:\\Users\\leal\\Desktop\\Tmp\\balanced_ddos_test_corr_25.csv", index=False)
    pd.read_csv(unbanaled_ddos)[names_20].to_csv(
        "C:\\Users\\leal\\Desktop\\Tmp\\unbalanced_ddos_test_corr_20.csv", index=False)
    pd.read_csv(unbanaled_ddos)[names_25].to_csv(
        "C:\\Users\\leal\\Desktop\\Tmp\\unbalanced_ddos_test_corr_25.csv", index=False)
