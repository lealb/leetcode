#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    /**
     * Time: O(n)
     * Space:O(1)
     */
    int maxProduct_0(vector<int> &nums)
    {
        int numsLen = nums.size();
        if (0 == numsLen)
        {
            return 0;
        }
        int currMax = 1, currMin = 1, maxProd = INT_MIN;
        for (int i = 0; i < numsLen; i++)
        {
            int temp = currMax;
            currMax = max(nums[i], nums[i] * currMax);
            if (currMin < 0)
            {
                currMax = max(currMax, currMin * nums[i]);
            }
            currMin = min(nums[i], currMin * nums[i]);
            currMin = min(currMin, temp * nums[i]);
            maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }

    /**
     * Time: O(n)
     * Space:O(n)
     */
    int maxProduct_1(vector<int> &nums)
    {
        int numsLen = nums.size();
        if (0 == numsLen)
        {
            return 0;
        }
        if (1 == numsLen)
        {
            return nums[0];
        }

        int maxEnd[numsLen];
        int minEnd[numsLen];

        maxEnd[0] = nums[0];
        minEnd[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < numsLen; ++i)
        {
            int curr = nums[i];
            int maxCurr = maxEnd[i - 1] * curr, minCurr = minEnd[i - 1] * curr;
            maxEnd[i] = max(curr, max(maxCurr, minCurr));
            minEnd[i] = min(curr, min(maxCurr, minCurr));
            result = max(result, maxEnd[i]);
        }
        return result;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {2, 3, -2, 4};
    cout << solution.maxProduct_1(nums) << endl;
    system("pause");
    return 0;
}
