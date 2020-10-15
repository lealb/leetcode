#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
        {
            return -1;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (target == nums[i])
            {
                return i;
            }
        }
        return -1;
    }
    /**
     * Binary Search O(n)
     */
    int search_1(vector<int> &nums, int target)
    {
        int n = nums.size();
        int index = -1, left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid > 0 && nums[mid] < nums[mid - 1])
            {
                index = mid - 1;
                break;
            }
            if (mid < n - 1 && nums[mid] > nums[mid + 1])
            {
                index = mid;
                break;
            }
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
        left = 0, right = index;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        left = index + 1, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
    int searchTarget(vector<int> &nums, int low, int high, int target)
    {
        int mid;
        while (low <= high)
        {
            // 防止溢出
            mid = low + (high - low) / 2;
            if (nums[mid] > target)
                high = mid - 1;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                return mid;
        }
        return -1;
    }
    int search_2(vector<int> &nums, int target)
    {
        int numsLength = nums.size();
        int mid, low = 0, high = numsLength - 1;
        // 查找打乱的分界点
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] < nums[high])
                high = mid;
            else if (nums[mid] > nums[high])
                low = mid + 1;
        }
        //left
        int ans = searchTarget(nums, 0, low - 1, target);
        return (ans != -1) ? ans : searchTarget(nums, low, numsLength - 1, target);
    }
    int search_3(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return -1;

        int len = nums.size(),
            low = 0,
            high = len - 1,
            mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            // cout << low << " " << mid << " " << high << endl;

            if (target == nums[mid])
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                if (nums[low] <= nums[mid] && target < nums[low])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else if (nums[mid] < target)
            {
                if (nums[low] > nums[mid] && target >= nums[low])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << solution.search_2(nums, 5) << endl;
    return 0;
}
