#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
/**
 * Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
 * n == nums.length
 * 1 <= n <= 10^4
 * 0 <= nums[i] <= n
 * All the numbers of nums are unique.
 */
class Solution
{
public:
    /**
     * Approach #1 Sorting
     * Time complexity : O(nlgn)
     */
    int missingNumber_0(vector<int> &nums)
    {
        int numsLen = nums.size();
        sort(nums.begin(), nums.end());
        // Ensure that n is at the last index
        if (nums[numsLen - 1] != numsLen)
        {
            return numsLen;
        }
        // Ensure that 0 is at the first index
        else if (nums[0] != 0)
        {
            return 0;
        }

        // If we get here, then the missing number is on the range (0, n)
        for (int i = 1; i < numsLen; i++)
        {
            int expectedNum = nums[i - 1] + 1;
            if (nums[i] != expectedNum)
            {
                return expectedNum;
            }
        }
        return -1;
    }

    /**
     *Approach #2 HashSet 
     * Time: O(n)
     * Space: O(n)
     */
    int missingNumber_1(vector<int> &nums)
    {
        unordered_set<int> numSet;
        for (int num : nums)
            numSet.insert(num);

        int expectedNumCount = nums.size() + 1;
        for (int number = 0; number < expectedNumCount; number++)
        {
            if (numSet.find(number) == numSet.end())
            {
                return number;
            }
        }
        return -1;
    }

    /**
     * Approach #3 Bit Manipulation
     * Time: O(1)
     * Space:O(n)
     */
    int missingNumber_2(vector<int> &nums)
    {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            missing ^= i ^ nums[i];
        }
        return missing;
    }

    /**
     * Approach #4 Gauss' Formula
     */
    int missingNumber_3(vector<int> &nums)
    {
        // int numsLen = nums.size();
        // int expectedSum = numsLen * (numsLen + 1) / 2;
        // int actualSum = 0;
        // for (int num : nums)
        // {
        //     actualSum += num;
        // }
        // return expectedSum - actualSum;
        // In case of overflow
        int result = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            result += (i + 1) - nums[i];
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << solution.missingNumber_0(nums) << endl;
    system("pause");
    return 0;
}
