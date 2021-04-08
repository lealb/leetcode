#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool solve(string &s, string &p, int a, int b)
    {
        int sLen = s.length(), pLen = p.length();
        if (b == pLen)
        {
            return a == sLen;
        }
        int temp = (a < sLen && (s[a] == p[b] || p[b] == '.'));
        if ((b + 1) < pLen && p[b + 1] == '*')
        {
            return (temp && solve(s, p, a + 1, b)) || solve(s, p, a, b + 2);
        }
        else
        {
            return temp && solve(s, p, a + 1, b + 1);
        }
    }
    bool isMatch_1(string s, string p)
    {
        return solve(s, p, 0, 0);
    }
    /**
     * @brief 
     * '.' 匹配任意单个字符
     * '*' 匹配零个或多个前面的那一个元素
     * 
     * @param s 
     * @param p 
     * @return true 
     * @return false 
     */
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0)
            {
                return false;
            }
            if (p[j - 1] == '.')
            {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] == '*')
                {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1))
                    {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else
                {
                    if (matches(i, j))
                    {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }

    int sn;
    int pn;
    vector<vector<bool>> memory; //记忆容器

    bool backtracking(string &s, string &p, int sIndex, int pIndex)
    {
        //记忆化剪枝
        if (!memory[sIndex][pIndex])
        {
            return false;
        }
        if (sIndex == sn)
        {
            memory[sIndex][pIndex] = pIndex == pn || (pIndex + 1 < pn && p[pIndex + 1] == '*' && backtracking(s, p, sIndex, pIndex + 2));
            return memory[sIndex][pIndex];
        }
        else if (pn == pIndex)
        {
            memory[sIndex][pIndex] = false;
            return false;
        }

        if (s[sIndex] == p[pIndex] || p[pIndex] == '.')
        {
            //当前位置成功匹配
            if (pIndex + 1 < pn && p[pIndex + 1] == '*')
            {
                //复制+终结+越过
                memory[sIndex][pIndex] = backtracking(s, p, sIndex + 1, pIndex) || backtracking(s, p, sIndex + 1, pIndex + 2) || backtracking(s, p, sIndex, pIndex + 2);
                return memory[sIndex][pIndex];
            }
            else
            {
                memory[sIndex][pIndex] = backtracking(s, p, sIndex + 1, pIndex + 1);
                return memory[sIndex][pIndex];
            }
        }
        else
        {
            //未成功匹配
            //找p下一位* 或者匹配失败
            if (pIndex + 1 < pn && p[pIndex + 1] == '*')
            {
                memory[sIndex][pIndex] = backtracking(s, p, sIndex, pIndex + 2);
                return memory[sIndex][pIndex];
            }
            else
            {
                memory[sIndex][pIndex] = false;
                return false;
            }
        }
    }
    /**
     * @brief 回溯算法+记忆
     * 
     * @param s 
     * @param p 
     * @return true 
     * @return false 
     */
    bool isMatch_2(string s, string p)
    {
        sn = s.size();
        pn = p.size();

        memory = vector<vector<bool>>(sn + 1, vector<bool>(pn + 1, true));

        return backtracking(s, p, 0, 0);
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "mississippi", p = "mis*is*p*.";
    cout << solution.isMatch_1(s, p) << endl;
    system("pause");
    return 0;
}
