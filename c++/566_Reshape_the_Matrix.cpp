#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/**
 * The height and width of the given matrix is in range [1, 100].
 * The given r and c are all positive.
 */
class Solution
{
public:
    /**
     * vector
     * T: O(m⋅n)^2
     * S:O(m*n)
     */
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int row = nums.size(), col = nums[0].size();
        vector<vector<int>> ans(r, vector<int>(c));
        if (row == 0 || r * c != row * col)
        {
            return nums;
        }
        vector<int> tmp;
        for (int i = 0; i < row; ++i)
        {
            for (auto n : nums[i])
            {
                tmp.push_back(n);
            }
        }
        int k = 0, count = tmp.size();
        while (k < count)
        {
            for (int i = 0; i < r; ++i)
            {
                for (int j = 0; j < c; j++)
                {

                    ans[i][j] = tmp[k];
                    k++;
                }
            }
        }
        return ans;
    }
    /**
     * queue
     * T: O(m⋅n)
     * S:O(m*n)
     */
    vector<vector<int>> matrixReshape_1(vector<vector<int>> &nums, int r, int c)
    {
        vector<vector<int>> ans(r, vector<int>(c));
        int row = nums.size(), col = nums[0].size();
        if (r == row || row == 0 || r * c != row * col)
        {
            return nums;
        }
        queue<int> queue;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                queue.push(nums[i][j]);
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                ans[i][j] = queue.front();
                queue.pop();
            }
        }
        return ans;
    }
    /**
     * 
     * T: O(m⋅n)
     * S:O(1)
     */
    vector<vector<int>> matrixReshape_2(vector<vector<int>> &nums, int r, int c)
    {
        vector<vector<int>> ans(r, vector<int>(c));
        int row = nums.size(), col = nums[0].size();
        if (r == row || row == 0 || r * c != row * col)
        {
            return nums;
        }
        int nRows = 0, nCols = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                ans[nRows][nCols] = nums[i][j];
                nCols++;
                if (nCols == c)
                {
                    nRows++;
                    nCols = 0;
                }
            }
        }
        return ans;
    }

    /**
     * Approach 3: Using division and modulus
     */
    vector<vector<int>> matrixReshape_3(vector<vector<int>> &nums, int r, int c)
    {
        vector<vector<int>> ans(r, vector<int>(c));
        int row = nums.size(), col = nums[0].size();
        if (r == row || row == 0 || r * c != row * col)
        {
            return nums;
        }
        int count = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                ans[count / c][count % c] = nums[i][j];
                count++;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> nums = {{1, 2}, {3, 4}};
    vector<vector<int>> res = solution.matrixReshape_3(nums, 4, 1);
    for (int i = 0; i < res.size(); i++)
    {
        for (auto r : res[i])
        {
            cout << r << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
