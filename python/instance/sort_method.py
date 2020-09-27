# 经典排序和查找算法
import random
"""
    分类：
        比较类排序-
            交换-
                冒泡排序
                快速排序
            插入-
                简单插入排序
                希尔排序
            选择-
                简单选择排序
                堆排序
            归并-
                二路归并算法
                多路归并算法
        非比较类排序-
            计数排序
            桶排序
            基数排序
"""


def get_lists_length(lists):
    """
        处理lists异常
    """
    if lists == []:
        return 0
    list_length = len(lists)
    if list_length == 1:
        return lists
    return list_length


def bubble_sort(lists):
    """
        冒泡排序
        在要排序的一组数中，对当前还未排好序的范围内的全部数，
        自上而下对相邻的两个数依次进行比较和调整，让较大的数往下沉，较小的往上冒。
        即：每当两相邻的数比较后发现它们的排序与排序要求相反时，就将它们互换
        时间：平均-O(n^2) 最好/坏-O(n)/O(n^2) 空间：O(1) 稳定
    """
    list_lenth = get_lists_length(lists)
    for i in range(list_lenth-1):
         # i表示比较轮数
         # 优化标志位，最好情况下
        flag = False
        for j in range(list_lenth-i-1):
            # j表示每轮比较的元素的范围，因为每比较一轮就会排序好一个元素的位置，
            # 所以在下一轮比较的时候就少比较了一个元素，所以要减去i
            if lists[j] > lists[j+1]:
                lists[j], lists[j+1] = lists[j+1], lists[j]
                flag = True
        if not flag:
            break
    return lists


def quick_sort(lists, left, right):
    """
        快速排序：
        1）选择一个基准元素,通常选择第一个元素或者最后一个元素,
        2）通过一趟排序讲待排序的记录分割成独立的两部分，其中一部分记录的元素值均比基准元素值小。
        另一部分记录的 元素值比基准值大。
        3）此时基准元素在其排好序后的正确位置(中间位置，分区)
        4）然后分别对这两部分记录用同样的方法继续进行排序，直到整个序列有序
        当待排序列基本有序，将退化为冒泡排序-通常以“三者取中法”来选取基准记录，
        即将排序区间的两个端点与中点三个记录关键码居中的调整为支点记录
        时间：平均-O(nlogn) 最好/坏-O(nlogn)/O(n^2) 空间：O(nlogn) 不稳定
    """
    if left < right:
        low, high = left, right
        key = lists[low]
        while low < high:
            while low < high and key <= lists[high]:
                # 从右边开始找，如果元素小于基准，则把这个元素放到左边
                high -= 1
            lists[low] = lists[high]

            while low < high and key > lists[low]:
                # 从左边开始找，如果元素大于基准，则把元素放到右边
                low += 1
            lists[high] = lists[low]

        # 循环退出，low==high，把基准元素放到这个位置
        lists[low] = key

        # 递归调用，重新排列左边的和右边的序列
        quick_sort(lists, left, low-1)
        quick_sort(lists, low+1, right)
    return lists


def quick_sort_py(lists):
    if len(lists) < 2:
        return lists
    else:
        key = lists[0]
        low = [i for i in lists[1:] if i <= key]
        high = [i for i in lists[1:] if i > key]
    return quick_sort_py(low)+[key]+quick_sort_py(high)


def insertion_sort(lists):
    """
        插入排序
        从第一个元素开始，该元素可以认为已经被排序
        取出下一个元素，在已经排序的元素序列中从后向前扫描
        如果该元素（已排序）大于新元素，将该元素移到下一位置
        重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
        将新元素插入到该位置后
        重复步骤2~5
        时间：平均-O(n^2) 最好/坏-O(n)/O(n^2) 空间：O(1) 不稳定
    """
    list_length = get_lists_length(lists)
    for i in range(1, list_length):
        temp = lists[i]
        j = i-1
        while j >= 0 and temp < lists[j]:
            # 将前面较大的数往后移动
            lists[j+1] = lists[j]
            j -= 1
        # 将lists[i] 放在指定位置
        lists[j+1] = temp
    return lists


def shell_sort(lists):
    """
        希尔排序
        1.将有n个元素的数组分成n/2份，第一个数据与第n/2+1个数据属于同一份[选择一个增量序列t1,t2...tk,其中ti>tj,tk=1]
        2.内部使用简单插入排序的方法，将同一份的数据排序[按增量序列个数为k，对序列进行k趟排序]
        3.更改步长，继续分组(优化：step=3*step+1)[每趟排序，根据对应的增量t1,将待排序列分割成若干长度为m的子序列，仅当增量因子为1时，整个序列作为整个表处理]
        时间：平均-O(n^1.3) 最好/坏-O(n)/O(n^2) 空间：O(1) 不稳定
    """
    list_length = get_lists_length(lists)
    step = 0
    while step <= list_length:
        step = 3*step+1
    while step >= 1:
        for i in range(step, list_length):
            j = i-step
            temp = lists[i]
            while j >= 0 and lists[j] > temp:
                lists[j+step] = lists[j]
                j -= step
            lists[j+step] = temp
        step = (step-1)//3
    return lists


def selection_sort(lists):
    """
        选择排序
        1.初始化最小的数据
        2.遍历查找到最小的数据的索引
        3.与初始化的数据交换
        每次选择最小的数据进行暴力排序
        时间：平均-O(n^2) 最好/坏-O(n^2)/O(n^2) 空间：O(1) 不稳定
    """
    list_length = get_lists_length(lists)
    for i in range(list_length):
        # 初始化最小数据的索引
        min = i
        for j in range(i+1, list_length):
            # 查找最小的数
            if lists[j] < lists[min]:
                min = j
        # 交换最小的数
        lists[i], lists[min] = lists[min], lists[i]
    return lists


# @staticmethod
def heap_sort(lists):
    """
        堆排序
        a.将无需序列构建成一个堆，根据升序降序需求选择大顶堆或小顶堆;
        b.将堆顶元素与末尾元素交换，将最大元素"沉"到数组末端;
        c.重新调整结构，使其满足堆定义，然后继续交换堆顶元素与当前末尾元素，反复执行调整+交换步骤，直到整个序列有序
        时间：平均-O(nlogn) 最好/坏-O(nlogn)/O(nlogn) 空间：O(1) 不稳定
    """
    list_length = get_lists_length(lists)
    # 调整大顶堆（仅是调整过程，建立在大顶堆已构建的基础上）

    def adjuct_heap(listsay, index, length):
        # 先取出当前元素i
        temp = listsay[index]
        # 从i结点的左子结点开始，也就是2i + 1处开始
        k = index * 2 + 1
        while k < length:
            # 如果左子结点小于右子结点，k指向右子结点
            if k + 1 < length and listsay[k] < listsay[k + 1]:
                k += 1
            # 如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
            if listsay[k] > temp:
                listsay[index] = listsay[k]
                index = k
            else:
                break
            k = 2 * k + 1
        # 将temp值放到最终的位置
        listsay[index] = temp

    # 构建最大堆
    for i in range(list_length // 2 - 1, -1, -1):
        # 从第一个非叶子节点从下至上，从右至左调整结构
        adjuct_heap(lists, i, list_length)

    for j in range(list_length - 1, -1, -1):
        lists[j], lists[0] = lists[0], lists[j]
        adjuct_heap(lists, 0, j)

    return lists


def merge_sort(lists):
    """
        二路归并排序-分治
        （1）分解,将n个元素分成各含n/2个元素的子序列
        （2）求解,用归并排序对两个子序列递归地排序
        （3）合并,合并两个已经排好序的子序列以及得到排序结果
        时间：平均-O(nlogn) 最好/坏-O(nlogn)/O(nlogn) 空间：O(n) 稳定
    """
    def merge(left, right):
        i, j = 0, 0
        result = []
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                result.append(left[i])
                i += 1
            else:
                result.append(right[j])
                j += 1
        result += left[i:]
        result += right[j:]
        return result

    # 归并排序
    list_length = len(lists)
    if list_length < 2:
        return lists
    num = list_length // 2
    left = merge_sort(lists[:num])
    right = merge_sort(lists[num:])

    return merge(left, right)

# 多路归并算法

# 非交换排序-


def count_sort(lists):
    """
        1.找出lists中最大值和最小值，初始化数组全为0
        2.遍历lists,在相应的数字下标填入count数字
        3.遍历数组不为0的值即为排序的元素，以空间换时间，当待排序列比较集中可以选该方法
        >0
    """
    _max = max(lists)
    # for i in range(list_length):
    #     if min>lists[i]:
    #         min=lists[i]
    #     if max<lists[i]:
    #         max=lists[i]
    zero_lists = [0 for i in range(_max + 1)]  # 设置计数序列并初始化为0，
    for i in lists:
        zero_lists[i] += 1
    count_lists = []
    for i, v in enumerate(zero_lists):
        # while v > 0:
        #     count_lists.append(i)
        #     v -= 1
        if v != 0:
            count_lists += [i]*v
    return count_lists


def bucket_sort(lists):
    _min, _max = min(lists), max(lists)
    buckets = [0] * (_max-_min + 1)  # 初始化桶元素为0
    list_length = get_lists_length(lists)
    for i in range(list_length):
        buckets[lists[i] - _min] += 1  # 遍历数组a，在桶的相应位置累加值
    sorted_lists = []
    for i in range(len(buckets)):
        if buckets[i] != 0:
            sorted_lists += [i + _min] * buckets[i]
    return sorted_lists


def radix_sort(lists, d=3): 
     # 默认三位数，如果是四位数，则d=4，以此类推
    for i in range(d):  # d轮排序
        s = [[] for k in range(10)]  # 因每一位数字都是0~9，建10个桶
        for j in lists:
            s[int(j / (10 ** i)) % 10].append(j)
        sorted_lists = [a for b in s for a in b]
    return sorted_lists


def monkey_sort(lists):
    """
        猴子搞笑排序
    """
    def judge_monkey():
        for i in range(len(lists)):
            if i+1 == len(lists):
                return False
            if lists[i] > lists[i+1]:
                return True
        return False

    count = 0
    while judge_monkey():
        random.shuffle(lists)
        count += 1
    return lists, count


def get_random_lists(n, min=-10, max=100):
    return [random.randint(min, max) for i in range(n)]


def is_sorted(lists):
    list_length = len(lists)
    for i in range(1, list_length):
        # 有序，针对升序排列
        if lists[i] < lists[i-1]:
            return False
    return True

# import timeit
# def test_sorted():
#     t1 = timeit.Timer('testSort("某种排序算法函数", alist)', 'from __main__ import testSort, 某种排序算法函数, alist')

#     print('某种排序算法：%s s' %t1.timeit(number=1))

# # func表示要检测的算法函数，alist为传入的数列
# def testSort(func, alist):
#   alist =  func(alist)
#   assert is_sorted(alist), "排序算法错误\n"


if __name__ == "__main__":
    print("hello")
    lists = [2, 10, 4, 3, 7, 3, 37]
    print(get_random_lists(10))
    # print(bubble_sort(lists))
    # print(quick_sort(lists, 0, get_lists_length(lists)-1))
    # print(quick_sort_py(lists))
    # print(shell_sort(lists))
    # print(selection_sort(lists))
    # print(heap_sort(lists))
    # print(merge_sort(lists))
    # print(radix_sort(lists, 2))
    print(monkey_sort(lists))
