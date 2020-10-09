#include <iostream>
#include <vector>
using namespace std;

/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font for better legibility)
 */
class Solution
{
public:
    string convert(string s, int numRows)
    {

        if (numRows == 1)
            return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows)
            ret += row;
        return ret;
    }
};
int main(int argc, char const *argv[])
{
    string testStr = "PAYPALISHIRING";
    Solution s;
    cout << s.convert(testStr, 3) << endl;
    return 0;
}
