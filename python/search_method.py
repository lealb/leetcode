# 查找算法

# 1.顺序查找


def sequence_search(lists, value):
    """
    时间复杂度：O(n)
    """
    list_length = len(lists)
    for i in range(list_length):
        if lists[i] == value:
            return i
    return -1


def binary_search(lists, value):
    """
    二分查找
    元素必须是有序的，如果是无序的则要先进行排序操作
    时间复杂度：O(logn)
    """
    sorted_lists = sorted(lists)
    low, high = 0, len(lists)-1
    while low < high:
        mid = (low+high)//2
        if sorted_lists[mid] == value:
            return mid
        elif sorted_lists[mid] < value:
            low = mid + 1
        else:
            high = mid - 1
    return -1


def binary_search_by(lists, value, low, high):
    """
        递归二分查找
        选取查找点，改变查找的方向
        时间：O(logn)
    """
    mid = low+(high-low)//2
    while low < high:
        if lists[mid] == value:
            return mid
        elif lists[mid] < value:
            return binary_search_by(lists, value, low+1, high)
        else:
            return binary_search_by(lists, value, low, high-1)
    return -1


def insertion_search(lists, value, low, high):
    """
    插值查找：
    改变查找点，不需要从中间获取
    对于表长较大，而关键字分布又比较均匀的查找表来说，
    插值查找算法的平均性能比折半查找要好的多。反之，数组中如果分布非常不均匀，那么插值查找未必是很合适的选择
    mid=low+(value-a[low])/(a[high]-a[low])*(high-low)
    时间：O(log(logn))
    """
    while low < high:
        mid = low+(value-lists[low])//(lists[high]-lists[low])*(high-low)
        if lists[mid] == value:
            return mid
        elif lists[mid] < value:
            return binary_search_by(lists, value, low+1, high)
        else:
            return binary_search_by(lists, value, low, high-1)
    return -1


if __name__ == "__main__":
    lists = [-1, 2, -10, 3, 7, 1, 10, 15, 19, 45]
    # print(sequence_search(lists, 7))
    sorted_lists = sorted(lists)
    print(sorted_lists)
    # print(binary_search(lists, 7))
    # print(binary_search_by(sorted_lists, 12, 0, len(sorted_lists)-1))
    print(insertion_search(sorted_lists, 12, 0, len(sorted_lists)-1))
