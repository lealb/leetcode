#include <iostream>
#include <vector>

using namespace std;
/**
 * 1 <= nums.length <= 2 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 */
class Solution
{
public:
    int sumArray(vector<int> &nums, int left, int right)
    {
        int res;
        for (int i = left; i <= right; i++)
        {
            res += nums[i];
        }
        return res;
    }
    int maxSubArray(vector<int> &nums)
    {
        int size = nums.size();
        if (1 == size)
        {
            return nums[0];
        }
        int res = 0;
        int left = 0, right = size - 1;
        while (left <= right)
        {
            int res = sumArray(nums, left, right);
            if (res - nums[left + 1] > res)
            {
                left++;
            }
            else if (res - nums[right - 1] > res)
            {
                right--;
            }
            else
            {
                return sumArray(nums, left, right);
            }
        }
        return -1;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << solution.maxSubArray(nums) << endl;
    system("pause");
    return 0;
}
