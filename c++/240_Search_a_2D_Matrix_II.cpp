#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= n, m <= 300
 * -10^9 <= matix[i][j] <= 10^9
 * All the integers in each row are sorted in ascending order.
 * All the integers in each column are sorted in ascending order.
 * -10^9 <= target <= 10^9
 */
class Solution
{
public:
    bool binarySearch(vector<int> nums, int target)
    {
        int low = 0, high = nums.size() - 1, mid;
        while (low <= high)
        {
            int mid = low + (high - low) >> 1;
            if (target == nums[mid])
            {
                return true;
            }
            else if (target > nums[mid])
            {
                mid = low + 1;
            }
            else
            {
                mid = high + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        const int m = matrix.size();
        if (m == 0)
        {
            return false;
        }
        const int n = matrix[0].size();
        if (n == 0)
        {
            return false;
        }
        int count = 0;

        int i = 0, j = n - 1;
        while (i < m && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] > target)
            {
                --j; // Go left
            }
            else
            {
                ++i; // Go down
            }
        }

        return false;
    }
    bool searchMatrix_1(vector<vector<int>> &matrix, int target)
    {
        std::ios::sync_with_stdio(0);
        if (matrix.size() == 1 && matrix[0].size() == 0)
        {
            return false;
        }
        while (matrix.size() != 0)
        {
            int temp = matrix[0][matrix[0].size() - 1];
            if (temp == target)
            {
                return true;
            }
            else if (temp > target)
            {
                for (int i = 0; i < matrix.size(); i++)
                {
                    matrix[i].pop_back();
                    if (matrix[i].size() == 0)
                    {
                        matrix.erase(matrix.begin() + i);
                    }
                }
            }
            else
            {
                matrix.erase(matrix.begin());
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
