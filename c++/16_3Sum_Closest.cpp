#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /**
     * Approach 1: Two Pointers
     * Time Complexity: O(n^2) Sorting the array takes O(nlogn)
     * Space Complexity: from O(logn) to O(n),
     *  depending on the implementation of the sorting algorithm.
     */
    int threeSumClosest(vector<int> &nums, int target)
    {
        int diff = INT_MAX, numsSize = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < numsSize && diff != 0; ++i)
        {
            int left = i + 1, right = numsSize - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(target - sum) < abs(diff))
                    diff = target - sum;
                if (sum < target)
                    ++left;
                else
                    --right;
            }
        }
        return target - diff;
    }

    /**
     * Approach 2: Binary Search
     * Time Complexity: O(n2logn) 
     * Space Complexity: from O(logn) to O(n), 
     * depending on the implementation of the sorting algorithm.
     */
    int threeSumClosest_1(vector<int> &nums, int target)
    {
        int diff = INT_MAX, numsSize = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < numsSize && diff != 0; ++i)
        {
            for (int j = i + 1; j < numsSize - 1; ++j)
            {
                int complement = target - nums[i] - nums[j];
                auto it = upper_bound(begin(nums) + j + 1, end(nums), complement);
                int high = it - begin(nums), low = high - 1;
                if (high < numsSize && abs(complement - nums[high]) < abs(diff))
                    diff = complement - nums[high];
                if (low > j && abs(complement - nums[low]) < abs(diff))
                    diff = complement - nums[low];
            }
        }
        return target - diff;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1, 2, 1, -4};
    Solution solution = Solution();
    cout << solution.threeSumClosest_1(nums, 1) << endl;
    return 0;
}
