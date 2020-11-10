#include <iostream>
#include <vector>

using namespace std;
#define all(c) c.begin(), c.end()
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int numsLength = nums.size();
        if (0 == numsLength || target < nums[0])
        {
            return 0;
        }
        if (target > nums[numsLength - 1])
        {
            return numsLength;
        }
        for (int i = 0; i < numsLength; i++)
        {
            if (target == nums[i])
            {
                return i;
            }
            else if (nums[i] < target && target < nums[i + 1])
            {
                return i + 1;
            }
        }
        return -1;
    }
    int searchInsert_2(vector<int> &nums, int target)
    {
        int numsLength = nums.size(),
            low = 0,
            high = numsLength - 1,
            mid = 0;
        if (0 == numsLength)
        {
            return 0;
        }
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            if (target > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return target > nums[mid] ? mid + 1 : mid;
    }
    int searchInsert_1(vector<int> &nums, int target)
    {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }

    int binarySearch(vector<int> &nums, int L, int R, int &target)
    {
        int mid = 0;
        while (L <= R)
        {
            mid = L + (R - L) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            if (target > nums[mid])
            {
                L = mid + 1;
            }
            else
            {
                R = mid - 1;
            }
        }
        return target > nums[mid] ? mid + 1 : mid;
    }
    int binarySearch_1(vector<int> &nums, int L, int R, int &target)
    {
        int mid = L + (R - L) / 2;
        if (L <= R)
        {
            if (nums[mid] == target)
            {
                return mid;
            }
            if (target > nums[mid])
            {
                return binarySearch_1(nums, mid + 1, R, target);
            }
            return binarySearch_1(nums, L, mid - 1, target);
        }
        return target > nums[mid] ? mid + 1 : mid;
    }
    /**
     * using lower_bound
     */

    int searchInsert_3(vector<int> &nums, int target)
    {
        // auto it = lower_bound(all(nums), target);
        // return it == nums.end() ? nums.size() : it - nums.begin();
        //distance(begin(nums), lower_bound(begin(nums), end(nums), target));
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
int main(int argc, char const *argv[])
{
    Solution soultion;
    vector<int> nums = {1, 3, 5, 6};
    cout << soultion.searchInsert_2(nums, 7) << endl;
    return 0;
}
