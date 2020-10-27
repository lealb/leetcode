#include <iostream>
#include <vector>

using namespace std;
/**
 * Four basic movement and one criterion in spiral matrix :
 * Criterion: Reducing boundary to avoid visiting duplicate point
 * 
 * Four basic movement:
 * 1.visit node form left to right in the topmost submatrix, reducing top boundary after visting
 *  for(idx=left;idx<=right;++idx); ++top
 * 2.visit node from top to bottom in the rightest submatrix, reducing right boundary after visting
 *  for(idx=top;idx<=bottom;++idx); --right
 * 3.visit node from right to left in the bottommost submatrix, reducing bottom boundary after visting
 *  for(idx=right;idx>=left;--idx); --bottom
 * 4.visit node from bottom to top in the leftest submatrix, reducing left boundary after visting
 *  for(idx=bottom;idx>=top;--idx); ++left
 * 
 * Restriction and terminating condition:
 * 1. checking boudary if available for traversing before traversal
 *  if(left>right || top>bottom ) break
 * 2.Left one node
 * if(left==right && top==bottom)
 * 3. Movement(3,4) are optional because after doing movement(1,2), we can reach situation which no available movment on unvisited point.
 * if(left<=right && top<=bottom)
 */
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int R = matrix.size(), C = matrix[0].size();
        vector<int> res;
        if (0 == R)
        {
            return res;
        }
        vector<vector<bool>> seen(R, vector<bool>(C, false));
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};
        int r = 0, c = 0, di = 0;
        for (int i = 0; i < R * C; i++)
        {
            res.push_back(matrix[r][c]);
            seen[r][c] = true;
            int cr = r + dr[di];
            int cc = c + dc[di];
            if (0 <= cr && cr < R && 0 <= cc && cc < C && !seen[cr][cc])
            {
                r = cr;
                c = cc;
            }
            else
            {
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
        }
        return res;
    }
    vector<int> spiralOrder_1(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        const int row = matrix.size(), col = row ? matrix[0].size() : 0;
        int left = 0, right = col - 1, top = 0, bottom = row - 1, idx = 0;
        while (1)
        {
            if (left > right || top > bottom)
                break;
            if (left == right && top == bottom)
            {
                ans.push_back(matrix[top][left]);
                break;
            }
            for (idx = left; idx <= right; ++idx)
                ans.push_back(matrix[top][idx]);
            ++top;
            for (idx = top; idx <= bottom; ++idx)
                ans.push_back(matrix[idx][right]);
            --right;
            if (left <= right && top <= bottom)
            {
                for (idx = right; idx >= left; --idx)
                    ans.push_back(matrix[bottom][idx]);
                --bottom;
                for (idx = bottom; idx >= top; --idx)
                    ans.push_back(matrix[idx][left]);
                ++left;
            }
        }
        return ans;
    }

    /**
     * Optimized version with solution 1
     */
    vector<int> spiralOrder_2(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        const int row = matrix.size(), col = row ? matrix[0].size() : 0;
        int left = 0, right = col - 1, top = 0, bottom = row - 1, idx = 0;
        while (left <= right && top <= bottom)
        {
            for (idx = left; idx <= right; ++idx)
                ans.push_back(matrix[top][idx]);
            ++top;
            for (idx = top; idx <= bottom; ++idx)
                ans.push_back(matrix[idx][right]);
            --right;
            if (left > right || top > bottom)
                break;
            for (idx = right; idx >= left; --idx)
                ans.push_back(matrix[bottom][idx]);
            --bottom;
            for (idx = bottom; idx >= top; --idx)
                ans.push_back(matrix[idx][left]);
            ++left;
        }
        return ans;
    }

    /**
     * Check moving point whether it has been visisted
     */
    vector<int> spiralOrder_3(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.size() == 0)
            return ans;
        const int row = matrix.size(), col = matrix[0].size();
        const int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        vector<vector<int>> used(row, vector<int>(col, 0));
        int r = 0, c = 0, newr, newc;
        ans.push_back(matrix[0][0]);
        used[0][0] = true;
        for (int i = 1, j = 0; i < row * col;)
        {
            newr = r + dir[j][1];
            newc = c + dir[j][0];
            if (newr >= 0 && newr < row && newc >= 0 && newc < col && !used[newr][newc])
            {
                r = newr, c = newc;
                ans.push_back(matrix[r][c]);
                used[r][c] = true;
                ++i;
            }
            else
                j = (j + 1) % 4;
        }
        return ans;
    }

    /**
     * Approach 2: Layer-by-Layer
     * Time Complexity: O(N), 
     * where N is the total number of elements in the input matrix. 
     * We add every element in the matrix to our final answer.
     * Space Complexity:
     * O(1) without considering the output array, since we don't use any additional data structures for our computations.
     * O(N) if the output array is taken into account.
     */
    vector<int> spiralOrder_4(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.size() == 0)
            return ans;
        int r1 = 0, r2 = matrix.size() - 1;
        int c1 = 0, c2 = matrix[0].size() - 1;
        while (r1 <= r2 && c1 <= c2)
        {
            for (int c = c1; c <= c2; c++)
                ans.push_back(matrix[r1][c]);
            for (int r = r1 + 1; r <= r2; r++)
                ans.push_back(matrix[r][c2]);
            if (r1 < r2 && c1 < c2)
            {
                for (int c = c2 - 1; c > c1; c--)
                    ans.push_back(matrix[r2][c]);
                for (int r = r2; r > r1; r--)
                    ans.push_back(matrix[r][c1]);
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res = solution.spiralOrder_1(matrix);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
