#include <iostream>
#include <vector>

using namespace std;
/**
 * The value in the given matrix is in the range of [0, 255].
 * The length and width of the given matrix are in the range of [1, 150].
*/
class Solution
{
public:
    /**
     * Approach #1: Iterate Through Grid
     * Time Complexity: O(N)
     * Space Complexity: O(N)
     */
    vector<vector<int>> imageSmoother_0(vector<vector<int>> &M)
    {
        int row = M.size(), col = M[0].size();
        vector<vector<int>> ans(row, vector<int>(col));
        for (int r = 0; r < row; ++r)
            for (int c = 0; c < col; ++c)
            {
                int count = 0;
                for (int nr = r - 1; nr <= r + 1; ++nr)
                    for (int nc = c - 1; nc <= c + 1; ++nc)
                    {
                        if (0 <= nr && nr < row && 0 <= nc && nc < col)
                        {
                            ans[r][c] += M[nr][nc];
                            count++;
                        }
                    }
                ans[r][c] /= count;
            }
        return ans;
    }
    vector<vector<int>> imageSmoother_1(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int cnt = 0, tot = 0;
                for (int x = i - 1; x <= i + 1; x++)
                {
                    // if (x < 0 || x >= m)
                    // {
                    //     continue;
                    // }
                    // for (int y = j - 1; y <= j + 1; y++)
                    // {
                    //     if (y < 0 || y >= n)
                    //     {
                    //         continue;
                    //     }
                    //     cnt++;
                    //     tot += matrix[x][y];
                    // }
                    if (x >= 0 && x < m)
                    {
                        for (int y = j - 1; y <= j + 1; y++)
                        {
                            if (y >= 0 && y < n)
                            {
                                cnt++;
                                tot += matrix[x][y];
                            }
                        }
                    }
                }
                ans[i][j] = tot / cnt;
            }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> M = {{1, 1, 1},
                             {1, 0, 1},
                             {1, 1, 1}};
    vector<vector<int>> ans = solution.imageSmoother_1(M);
    for (int i = 0; i < ans.size(); i++)
    {
        for (auto n : ans[i])
        {
            cout << n << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
