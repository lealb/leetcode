#include <iostream>
#include <vector>

using namespace std;
/**
 * 1 <= k <= n <= 30,000.
 * Elements of the given array will be in the range [-10,000, 10,000].
 */
class Solution
{
public:
    /**
     * Approach #1 Cumulative Sum
     * O(n)
     */
    double findMaxAverage_0(vector<int> &nums, int k)
    {
        int size = nums.size();
        vector<int> numsSum(size);
        numsSum[0] = nums[0];
        for (int i = 1; i < size; i++)
        {
            numsSum[i] = numsSum[i - 1] + nums[i];
        }
        double res = numsSum[k - 1] * 1.0 / k;
        for (int i = k; i < size; i++)
        {
            res = max(res, (numsSum[i] - numsSum[i - k]) * 1.0 / k);
        }
        return res;
    }

    /**
     * Approach #2 Sliding Window 
     */
    double findMaxAverage_1(vector<int> &nums, int k)
    {
        double sum = 0;
        int size = nums.size();
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        double res = sum;
        for (int i = k; i < size; i++)
        {
            sum += nums[i] - nums[i - k];
            res = max(res, sum);
        }
        return res / k;
    }
    double findMaxAverage_2(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int size = nums.size();
        double curAv = 0, maxAv = 1.0 * INT_MIN;
        for (int i = 0; i < size; i++)
        {
            if (i < k)
            {
                curAv += nums[i];
            }
            else
            {
                maxAv = max(maxAv, curAv);
                curAv -= nums[i - k];
                curAv += nums[i];
            }
        }
        return max(maxAv, curAv) / k;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    cout << solution.findMaxAverage_1(nums, 4) << endl;
    system("pause");
    return 0;
}
