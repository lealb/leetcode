#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 1 ≤ a[i] ≤ n (n = size of array)
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * some elements appear twice and others appear once.
 * without extra space and in O(n) runtime
 */
class Solution
{
public:
    /**
     * wrong answer
     * 
     */
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int numsLen = nums.size();
        vector<int> ans;
        for (int i = 1; i < numsLen; ++i)
        {
            // swap
            if (nums[i - 1] != i)
            {
                if (nums[nums[i - 1] - 1] != nums[i - 1])
                {
                    swap(nums[i - 1], nums[nums[i - 1] - 1]);
                    // nums[i] = nums[i] ^ nums[nums[i] - 1];
                    // nums[nums[i] - 1] = nums[i] ^ nums[nums[i] - 1];
                    // nums[i] = nums[i] ^ nums[nums[i] - 1];
                }
                else
                {
                    ans.push_back(i - 1);
                }
            }
        }
        return ans;
    }
    vector<int> findDisappearedNumbers_0(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        { // loop 1
            while (nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // now it's [1,2,3,4,3,2,7,8]
        vector<int> res;
        for (int i = 1; i <= n; ++i)
        {
            if (i != nums[i - 1])
            {
                res.push_back(i);
            }
        }
        return res;
    }
    /**
     *  abs
     */
    vector<int> findDisappearedNumbers_1(vector<int> &nums)
    {
        int len = nums.size();
        int i = 0;
        while (i < len)
        {
            if (nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
            else
            {
                ++i;
            }
        }

        vector<int> res;
        for (int i = 0; i < len; i++)
        {
            if (i + 1 != nums[i])
            {
                res.push_back(i + 1);
            }
        }
        return res;
    }
    /**
     *  dp
     * S:O(n)
     */
    vector<int> findDisappearedNumbers_2(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, 0), ans;

        for (int i = 0; i < n; i++)
        {
            dp[nums[i]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (dp[i] == 0)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
int main()
{
    Solution solution;
    //4, 3, 2, 7, 8, 2, 3
    vector<int> nums = {1, 1, 2};
    vector<int> res = solution.findDisappearedNumbers(nums);
    for (auto r : res)
    {
        cout << r << " ";
    }
    cout << endl;
    // system("pause");
    return 0;
}
