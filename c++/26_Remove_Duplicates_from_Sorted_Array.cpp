#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    /**
 * Approach 1: Two Pointers
 * Time complextiy : O(n). Assume that nn is the length of array.
 *  Each of i and j traverses at most nn steps.
 * Space complexity : O(1).
 */
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int i = 0;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
    int removeDuplicates_1(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int j = 1, ans = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                nums[j++] = nums[i + 1], ans++;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << solution.removeDuplicates_1(nums) << endl;
    return 0;
}
