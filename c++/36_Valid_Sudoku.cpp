#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool a[9][9] = {false}, b[9][9] = {false}, c[3][3][9] = {false};
        int n;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (isdigit(board[i][j]))
                {
                    n = board[i][j] - '1';
                    if (a[i][n] || b[j][n] || c[i / 3][j / 3][n])
                        return false;
                    a[i][n] = b[j][n] = c[i / 3][j / 3][n] = true;
                }
            }
        }
        return true;
    }
    bool isValidSudoku_1(vector<vector<char>> &board)
    {
        int rows[9][10];
        int cols[9][10];
        int boxes[9][10];
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(boxes, 0, sizeof(boxes));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    if (++rows[i][num] > 1 || ++cols[j][num] > 1 || ++boxes[(i / 3) * 3 + j / 3][num] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<char>> board =
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    vector<char> testS = {'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    cout << solution.isValidSudoku(board) << endl;
    // system("pause");
    return 0;
}
