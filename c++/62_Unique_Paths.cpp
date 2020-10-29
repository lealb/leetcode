#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //dp[i][j] => no of ways to reach (0,0) to (i,j)
        int i = 0, j = 1;
        while (i < m || j < n)
        {
            if (i < m)
            {
                dp[i++][0] = 1;
            }
            if (j < n)
            {
                dp[0][j++] = 1;
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePaths_1(int m, int n)
    {
        vector<vector<int>> grid(m, vector<int>(n));
        grid[m - 1][0] = 1;
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j > 0)
                    grid[i][j] += grid[i][j - 1];
                if (i < m - 1)
                    grid[i][j] += grid[i + 1][j];
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        return grid[0][n - 1];
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.uniquePaths_1(3, 7) << endl;
    system("pause");
    return 0;
}
