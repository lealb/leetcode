#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
/**
 * 0 <= i, j < nums.length
 * i != j
 * |nums[i] - nums[j]| == k
 */
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        set<pair<int, int>> s;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        if (k < 0)
        {
            return 0;
        }
        else if (k == 0)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (mp[nums[i]] > 1)
                {
                    s.insert(make_pair(nums[i], nums[i]));
                }
            }
            return s.size();
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (mp.count(nums[i] - k) && mp.count(nums[i] + k))
                {
                    s.insert(make_pair(nums[i] - k, nums[i]));
                    s.insert(make_pair(nums[i], nums[i] + k));
                }
                if (mp.count(nums[i] - k) && mp.count(nums[i] + k) == 0)
                {
                    s.insert(make_pair(nums[i] - k, nums[i]));
                }
                if (mp.count(nums[i] + k) && mp.count(nums[i] - k) == 0)
                {
                    s.insert(make_pair(nums[i], nums[i] + k));
                }
            }
            return s.size();
        }
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {3, 1, 4, 1, 5};
    cout << solution.findPairs(nums, 2) << endl;
    return 0;
}
