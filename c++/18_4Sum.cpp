#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /**
     * Approach 1: Two Pointers
     * Time: O(k^n-1), or O(n^3) for 4Sum, we have k-2 loops, and twoSum is O(n) + sorted O(nlogn)
     *  Note that for k > 2, sorting the array does not change the overall time complexity.
     * Space: O(n). We need O(k) space for the recursion. 
     * k can be the same as n in the worst case for the generalized algorithm.
     */
    vector<vector<int>> twoSum(vector<int> &nums, int target, int start)
    {
        vector<vector<int>> res;
        int low = start, high = nums.size() - 1;
        while (low < high)
        {
            int sum = nums[low] + nums[high];
            if (sum < target || (low > start && nums[low] == nums[low - 1]))
            {
                ++low;
            }
            else if (sum > target || (high < nums.size() - 1 && nums[high] == nums[high + 1]))
            {
                --high;
            }
            else
            {
                res.push_back({nums[low++], nums[high--]});
            }
        }
        return res;
    }
    vector<vector<int>> kSum(vector<int> &nums, int target, int start, int k)
    {
        vector<vector<int>> res;
        if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
            return res;
        if (k == 2)
            return twoSum(nums, target, start);
        for (int i = start; i < nums.size(); ++i)
            if (i == start || nums[i - 1] != nums[i])
                for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1))
                {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(set), end(set));
                }
        return res;
    }

    vector<vector<int>> fourSum_1(vector<int> &nums, int target)
    {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }

    /**
     * Approach 2: Hash Set
     * Time: As approach 1
     * Space Complexity: O(n) for the hash set.
     *  The space needed for the recursion will not exceed O(n).
     */
    vector<vector<int>> twoSum_2(vector<int> &nums, int target, int start)
    {
        vector<vector<int>> res;
        unordered_set<int> s;
        for (auto i = start; i < nums.size(); ++i)
        {
            if (res.empty() || res.back()[1] != nums[i])
                if (s.count(target - nums[i]))
                    res.push_back({target - nums[i], nums[i]});
            s.insert(nums[i]);
        }
        return res;
    }
    vector<vector<int>> kSum_2(vector<int> &nums, int target, int start, int k)
    {
        vector<vector<int>> res;
        if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
            return res;
        if (k == 2)
            return twoSum_2(nums, target, start);
        for (int i = start; i < nums.size(); ++i)
            if (i == start || nums[i - 1] != nums[i])
                for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1))
                {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(set), end(set));
                }
        return res;
    }
    vector<vector<int>> fourSum_2(vector<int> &nums, int target)
    {
        sort(begin(nums), end(nums));
        return kSum_2(nums, target, 0, 4);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    Solution solution = Solution();
    sort(begin(nums), end(nums));
    vector<vector<int>> res = solution.twoSum(nums, -1, 0);
    for (int i = 0; i < res.size(); i++)
    {
        for (auto r : res[i])
        {
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}
