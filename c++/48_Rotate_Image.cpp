#include <iostream>
#include <vector>

using namespace std;
/**
 * matrix.length == n
 * matrix[i].length == n
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 */
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (1 == n)
        {
            return;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reversal of all rows
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }

    void rotate_1(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (1 == n)
        {
            return;
        }
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int temp = matrix[n - 1 - i][j];
                matrix[n - 1 - i][j] = matrix[n - 1 - j][n - 1 - i];
                matrix[n - 1 - j][n - 1 - i] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    solution.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (auto num : matrix[i])
        {
            cout << num << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
