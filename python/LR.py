
# LR Test
from sklearn import datasets
from sklearn.model_selection import train_test_split


def get_dataset():
    iris = datasets.load_iris()
    X, y = iris.data, iris.target
    return X, y


def plot(X, y):
    from matplotlib import pyplot as plt
    plt.scatter(X[:, 0], y[y == 0], color='red', marker='o', label='setosa')
    plt.xlabel('petal length')
    plt.ylabel('sepal length')
    plt.legend(loc='upper left')
    plt.show()


if __name__ == "__main__":
    X, y = get_dataset()
    # plot(X,y)
    print(y)
