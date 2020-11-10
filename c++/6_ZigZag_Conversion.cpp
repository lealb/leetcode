#include <iostream>
#include <vector>
#include <unordered_map>
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
    /**
     * 
     * 1 <= s.length <= 1000
     * s consists of English letters (lower-case and upper-case), ',' and '.'.
     * 1 <= numRows <= 1000
    */
    string convert_1(string s, int numRows)
    {
        int strLength = s.length();
        // 约定
        if (numRows >= strLength)
            return s;
        unordered_map<int, string> currRowStrings;
        string res;

        int i = 0, j = 0;
        while (j < strLength)
        {
            while (i < numRows && j < strLength)
                currRowStrings[i++].push_back(s[j++]);
            i -= 2;
            while (i >= 0 && j < strLength)
                currRowStrings[i--].push_back(s[j++]);
            i += 2;
        }
        for (int i = 0; i < numRows; i++)
            res += currRowStrings[i];
        return res;
    }
    string convert_3(string s, int n)
    {
        int strLength = s.length();
        // c++ 11 支持 or 表示||
        if (strLength <= 1 or strLength <= n or n == 1)
            return s;
        string res(strLength, ' ');
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < strLength; j += 2 * n - 2)
            {
                if (i != 0 and i != n - 1)
                {
                    res[count++] = s[j];
                    if (j + 2 * (n - i - 1) < strLength)
                    {
                        res[count++] = s[j + 2 * (n - i - 1)];
                    }
                }
                else
                {
                    res[count++] = s[j];
                }
            }
        }
        return res;
    }
    string convert_4(string s, int numRows)
    {
        size_t size = s.size();
        size_t len = numRows;
        if (size < 2 || len == 1 || len == size)
        {
            return s;
        }
        string result(size, 0);
        auto o = result.data();
        for (size_t i = 0; i < len; ++i)
        {
            struct
            {
                size_t x;
                size_t y;
            } increments = {0, 0};
            size_t const zerothIncrement = 2 * (len - 1);

            if (0 == i || len - 1 == i)
            {
                increments = {zerothIncrement, zerothIncrement};
            }
            else
            {
                increments.x = 2 * i;
                increments.y = zerothIncrement - increments.x;
            }

            for (long j = 0, k = i, g = s.size();
                 k < g;
                 ++j, k += (j % 2 == 0 ? increments.x : increments.y))
            {
                *o++ = s[k];
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    string testStr = "PAYPALISHIRING";
    Solution s;
    cout << s.convert_4(testStr, 3) << endl;
    return 0;
}
