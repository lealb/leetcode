#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 100
 * 
 */
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.empty() && grid[0].empty())
        {
            return 0;
        }
        // init
        int n = grid.size(), m = grid[0].size();
        int f[n][m];
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            res += grid[i][0];
            f[i][0] = res;
        }
        res = 0;
        for (int i = 0; i < m; ++i)
        {
            res += grid[0][i];
            f[0][i] = res;
        }
        // compute
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }
        return f[n - 1][m - 1];
    }
    int minPathSum_1(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++)
        {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << solution.minPathSum(grid) << endl;
    system("pause");
    return 0;
}
