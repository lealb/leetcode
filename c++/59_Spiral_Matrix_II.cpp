#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    /**
     * Approach 1: Traverse Layer by Layer in Spiral Form
     * Time Complexity: O(n^2). 
     *  Here, n is given input and we are iterating over n⋅n matrix in spiral form.
     * Space Complexity: O(1) 
     *  We use constant extra space for storing cntcnt.
     */
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n));
        int cnt = 1;
        for (int layer = 0; layer < (n + 1) / 2; layer++)
        {
            // direction 1 - traverse from left to right
            for (int ptr = layer; ptr < n - layer; ptr++)
            {
                result[layer][ptr] = cnt++;
            }
            // direction 2 - traverse from top to bottom
            for (int ptr = layer + 1; ptr < n - layer; ptr++)
            {
                result[ptr][n - layer - 1] = cnt++;
            }
            // direction 3 - traverse from right to left
            for (int ptr = n - layer - 2; ptr >= layer; ptr--)
            {
                result[n - layer - 1][ptr] = cnt++;
            }
            // direction 4 - traverse from bottom to top
            for (int ptr = n - layer - 2; ptr > layer; ptr--)
            {
                result[ptr][layer] = cnt++;
            }
        }
        return result;
    }

    int floorMod(int x, int y)
    {
        return ((x % y) + y) % y;
    }
    /**
     * Approach 2: Optimized spiral traversal
     *Time Complexity: O(n^2). 
     *  Here, n is given input and we are iterating over n⋅n matrix in spiral form.
     *Space Complexity: O(1) 
     *  We use constant extra space for storing cntcnt.
     */
    vector<vector<int>> generateMatrix_2(int n)
    {
        vector<vector<int>> result(n, vector<int>(n));
        int cnt = 1;
        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        int row = 0;
        int col = 0;
        while (cnt <= n * n)
        {
            result[row][col] = cnt++;
            int r = floorMod(row + direction[d][0], n);
            int c = floorMod(col + direction[d][1], n);
            // change direction if next cell is non zero
            if (result[r][c] != 0)
                d = (d + 1) % 4;
            row += direction[d][0];
            col += direction[d][1];
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> res = solution.generateMatrix(3);
    for (int i = 0; i < res.size(); i++)
    {
        for (auto v : res[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
