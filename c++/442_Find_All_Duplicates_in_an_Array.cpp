#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 1 ≤ a[i] ≤ n (n = size of array),
 */
class Solution
{
public:
    /**
     * Sorted
     * Time: O(nlogn)
     */
    vector<int> findDuplicates(vector<int> &nums)
    {
        int numsLen = nums.size();
        vector<int> res;
        if (1 == numsLen)
        {
            return res;
        }
        // sort
        sort(nums.begin(), nums.end());
        for (int i = 1; i < numsLen; ++i)
        {
            if (nums[i - 1] == nums[i])
            {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
    /**
     * T: O(n)
     * S:O(n)
     * thoughts: create a table to store the number of occurance
     */
    vector<int> findDuplicates_0(vector<int> &nums)
    {
        vector<int> occurance(nums.size(), 0);
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            occurance[nums[i] - 1]++;
            if (occurance[nums[i] - 1] > 1)
            {
                ret.push_back(nums[i]);
            }
        }
        return ret;
    }
    vector<int> findDuplicates_1(vector<int> &nums)
    {
        vector<int> ans;
        int numsLen = nums.size();
        for (int i = 0; i < numsLen; i++)
        {
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            if (nums[abs(nums[i]) - 1] > 0)
            {
                ans.push_back(abs(nums[i]));
            }
        }
        return ans;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> res = solution.findDuplicates_1(nums);
    for (auto n : res)
    {
        cout << n << " ";
    }
    cout << endl;
    // system("pause");
    return 0;
}
