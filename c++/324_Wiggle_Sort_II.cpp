#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * @brief 
 * Can you do it in O(n) time and/or in-place with O(1) extra space?
 * 
 */
class Solution
{
public:
    /**
     * @brief Sort
     * nlog(n)
     * @param nums 
     */
    void wiggleSort(vector<int> &nums)
    {
        int size = nums.size();
        if (size <= 1)
            return;
        vector<int> tmp = nums;
        int k(size + 1 >> 1), i(0), j(size);
        sort(tmp.begin(), tmp.end());
        while (i < size)
        {
            nums[i++] = i & 1 ? tmp[--j] : tmp[--k];
        }
    }
    // O(n) time and O(1) space
    void wiggleSort_1(vector<int> &nums)
    {
#define METHOD(i) nums[(1 + 2 * i) % (n | 1)]
        int n = nums.size(), i = 0, j = 0, k = n - 1;
        auto midptr = nums.begin() + n / 2;
        //查找“第 nth 大”的元素，并将其移动到 nth 指向的位置
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        while (j <= k)
        {
            if (METHOD(j) > mid)
                swap(METHOD(i++), METHOD(j++));
            else if (METHOD(j) < mid)
                swap(METHOD(j), METHOD(k--));
            else
                ++j;
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 3, 2, 2, 3, 1};
    solution.wiggleSort(nums);
    for (auto &v : nums)
    {
        cout << v << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
