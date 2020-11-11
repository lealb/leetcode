#include <iostream>
#include <vector>
using namespace std;
/**
 * 1 <= nums.length <= 2 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^5
 * 
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 */
class Solution
{
public:
    /**
     * Approach 1: Brute Force
     * Time complexity: O(n×k). All the numbers are shifted by one step(O(n)) k times.
     * Space complexity: O(1). No extra space is used.
     */
    void rotate_0(vector<int> &nums, int k)
    {
        int numsLen = nums.size();
        k %= numsLen;
        for (int i = 0; i < k; i++)
        {
            int previous = nums[numsLen - 1];
            for (int j = 0; j < numsLen; j++)
            {
                int temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }
    }
    /**
     * Approach 2: Using Extra Array
     * Time complexity: O(n). 
     *  One pass is used to put the numbers in the new array. 
     * And another pass to copy the new array to the original one.
     * Space complexity: O(n).
     *  Another array of the same size is used.
     */
    void rotate_1(vector<int> &nums, int k)
    {
        int numsLen = nums.size();
        vector<int> temp(numsLen);
        for (int i = 0; i < numsLen; i++)
        {
            temp[(i + k) % numsLen] = nums[i];
        }
        for (int i = 0; i < numsLen; i++)
        {
            nums[i] = temp[i];
        }
    }

    /**
     * Approach 3: Using Cyclic Replacements
     * Time complexity: O(n). Only one pass is used.
     * Space complexity: O(1). Constant extra space is used.
     */
    void rotate_2(vector<int> &nums, int k)
    {
        int numsLen = nums.size();
        k = k % numsLen;
        int count = 0;
        for (int start = 0; count < numsLen; start++)
        {
            int current = start;
            int prev = nums[start];
            do
            {
                int next = (current + k) % numsLen;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
    /**
     * Approach 4: Using Reverse
     * Time complexity: O(n). nn elements are reversed a total of three times.
     * Space complexity: O(1). No extra space is used.
     */
    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    void rotate_3(vector<int> &nums, int k)
    {
        int numsLen = nums.size();
        k %= numsLen;
        reverse(nums, 0, numsLen - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, numsLen - 1);
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    solution.rotate_2(nums, 3);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
