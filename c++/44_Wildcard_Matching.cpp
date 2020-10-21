#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 1] || i && (dp[i - 1][j] || dp[i - 1][j - 1]);
                }
                else
                {
                    dp[i][j] = i && dp[i - 1][j - 1] && (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
                }
            }
        }
        return dp[s.size()][p.size()];
    }
    bool isMatch_1(string s, string p)
    {
        int n = s.size(), m = p.size();
        if (n == 0 && m == 0)
            return true;
        if (m == 0)
            return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        int star = 0, ques = 0;
        for (int i = 0; i < m; i++)
        {
            if (p[i] == '*')
                star++;
            if (p[i] == '?')
                ques++;
        }
        if (star == m)
            return true;
        if (ques == m && n == m)
            return true;
        for (int i = 0; i <= n; i++)
            dp[i][0] = false;
        dp[0][0] = true;
        for (int j = 1; j < m; j++)
            dp[0][j] = p[j - 1] == '*' && dp[0][j - 1];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (p[j - 1] >= 'a' && p[j - 1] <= 'z')
                    dp[i][j] = dp[i - 1][j - 1] && (bool)(s[i - 1] == p[j - 1]);
                else if (p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
    bool isMatch_2(string s, string p)
    {
        int ls = s.length();
        int ps = p.length();
        vector<vector<int>> dp(ls + 1, vector<int>(ps + 1, 0));
        dp[0][0] = 1;

        //fill the 0th row.
        for (int i = 1; i <= ps; i++)
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 1];

        //fill the remaining.
        for (int i = 1; i <= ls; i++)
        {
            for (int j = 1; j <= ps; j++)
            {
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];

                else if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                //mismatch
                else
                    dp[i][j] = 0;
            }
        }
        return dp[ls][ps];
    }
    bool isMatch_3(string s, string p)
    {
        int i = 0, j, p_size = p.size(), s_size = s.size();

        if (s_size == 0)
        {
            while (i < p_size && p[i] == '*')
                ++i;

            return (i < p_size) ? false : true;
        }

        int *match_table = new int[p_size];
        memset(match_table, -1, p_size * 4);

        for (i = 0, j = 0; i < p_size && j < s_size;)
        {
            switch (p[i])
            {
            case '?':
                ++i;
                ++j;
                break;
            case '*':
                match_table[i] = j;
                ++i;
                if (i == p_size)
                    j = s_size; // match, escape loop
                break;
            default:
                if (p[i] == s[j])
                {
                    ++i;
                    ++j;
                }
                else
                {
                    while (i >= 0 && p[i] != '*')
                        --i;
                    if (i < 0)
                    {
                        j = s_size; // doesn't match, escape loop
                        break;
                    }
                    else
                    {
                        // back to previous *
                        match_table[i] += 1;
                        j = match_table[i];
                        ++i;
                    }
                }
            }

            // i >= p_size && j < s_size
            if (i >= p_size && j < s_size)
            {
                while (i >= 0 && p[i] != '*')
                    --i;
                if (i < 0)
                {
                    j = s_size; // doesn't match, escape loop
                    break;
                }
                else
                {
                    // back to previous *
                    match_table[i] += 1;
                    j = match_table[i];
                    ++i;
                }
            }
            while (j >= s_size && i >= 0 && i < p_size && p[i] == '*')
                ++i;
        }

        // doesn't match
        bool res;
        if (i < p_size || j < s_size)
            res = false;
        else
            res = true;

        delete[] match_table;
        return res;
    }
    bool isMatch_4(string s, string p)
    {
        int sIndex = 0, sLen = s.size();
        int pIndex = 0, pLen = p.size();
        int sBackupIndex = -1;
        int pBackupIndex = -1;

        while (sIndex < sLen)
        {
            if (pIndex < pLen && (p[pIndex] == '?' || p[pIndex] == s[sIndex]))
            {
                sIndex++;
                pIndex++;
            }
            else if (pIndex < pLen && p[pIndex] == '*')
            {
                //note down both positions and will increment
                // one by one
                sBackupIndex = sIndex;
                pBackupIndex = pIndex;
                pIndex++;
            }
            else if (pBackupIndex == -1)
            {
                return false;
            }
            else
            {
                sIndex = sBackupIndex + 1;
                pIndex = pBackupIndex + 1;
                sBackupIndex = sIndex;
            }
        }
        for (int i = pIndex; i < pLen; i++)
        {
            if (p[i] != '*')
                return false;
        }
        return true;
    }
    bool isMatch_5(string s, string p)
    {
        if (s.length() == 0 && p.length() == 0)
            return true;
        int i = 0, j = 0, match = 0, starIdx = -1;

        while (i < s.length())
        {
            if (j < p.length() && (p[j] == '?' || s[i] == p[j]))
            {
                ++i;
                ++j;
            }
            else if (j < p.length() && p[j] == '*')
            {
                starIdx = j;
                match = i;
                ++j;
            }
            else if (starIdx != -1)
            {
                j = starIdx + 1;
                ++match;
                i = match;
            }
            else
                return false;
        }

        while (j < p.length() && p[j] == '*')
            ++j;

        return j == p.length();
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.isMatch("aaa", "a?c") << endl;
    system("pause");
    return 0;
}
