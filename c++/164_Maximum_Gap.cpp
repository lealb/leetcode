#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /**
     * @brief Sorted
     * O(NlogN)
     * @param nums 
     * @return int 
     */
    int maximumGap(vector<int> &nums)
    {
        int size = nums.size();
        if (2 > size)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int gap = 0;
        for (int i = size - 1; i > 0; --i)
        {
            gap = max(gap, nums[i] - nums[i - 1]);
        }
        return gap;
    }
    /**
     * @brief 尝试桶排序 O(n)
     * 
     * @param nums 
     * @return int 
     */
    int maximumGap_1(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        if (n < 2)
        {
            return 0;
        }
        long maxNum = *max_element(nums.begin(), nums.end());
        long minNum = *min_element(nums.begin(), nums.end());
        // all numbers is same
        if (maxNum == minNum)
        {
            return 0;
        }
        // spilt bucket
        vector<pair<int, int>> bucket(n, pair<int, int>(INT_MAX, INT_MIN));
        for (long i : nums)
        {
            int index = (i - minNum) * (n - 1) / (maxNum - minNum);
            if (i < bucket[index].first)
                bucket[index].first = i;
            if (i > bucket[index].second)
                bucket[index].second = i;
        }
        int pre = -1;
        for (int i = 0; i < n; i++)
        {
            if (bucket[i].first == INT_MAX)
                continue;
            if (pre > -1)
                ans = max(ans, bucket[i].first - bucket[pre].second);
            pre = i;
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 6, 9, 1};
    cout << solution.maximumGap(nums) << endl;
    system("pause");
    return 0;
}
