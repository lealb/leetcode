#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    /**
     * 还是需要找寻左右指针点
     */
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int numsLen = nums.size(),
            low = 0,
            high = numsLen - 1,
            mid;
        if (0 == numsLen)
        {
            return {-1, -1};
        }
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else if (nums[high] > target)
            {
                high = mid - 1;
            }
            else
            {
                if (high + 1 == numsLen)
                {
                    return {low, high};
                }
                else
                {
                    return {low, high + 1};
                }
            }
        }
        return {-1, -1};
    }
    /**
     * Time complexity : O(n)
     * This brute-force approach examines each of the n elements of nums exactly twice, 
     * so the overall runtime is linear.
     * Space complexity : O(1)
     * The linear scan method allowcates a fixed-size array and a few integers,
     *  so it has a constant-size memory footprint.
     */
    vector<int> searchRange_1(vector<int> &nums, int target)
    {
        vector<int> targetRange = {-1, -1};
        // find the index of the leftmost appearance of `target`.
        int numsLength = nums.size();
        for (int i = 0; i < numsLength; i++)
        {
            if (nums[i] == target)
            {
                targetRange[0] = i;
                break;
            }
        }
        // if the last lowop did not find any index, then there is no valid range
        // and we return [-1, -1].
        if (targetRange[0] == -1)
        {
            return targetRange;
        }
        // find the index of the rightmost appearance of `target` (by reverse
        // iteration). it is guaranteed to appear.
        for (int j = numsLength - 1; j >= 0; j--)
        {
            if (nums[j] == target)
            {
                targetRange[1] = j;
                break;
            }
        }
        return targetRange;
    }
    /**
     * Time complexity : O(lowgN)
     * Space complexity : O(1)
     */
    vector<int> searchRange_2(vector<int> &nums, int target)
    {
        vector<int> targetRange = {-1, -1};
        int leftIdx = extremeInsertionIndex(nums, target, true);
        // assert that `leftIdx` is within the array bounds and that `target`
        // is actually in `nums`.
        if (leftIdx == nums.size() || nums[leftIdx] != target)
        {
            return targetRange;
        }
        targetRange[0] = leftIdx;
        targetRange[1] = extremeInsertionIndex(nums, target, false) - 1;
        return targetRange;
    }
    int extremeInsertionIndex(vector<int> &nums, int target, bool left)
    {
        int low = 0;
        int high = nums.size();
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target || (left && target == nums[mid]))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
int main(int argc, char const *argv[])
{
    Solution soultion;
    // 5, 7, 7, 8, 8,
    // 1,3 1
    vector<int> nums = {8,8};
    vector<int> res = soultion.searchRange(nums, 8);
    for (auto r : res)
    {
        cout << r << " ";
    }

    return 0;
}
