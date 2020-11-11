#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string.h>
using namespace std;
class Solution
{
public:
    /**
     * Time Limit Exceeded
     * Time: O(n^2)
     */
    bool containsDuplicate(vector<int> &nums)
    {
        int numsLen = nums.size();
        if (1 == numsLen)
        {
            return false;
        }

        for (size_t i = 0; i < numsLen; i++)
        {
            if (count(nums.begin(), nums.end(), nums[i]))
            {
                return true;
            }
        }
        return false;
    }

    /**
     * Approach #2 (Sorting) 
     * Time complexity : O(nlogn)
     * Space complexity : O(1)
     */
    bool containsDuplicate_1(vector<int> &nums)
    {
        int numsLen = nums.size();
        if (1 == numsLen)
        {
            return false;
        }
        sort(nums.begin(), nums.end());
        // for (int i = 0; i < nums.length - 1; ++i)
        // i vs i+1
        for (size_t i = 1; i < numsLen; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                return true;
            }
        }
        return false;
    }

    /**
     * Approach 3 HashSet
     * Time:O(n)
     * Space:O(n)
     */
    bool containsDuplicate_2(vector<int> &nums)
    {
        int numsLen = nums.size();
        if (1 == numsLen)
        {
            return false;
        }
        unordered_set<int> numsSet(numsLen);
        for (int x : nums)
        {
            if (numsSet.find(x) != numsSet.end())
            {
                return true;
            }
            numsSet.insert(x);
        }
        return false;
    }

    bool containsDuplicate_3(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if (nums.size() <= 1)
            return 0;

        int minn = *min_element(nums.begin(), nums.end());
        int maxx = *max_element(nums.begin(), nums.end());

        int arr[maxx - minn + 1];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < nums.size(); i++)
        {

            arr[nums[i] - minn]++;

            if (arr[nums[i] - minn] > 1)
            {
                return 1;
            }
        }
        return 0;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 3};
    cout << solution.containsDuplicate_2(nums) << endl;
    system("pause");
    return 0;
}
