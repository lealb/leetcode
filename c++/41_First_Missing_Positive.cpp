#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
/**
 * 0 <= nums.length <= 300
 * -2^31 <= nums[i] <= 2^31 - 1
 * Time: O(n)
 * Space: O(1)
 */
class Solution
{

public:
    // ios_base::sync_with_stdio(0);
    // void swap(vector<int> &nums, int i, int j)
    // {
    //     int temp = nums[i];
    //     nums[i] = nums[j];
    //     nums[j] = temp;
    // }
    /**
     * Time: O(n)
     * Space:O(n)
     */
    int firstMissingPositive(vector<int> &nums)
    {
        int numsLen = nums.size();
        if (0 == numsLen)
        {
            return 1;
        }
        int dp[numsLen + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < numsLen; i++)
        {
            if (nums[i] >= 1 && nums[i] <= numsLen)
            {
                dp[nums[i]]++;
            }
        }
        for (int i = 1; i <= numsLen; i++)
        {
            if (dp[i] == 0)
                return i;
        }
        return numsLen + 1;
    }
    int firstMissingPositive_1(vector<int> &nums)
    {
        size_t i = 0;
        int numsLen = nums.size();
        if (0 == numsLen)
        {
            return 1;
        }
        // 交换排序
        while (i < numsLen)
        {
            /**
             * 1.nums[i] <= 0 负数不影响结果
             * 2.nums[i] > numsLen 值大于长度
             */
            if (nums[i] <= 0 || nums[i] > numsLen || nums[i] - 1 == i || nums[nums[i] - 1] == nums[i])
            {
                i++;
            }
            else
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < numsLen; i++)
        {
            if (i != nums[i] - 1)
            {
                return i + 1;
            }
        }
        return numsLen + 1;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {3, 4, -1, 1};
    Solution solution;
    cout << solution.firstMissingPositive_1(nums) << endl;
    system("pause");
    return 0;
}
