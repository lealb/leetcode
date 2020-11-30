#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return false;
        int end = n - 1;
        int start = 0;

        while (start <= end)
        {
            int mid = start + (end - start >> 1);

            if (nums[mid] == target)
            {
                return true;
            }
            // nums[start] != element
            if (nums[start] == nums[mid])
            {
                start++;
                continue;
            }
            // which array does pivot belong to.
            bool pivotArray = nums[start] <= nums[mid];

            // which array does target belong to.
            bool targetArray = nums[start] <= target;
            if (pivotArray ^ targetArray)
            { // If pivot and target exist in different sorted arrays, recall that xor is true only when both the operands are distinct
                if (pivotArray)
                {
                    start = mid + 1; // pivot in the first, target in the second
                }
                else
                {
                    end = mid - 1; // target in the first, pivot in the second
                }
            }
            else
            { // If pivot and target exist in same sorted array
                if (nums[mid] < target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
    bool search_1(vector<int> &nums, int target)
    {
        if (nums.empty())
            return false;
        int left = 0, right = nums.size() - 1, mid = 0;
        while (left + 1 < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            // deal same nums
            else if (nums[left] == nums[mid] && nums[mid] == nums[right])
            {
                left++, right--;
            }
            else if (nums[mid] > nums[right])
            {
                if (nums[left] <= target && target <= nums[mid])
                    right = mid;
                else
                    left = mid;
            }
            else
            {
                if (nums[mid] <= target && target <= nums[right])
                    left = mid;
                else
                    right = mid;
            }
        }
        return nums[left] == target || nums[right] == target;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 1};
    int target = 1;
    cout << solution.search_1(nums, target) << endl;
    system("pause");
    return 0;
}
