#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
/**
 * 2 <= n <= 3 * 10^4
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * All the integers in nums appear only once except for precisely one integer which appears 
 * two or more times.
 * Follow-ups:
 *  How can we prove that at least one duplicate number must exist in nums? 
 *  Can you solve the problem without modifying the array nums?
 *  Can you solve the problem using only constant, O(1) extra space?    
 *  Can you solve the problem with runtime complexity less than O(n2)?
 */
class Solution
{
public:
    /**
     * O(n^2) 
     * Time Limit Exceeded
     */
    int findDuplicate_0(vector<int> &nums)
    {
        int numsLen = nums.size();
        for (int i = 0; i < numsLen; ++i)
        {
            if (count(nums.begin(), nums.end(), nums[i]) >= 2)
            {
                return nums[i];
            }
        }
        return -1;
    }

    /**
     * Sort
     * O(nlogn)
     */
    int findDuplicate_1(vector<int> &nums)
    {
        int numsLen = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < numsLen; ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                return nums[i];
            }
        }
        return -1;
    }

    /**
     * Hashset
     * Time O(n)
     * Space O(n)
     */
    int findDuplicate_2(vector<int> &nums)
    {
        unordered_set<int> seen;
        for (int num : nums)
        {
            if (seen.find(num) != seen.end())
            {
                return num;
            }
            seen.insert(num);
        }
        return -1;
    }
    /**
     * Floyd's Tortoise and Hare (Cycle Detection)
     * 环检测算法
     */
    int findDuplicate_3(vector<int> &nums)
    {
        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];
        do
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }
    int findDuplicate_4(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i])] < 0)
            {
                return abs(nums[i]);
            }
            nums[abs(nums[i])] = -nums[abs(nums[i])];
        }
        return -1;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 1};
    cout << solution.findDuplicate_3(nums) << endl;
    system("pause");
    return 0;
}
