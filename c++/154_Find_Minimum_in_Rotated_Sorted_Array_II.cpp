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
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else
            { // when num[mid] and num[right] are same
                right--;
            }
        }
        return nums[left];
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
