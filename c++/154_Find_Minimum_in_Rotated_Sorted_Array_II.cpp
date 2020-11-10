#include <iostream>
#include <vector>
using namespace std;
/**
 * The array may contain duplicates.
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
 */
class Solution
{
public:
    int findMin_0(vector<int> &nums)
    {
        int numsLen = nums.size();
        for (size_t i = 1; i < numsLen; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                return nums[i];
            }
        }
        return nums[0];
    }

    int findMin_1(vector<int> &nums)
    {
        int numsLen = nums.size();
        int left = 0, right = numsLen - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[mid + 1])
            {
                return nums[mid + 1];
            }
            if (nums[mid - 1] >= nums[mid])
            {
                return nums[mid];
            }
            if (nums[mid] >= nums[0])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return nums[0];
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {2, 2, 2, 0, 1};
    cout << solution.findMin_1(nums) << endl;
    // system("pause");
    return 0;
}
