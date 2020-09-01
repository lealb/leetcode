#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 1.构造函数
vector():创建一个空vector
vector(int nSize):创建一个vector,元素个数为nSize
vector(int nSize,const t& t):创建一个vector，元素个数为nSize,且值均为t
vector(const vector&):复制构造函数
vector(begin,end):复制[begin,end)区间内另一个数组的元素到vector中
2.增加函数
void push_back(const T& x):向量尾部增加一个元素X
iterator insert(iterator it,const T& x):向量中迭代器指向元素前增加一个元素x
iterator insert(iterator it,int n,const T& x):向量中迭代器指向元素前增加n个相同的元素x
iterator insert(iterator it,const_iterator first,const_iterator last):向量中迭代器指向元素前插入另一个相同类型向量的[first,last)间的数据
3.删除函数
iterator erase(iterator it):删除向量中迭代器指向元素
iterator erase(iterator first,iterator last):删除向量中[first,last)中元素
void pop_back():删除向量中最后一个元素
void clear():清空向量中所有元素
4.遍历函数
reference at(int pos):返回pos位置元素的引用
reference front():返回首元素的引用
reference back():返回尾元素的引用
iterator begin():返回向量头指针，指向第一个元素
iterator end():返回向量尾指针，指向向量最后一个元素的下一个位置
reverse_iterator rbegin():反向迭代器，指向最后一个元素
reverse_iterator rend():反向迭代器，指向第一个元素之前的位置
5.判断函数
bool empty() const:判断向量是否为空，若为空，则向量中无元素
6.大小函数
int size() const:返回向量中元素的个数
int capacity() const:返回当前向量所能容纳的最大元素值
int max_size() const:返回最大可允许的vector元素数量值
7.其他函数
void swap(vector&):交换两个同类型向量的数据
void assign(int n,const T& x):设置向量中第n个元素的值为x
void assign(const_iterator first,const_iterator last):向量中[first,last)中元素设置成当前向量元素
方法：

 */
vector<int> init()
{
    vector<int> nums = {1, 2, 3};
    return {};
}
// mult array
vector<vector<int>> init_2()
{
    int N = 5, M = 6;
    vector<vector<int>> obj(N, vector<int>(M)); //定义二维动态数组5行6列

    for (int i = 0; i < obj.size(); i++) //输出二维动态数组
    {
        for (int j = 0; j < obj[i].size(); j++)
        {
            cout << obj[i][j] << " ";
        }
        cout << "\n";
    }
    return obj;
}
void printVector(vector<int> &nums)
{
    //1. 直接遍历
    cout << "1.Array\n";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    //2. 迭代器
    cout << "2.Iterator\n";
    vector<int>::iterator it;
    for (it = nums.begin(); it != nums.end(); it++)
    {
        cout << *it << " ";
    }
    // auto
    cout << "\n3.Auto\n";
    for (auto &&i : nums)
    {
        cout << i << " ";
    }
}
// sort、reverse
bool compare(int a, int b)
{
    return a > b; //升序排列，如果改为return a>b，则为降序
}
void testSort()
{

    // int a[10] = {2, 4, 1, 23, 5, 76, 0, 43, 24, 65}, i;
    vector<int> a = {2, 4, 1, 23, 5, 76, 0, 43, 24, 65};
    cout << "Before:" << endl;
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    sort(a.begin(), a.end(), compare);
    cout << "\nAfter:" << endl;
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
}
int main(int argc, char const *argv[])
{
    vector<int> a = {2, 4, 1, 23, 5, 76, 0, 43, 24, 65};
    printVector(a);
    init_2();
    return 0;
}
