#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
/**
 *  log(∏xi)=∑logxi
 */
class Solution
{
public:
    /**
     * Approach #1: Binary Search on Logarithms
     */
    int numSubarrayProductLessThanK_0(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            return 0;
        }
        double logk = log(k);
        int size = nums.size();
        vector<double> prefix(size + 1);
        for (int i = 0; i < size; i++)
        {
            prefix[i + 1] = prefix[i] + log(nums[i]);
        }

        int ans = 0;
        for (int i = 0; i < size + 1; i++)
        {
            int low = i + 1, high = size + 1;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                // double
                if (prefix[mid] < prefix[i] + logk - 1e-9)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid;
                }
            }
            ans += low - i - 1;
        }
        return ans;
    }

    /**
     * Approach #2: Sliding Window
     */
    int numSubarrayProductLessThanK_1(vector<int> &nums, int k)
    {
        if (k <= 1)
        {
            return 0;
        }
        int prod = 1, ans = 0, left = 0;
        int size = nums.size();
        for (int right = 0; right < size; right++)
        {
            prod *= nums[right];
            while (prod >= k)
            {
                prod /= nums[left++];
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {10, 5, 2, 6};
    cout << solution.numSubarrayProductLessThanK_0(nums, 100) << endl;
    system("pause");
    return 0;
}
