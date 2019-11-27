# -*- encoding: utf-8 -*-
'''
@File    :   dt.py
@Time    :   2019/11/27 14:51:42
@Author  :   leal 
@Version :   1.0
@Contact :   lijiadongyue@gmail.com
@License :   (C)Copyright 2018-2019, Liugroup-NLPR-CASIA
@Desc    :   决策树算法选取特征,主要针对离散类别型数据
'''

# here put the import lib
import math
import numpy as np
import collections


def get_entropy(dataset):
    """
    根据给定的数据集计算经验熵
    """
    nums_dataset = len(dataset)
    labels = {}
    for data in dataset:
        label = data[-1]
        if label not in labels.keys():
            labels[label] = 0
        labels[label] += 1
    # print(labels)
    # 计算经验熵
    entropy = 0.0
    for key in labels:
        # 概率
        prob = labels[key] / nums_dataset
        entropy -= prob * math.log(prob, 2)
    return entropy


def split_dataset(dataset, axis, value):
    ret_dataset = []
    for feature in dataset:
        if feature[axis] == value:
            reduced_feature = feature[:axis]
            reduced_feature.extend(feature[axis + 1:])
            ret_dataset.append(reduced_feature)
    return ret_dataset


def get_info_gain(dataset):
    """
    计算信息增益
    """
    num_dataset = len(dataset)
    num_features = len(dataset[0]) - 1
    entropy = get_entropy(dataset)
    info_gain = {}
    for fe in range(num_features):
        features = [feature[fe] for feature in dataset]  # 取出特征列
        unique_feature = set(features)
        condaition_entropy = 0.0
        for value in unique_feature:
            sub_dataset = split_dataset(dataset, fe, value)
            prob = len(sub_dataset) / float(num_dataset)
            condaition_entropy += prob * get_entropy(sub_dataset)
        info_gain[fe] = entropy - condaition_entropy
        # print(info_gain)
    return info_gain


def get_major_class(class_list):
    """
        统计类别的数量，并返回数量最多的类别
    """
    class_count = {}
    for vote in class_list:
        if vote not in class_count.keys():
            class_count[vote] = 0
        class_count[vote] += 1
    return sorted(class_count.items(), key=lambda x: x[1], reverse=True)[0][0]


def get_best_feature(dataset):
    """
    获得最好的特征，即信息增益最大值，以ID3为例
    """
    info_gain = get_info_gain(dataset)
    return sorted(info_gain.items(), key=lambda v: v[1], reverse=True)[0][0]


def get_decision_tree(dataset, labels):
    """
        决策树生成
    """
    class_list = [example[-1] for example in dataset]
    if class_list.count(class_list[0]) == len(class_list):
        return class_list[0]  # 终止条件1：样本都是同一类型
    if len(dataset[0]) == 1:
        return get_major_class(class_list)  # 属性用完或分不开情形，使用后验分布

    best_feature = get_best_feature(dataset)
    print(labels, best_feature)
    best_fea_label = labels[best_feature]
    d_tree = {best_fea_label: {}}
    # 删除已经用于分裂的特征
    del (labels[best_feature])
    # 取出特征值
    feature_values = [fe[best_feature] for fe in dataset]
    unique_feature = set(feature_values)
    for v in unique_feature:
        sub_labels = labels[:]
        sub_dataset = split_dataset(dataset, best_feature, v)
        d_tree[best_fea_label][v] = get_decision_tree(sub_dataset, sub_labels)
    return d_tree


def get_dataset():
    """
    获得数据集
    """
    data = [
        [0, 0, 0, 0, 'no'],  # 数据集
        [0, 0, 0, 1, 'no'],
        [0, 1, 0, 1, 'yes'],
        [0, 1, 1, 0, 'yes'],
        [0, 0, 0, 0, 'no'],
        [1, 0, 0, 0, 'no'],
        [1, 0, 0, 1, 'no'],
        [1, 1, 1, 1, 'yes'],
        [1, 0, 1, 2, 'yes'],
        [1, 0, 1, 2, 'yes'],
        [2, 0, 1, 2, 'yes'],
        [2, 0, 1, 1, 'yes'],
        [2, 1, 0, 1, 'yes'],
        [2, 1, 0, 2, 'yes'],
        [2, 0, 0, 0, 'no']
    ]
    labels = ['年龄', '有工作', '有自己的房子', '信贷情况']  # 分类属性
    return data, labels


if __name__ == "__main__":
    credit_dataset, credit_labels = get_dataset()
    print(get_decision_tree(credit_dataset, credit_labels))
    """
    {'有自己的房子': {0: {'有工作': {0: 'no', 1: 'yes'}}, 1: 'yes'}}
    """
