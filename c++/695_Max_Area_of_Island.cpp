#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    void visit(vector<vector<int>> &grid, int m, int n, int i, int j, int *area)
    {
        if (i - 1 >= 0 && grid[i - 1][j])
        {
            grid[i - 1][j] = 0;
            (*area)++;
            visit(grid, m, n, i - 1, j, area);
        }
        if (i + 1 < m && grid[i + 1][j])
        {
            grid[i + 1][j] = 0;
            (*area)++;
            visit(grid, m, n, i + 1, j, area);
        }
        if (j - 1 >= 0 && grid[i][j - 1])
        {
            grid[i][j - 1] = 0;
            (*area)++;
            visit(grid, m, n, i, j - 1, area);
        }
        if (j + 1 < n && grid[i][j + 1])
        {
            grid[i][j + 1] = 0;
            (*area)++;
            visit(grid, m, n, i, j + 1, area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        int ret = 0;
        if (!m || !n)
        {
            return ret;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    grid[i][j] = 0;
                    int area = 1;
                    visit(grid, m, n, i, j, &area);
                    if (area > ret)
                        ret = area;
                }
            }
        }
        return ret;
    }
    int area(vector<vector<int>> &grid, int r, int c)
    {
        int rGrid = grid.size(), cGrid = grid[0].size();
        if (r < 0 || r >= rGrid || c < 0 || c >= cGrid || grid[r][c] == 0)
        {
            return 0;
        }
        return 1 + area(grid, r + 1, c) + area(grid, r - 1, c) + area(grid, r, c - 1) + area(grid, r, c + 1);
    }
    /**
     * Approach #1: Depth-First Search (Recursive) 
     */
    int maxAreaOfIsland_0(vector<vector<int>> &grid)
    {
        int rGrid = grid.size(), cGrid = grid[0].size();
        int ans = 0;
        for (int r = 0; r < rGrid; r++)
        {
            for (int c = 0; c < cGrid; c++)
            {
                if (grid[r][c])
                {
                    ans = max(ans, area(grid, r, c));
                }
            }
        }
        return ans;
    }
    int maxAreaOfIsland_1(vector<vector<int>> &grid)
    {
        int rGrid = grid.size(), cGrid = grid[0].size();
        vector<vector<bool>> seen(rGrid, vector<bool>(cGrid));
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        int ans = 0;
        for (int r0 = 0; r0 < rGrid; r0++)
        {
            for (int c0 = 0; c0 < cGrid; c0++)
            {
                if (grid[r0][c0] == 1 && !seen[r0][c0])
                {
                    int shape = 0;
                    stack<vector<int>> stack;
                    stack.push({r0, c0});
                    seen[r0][c0] = true;
                    while (!stack.empty())
                    {
                        vector<int> node = stack.top();
                        stack.pop();
                        int r = node[0], c = node[1];
                        shape++;
                        for (int k = 0; k < 4; k++)
                        {
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            if (0 <= nr && nr < rGrid &&
                                0 <= nc && nc < cGrid &&
                                grid[nr][nc] == 1 && !seen[nr][nc])
                            {
                                stack.push({nr, nc});
                                seen[nr][nc] = true;
                            }
                        }
                    }
                    ans = max(ans, shape);
                }
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << solution.maxAreaOfIsland_0(grid) << endl;
    system("pause");
    return 0;
}
