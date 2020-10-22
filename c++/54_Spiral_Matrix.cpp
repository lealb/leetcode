#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        if (1 == m == n)
        {
            return {matrix[0][0]};
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res = solution.spiralOrder(matrix);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
