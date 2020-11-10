#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int rows = triangle.size();
        if (rows == 0)
        {
            return 0;
        }
        int maxCols = triangle[rows - 1].size();
        if (maxCols == 0)
        {
            return 0;
        }
        vector<int> dp(maxCols + 1);
        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};
    cout << solution.minimumTotal(triangle) << endl;
    system("pause");
    return 0;
}
