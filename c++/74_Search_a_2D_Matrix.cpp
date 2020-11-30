#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &m, int t)
    {
        // pointless edge case we still have to consider
        if (!m.size() || !m[0].size())
        {
            return false;
        }
        // support variables
        int row, l = 0, r = m.size() - 1, mid;
        while (l < r)
        {
            mid = l + (r - l >> 2);
            // moving l up if needed
            if (m[mid].back() < t)
                l = mid + 1;
            // moving r down if needed
            else if (m[mid][0] > t)
                r = mid - 1;
            // we found our row!
            else
            {
                l = mid;
                break;
            };
        }
        // storing the value of the new found row
        row = l;
        // resetting l and r to run a binary search on the rows
        l = 0;
        r = m[0].size() - 1;
        while (l <= r)
        {
            mid = l + (r - l >> 2);
            // moving l up if needed
            if (m[row][mid] < t)
                l = mid + 1;
            // moving r down if needed
            else if (m[row][mid] > t)
                r = mid - 1;
            // we found our value!
            else
                return true;
        }
        return false;
    }
    bool searchMatrix_1(vector<vector<int>> &matrix, int target)
    {
        if (!matrix.size())
        {
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0;
        int high = row * col - 1;

        while (low <= high)
        {
            int mid = low + (high - low >> 2);
            int rRow = mid / col, cCol = mid % cCol;
            if (matrix[rRow][cCol] == target)
            {
                return true;
            }
            if (matrix[rRow][cCol] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix_2(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        if (n == 0)
            return false;
        int m = matrix[0].size();
        if (m == 0)
            return false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
