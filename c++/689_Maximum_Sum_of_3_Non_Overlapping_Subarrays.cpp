#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * size will be between 1 and 20000.
 * nums[i] will be between 1 and 65535.
 * k will be between 1 and floor(size / 3).
*/
class Solution
{
public:
    vector<int> maxSumOfNSubarrays(vector<int> &nums, int k, int n)
    {
        if (k < 1 || n * k > nums.size())
        {
            return {};
        }
        int N = nums.size();
        int s = 0;
        for (int i = 0; i < k; ++i)
        {
            s += nums[i];
        }
        // 计算每个数的前k个数的前缀和
        vector<int> sums(N, 0);
        sums[k - 1] = s;
        for (int i = k; i < N; ++i)
        {
            s += nums[i] - nums[i - k];
            sums[i] = s;
        }
        // 动态规划
        vector<vector<int>> dp(N, vector<int>(n + 1, 0));
        vector<vector<int>> path(N, vector<int>(n + 1, 0));
        dp[k - 1][1] = sums[k - 1];
        path[k - 1][1] = k - 1;
        for (int i = k; i < N; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = path[i - 1][j];
                if (sums[i] + dp[i - k][j - 1] > dp[i][j])
                {
                    dp[i][j] = sums[i] + dp[i - k][j - 1];
                    path[i][j] = i;
                }
            }
        }
        // 路径回溯
        vector<int> res;
        int ind = path[N - 1][n];
        res.push_back(ind - k + 1);
        for (int i = n - 1; i > 0; --i)
        {
            ind = path[ind - k][i];
            res.push_back(ind - k + 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        // 本题就是n=3的特殊情况，因此调用以下函数即可
        return maxSumOfNSubarrays(nums, k, 3);
    }
    vector<int> maxSumOfThreeSubarrays_1(vector<int> &nums, int k)
    {
        int size = nums.size();
        // W is an array of sums of windows
        vector<int> W(size - k + 1);
        int currSum = 0;
        for (int i = 0; i < size; i++)
        {
            currSum += nums[i];
            if (i >= k)
            {
                currSum -= nums[i - k];
            }
            if (i >= k - 1)
            {
                W[i - k + 1] = currSum;
            }
        }
        int wSize = W.size();
        vector<int> left(wSize);
        int best = 0;
        for (int i = 0; i < wSize; i++)
        {
            if (W[i] > W[best])
                best = i;
            left[i] = best;
        }
        vector<int> right(wSize);
        best = wSize - 1;
        for (int i = wSize - 1; i >= 0; i--)
        {
            if (W[i] >= W[best])
            {
                best = i;
            }
            right[i] = best;
        }

        vector<int> ans = {-1, -1, -1};
        for (int j = k; j < wSize - k; j++)
        {
            int i = left[j - k], l = right[j + k];
            if (ans[0] == -1 || W[i] + W[j] + W[l] > W[ans[0]] + W[ans[1]] + W[ans[2]])
            {
                ans[0] = i;
                ans[1] = j;
                ans[2] = l;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 1, 2, 6, 7, 5, 1};
    vector<int> res = solution.maxSumOfThreeSubarrays(nums, 2);
    for (auto r : res)
    {
        cout << r << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
