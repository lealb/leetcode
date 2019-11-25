# 画图
import numpy as np
import matplotlib.pyplot as plt

# 在xgboost不同特征下的精确率、召回、F-Measure的变化趋势
# 数据集虚拟


def test1():
    """
    替换一下数据集即可
    """
    y1 = [99.10, 99.13, 99.5, 99.40, 99.30, 99.60, 99.70, 99.12, 99.55, 99.25]
    x1 = range(0, 10)
    plt.plot(x1, y1, label='Frist line', linewidth=1, color='r', marker='o',
             markerfacecolor='blue', markersize=12)
    plt.xlabel('Plot Number')
    plt.ylabel('Important var')
    plt.title('Interesting Graph\nCheck it out')
    plt.legend()
    # 设置数字标签
    for a, b in zip(x1, y1):
        plt.text(a, b, b, ha='center', va='bottom', fontsize=20)


def plot_line():
    plt.figure()
    plt.subplot(131)
    test1()
    plt.subplot(132)
    test1()
    plt.subplot(133)
    test1()
    plt.show()

# 柱状图


def plot_bar():

    plt.figure(figsize=(9, 6))
    n = 5
    X = np.arange(n)+1
    # X是1,2,3,4,5,6,7,8,柱的个数
    # numpy.random.uniform(low=0.0, high=1.0, size=None), normal
    # uniform均匀分布的随机数，normal是正态分布的随机数，0.5-1均匀分布的数，一共有n个
    Y1 = np.random.uniform(0.5, 1.0, n)
    Y2 = np.random.uniform(0.5, 1.0, n)
    Y3 = np.random.uniform(0.5, 1.0, n)
    Y4 = np.random.uniform(0.5, 1.0, n)
    plt.bar(X, Y1, width=0.2, label="Y1",
            facecolor='lightskyblue', edgecolor='white')
    # width:柱的宽度
    plt.bar(X+0.2, Y2, width=0.2, label="Y2",
            facecolor='yellowgreen', edgecolor='white')
    plt.bar(X+0.4, Y3, width=0.2, label="Y3",
            facecolor='green', edgecolor='white')
    plt.bar(X+0.6, Y4, width=0.2, label="Y4",
            facecolor='yellow', edgecolor='white')
    # 水平柱状图plt.barh，属性中宽度width变成了高度height
    # 打两组数据时用+
    # facecolor柱状图里填充的颜色
    # edgecolor是边框的颜色
    # 想把一组数据打到下边，在数据前使用负号
    # plt.bar(X, -Y2, width=width, facecolor='#ff9999', edgecolor='white')
    # 给图加text
    for x, y in zip(X, Y1):
        plt.text(x, y+0.05, '%.2f' % y, ha='center', va='bottom')

    for x, y in zip(X, Y2):
        plt.text(x+0.2, y+0.05, '%.2f' % y, ha='center', va='bottom')
    for x, y in zip(X, Y3):
        plt.text(x+0.4, y+0.05, '%.2f' % y, ha='center', va='bottom')
    for x, y in zip(X, Y4):
        plt.text(x+0.6, y, '%.2f' % y, ha='center', va='bottom')
    plt.ylim(0, +1.25)
    plt.legend()
    plt.show()


if __name__ == "__main__":
    plot_bar()
    # plot_line()
