#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    /**
     * Approach #1 (Space Sub-Optimal)
     * Time: O(n)
     * Space: O(1)
     */
    void moveZeroes_0(vector<int> &nums)
    {
        int n = nums.size();
        // Make all the non-zero elements retain their original order.
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                ans.push_back(nums[i]);
            }
        }
        // Count the zeroes
        int numZeroes = n - ans.size();
        // Move all zeroes to the end
        while (numZeroes--)
        {
            ans.push_back(0);
        }
        // Combine the result
        for (int i = 0; i < n; i++)
        {
            nums[i] = ans[i];
        }
    }
    void moveZeroes(vector<int> &nums)
    {
        int numsLen = nums.size();
        // copy zero
        vector<int> ans;
        for (int i = 0; i < numsLen; i++)
        {
            if (0 != nums[i])
            {
                ans.push_back(nums[i]);
            }
        }
        int ansLen = ans.size();
        // add non-zero
        for (int i = 0; i < ansLen; i++)
        {
            nums[i] = ans[i];
        }
        // add zero
        for (int i = ansLen; i < numsLen; i++)
        {
            nums[i] = 0;
        }
    }

    /**
     * Approach #2 (Space Optimal, Operation Sub-Optimal)
     */
    void moveZeroes_1(vector<int> &nums)
    {
        int lastNonZeroFoundAt = 0;
        // If the current element is not 0, then we need to
        // append it just in front of last non 0 element we found.
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }
        // After we have finished processing new elements,
        // all the non-zero elements are already at beginning of array.
        // We just need to fill remaining array with 0's.
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }

    /**
     * Approach #3 (Optimal)
     * Space Complexity : O(1). Only constant space is used.
     * Time Complexity: O(n). 
     */
    void moveZeroes(vector<int> &nums)
    {
        int numsLen = nums.size();
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < numsLen; cur++)
        {
            if (nums[cur] != 0)
            {
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    // {0, 1, 0, 3, 12}
    vector<int> nums = {0, 1};
    solution.moveZeroes(nums);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
