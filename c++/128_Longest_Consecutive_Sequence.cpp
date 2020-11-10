#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
/**
 * 0 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 */
class Solution
{
public:
    /**
     * Approach 1: Brute Force
     * Time Limit Exceeded
     * Time complexity : O(n^3)
     *  The outer loop runs exactly nn times, 
     * and because currentNum increments by 1 during each iteration of the while loop, 
     * it runs in O(n) time. Then, on each iteration of the while loop, 
     * an O(n) lookup in the array is performed. Therefore, 
     * this brute force algorithm is really three nested O(n) loops, 
     * which compound multiplicatively to a cubic runtime.
     * Space complexity : O(1).
     * The brute force algorithm only allocates a handful of integers, 
     * so it uses constant additional space.
     */
    int longestConsecutive_0(vector<int> &nums)
    {
        int numsLen = nums.size();
        if (0 == numsLen)
        {
            return 0;
        }
        int longestStreak = 0;
        for (int num : nums)
        {
            int currentNum = num;
            int currentStreak = 1;

            while (find(nums.begin(), nums.end(), currentNum + 1) != nums.end())
            {
                currentNum++;
                currentStreak++;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
        return longestStreak;
    }

    /**
     * Approach 2: Sorting
     * ime complexity : O(nlgn).
     * The main for loop does constant work nn times, 
     * so the algorithm's time complexity is dominated by the invocation of sort, 
     * which will run in O(nlgn) time for any sensible implementation.
     * Space complexity : O(1) (or O(n)).
     * For the implementations provided here, the space complexity is constant 
     * because we sort the input array in place. If we are not allowed to modify the input array,
     * we must spend linear space to store a sorted copy.
     */
    int longestConsecutive_1(vector<int> &nums)
    {
        int numsLen = nums.size();
        if (0 == numsLen)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int longestStreak = 1;
        int currentStreak = 1;

        for (int i = 1; i < numsLen; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                if (nums[i] == nums[i - 1] + 1)
                {
                    currentStreak += 1;
                }
                else
                {
                    longestStreak = max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }
        return max(longestStreak, currentStreak);
    }
    /**
     * Approach 3: HashSet and Intelligent Sequence Building
     * Time complexity : O(n).
     * Although the time complexity appears to be quadratic due to the while loop nested 
     * within the for loop, closer inspection reveals it to be linear. 
     * Because the while loop is reached only when currentNum marks the beginning of a 
     * sequence (i.e. currentNum-1 is not present in nums), 
     * the while loop can only run for nn iterations throughout the entire runtime of the algorithm.
     *  This means that despite looking like O(n \cdot n)O(n⋅n) complexity, 
     * the nested loops actually run in O(n+n)=O(n) time.
     *  All other computations occur in constant time, so the overall runtime is linear.
     * 
     * Space complexity : O(n).
     * In order to set up O(1) containment lookups, 
     * we allocate linear space for a hash table to store the O(n) numbers in nums.
     *  Other than that, the space complexity is identical to that of the brute force solution.
     */
    int longestConsecutive_2(vector<int> &nums)
    {
        int numsLen = nums.size();
        if (0 == numsLen)
        {
            return 0;
        }
        unordered_set<int> numSet;
        for (int num : nums)
        {
            numSet.insert(num);
        }
        int longestStreak = 0;
        for (int num : numSet)
        {
            if (numSet.find(num - 1) == numSet.end())
            {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end())
                {
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }

    /**
     *  vector<flag> 
     *  8ms
     * Time: O(n)
     * Space: O(max-min+1)
     */
    int longestConsecutive_4(vector<int> &nums)
    {
        int numsLen = nums.size();
        if (0 == numsLen)
        {
            return 0;
        }
        // int maxV = INT_MIN, minV = INT_MAX;
        // for (int i = 0; i < numsLen; i++)
        // {
        //     if (maxV < nums[i])
        //         maxV = nums[i];
        //     if (minV > nums[i])
        //         minV = nums[i];
        // }
        int maxV = *max_element(nums.begin(), nums.end()), minV = *min_element(nums.begin(), nums.end());
        // +1 max==min
        int len = maxV - minV + 1;
        vector<bool> flag(len, false);
        for (int i = 0; i < numsLen; i++)
        {
            flag[nums[i] - minV] = true;
        }

        int longestStreak = 0, currentStreak = 0;
        for (int i = 0; i < len; i++)
        {
            if (flag[i])
                currentStreak++;
            else
                currentStreak = 0;
            // longestStreak = max(longestStreak, currentStreak);
            longestStreak = longestStreak < currentStreak ? currentStreak : longestStreak;
        }
        return longestStreak;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << solution.longestConsecutive_4(nums) << endl;
    system("pause");
    return 0;
}
