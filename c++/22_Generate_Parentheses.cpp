#include <iostream>
#include <vector>

using namespace std;
class Solution
{
    /**
     * @brief 判断括号是否合法
     * 
     * @param str 
     * @return true 
     * @return false 
     */
    bool isVaild(const string &str)
    {
        int balance = 0;
        for (char c : str)
        {
            c == '(' ? ++balance : --balance;
            if (balance < 0)
            {
                return false;
            }
        }
        return balance == 0;
    }

    void generate(string &current, int n, vector<string> &result)
    {
        if (n == current.size())
        {
            if (isVaild(current))
            {
                result.push_back(current);
            }
            return;
        }
        current += '(';
        generate(current, n, result);
        current.pop_back();
        current += ')';
        generate(current, n, result);
        current.pop_back();
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string current;
        generate(current, n * 2, result);
        return result;
    }

    /**
     * @brief 回溯算法
     * 
     * @param n 
     * @return vector<string> 
     */
    vector<string> generateParenthesis_1(int n)
    {
        //n is number of pairs of parentheses
        vector<string> ans;
        backtrack(ans, string(), 0, 0, n);
        return ans;
    }

    void backtrack(vector<string> &ans, string cur, int open, int close, int max)
    {
        if (cur.size() == max * 2)
        {
            ans.push_back(cur);
            return;
        }

        if (open < max)
        {
            cur += "(";
            backtrack(ans, cur, open + 1, close, max);
            cur.erase(cur.begin() + cur.length() - 1);
        }
        if (close < open)
        {
            cur += ")";
            backtrack(ans, cur, open, close + 1, max);
            cur.erase(cur.begin() + cur.length() - 1);
        }
    }
    /**
     * @brief 递归的DP
     * 
     * @param n 
     * @return vector<string> 
     */
    vector<string> generateParenthesis_2(int n)
    {
        vector<vector<string>> v(n + 1);
        v[0].push_back("");
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                for (string &str1 : v[j])
                {
                    for (string &str2 : v[i - j - 1])
                    {
                        v[i].push_back("(" + str2 + ")" + str1);
                    }
                }
            }
        }
        return v[n];
    }

    int bits(int n)
    {
        int res = 0;
        while (n)
        {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
    vector<string> generateParenthesis_3(int n)
    {
        vector<string> parenthesis;
        for (int i = 0; i < (1 << (2 * n)); i++)
        {
            if (bits(i) == n)
            {
                int t = i;
                int count = 0;
                bool vaild = true;
                string s;
                for (int j = 0; vaild && j < 2 * n; j++)
                {
                    if (t % 2)
                    {
                        count++;
                        s.push_back('(');
                    }
                    else
                    {
                        if (count)
                        {
                            count--;
                            s.push_back(')');
                        }
                        else
                        {
                            vaild = false;
                        }
                    }
                    t = t / 2;
                }
                if (vaild)
                {
                    parenthesis.emplace_back(s);
                }
            }
        }
        return parenthesis;
    }
    /**
     * @brief DFS
     * 
     * @param n 
     * @return vector<string> 
     */
    vector<string> generateParenthesis_4(int n)
    {
        vector<string> ans;
        dfs(0, 2 * n, 0, n, "", ans);
        return ans;
    }

    void dfs(int i, int n, int score, int max, string path, vector<string> &ans)
    {
        if (i == n)
        {
            if (score == 0)
            {
                ans.push_back(path);
            }
        }
        else
        {
            if (score + 1 <= max)
            {
                dfs(i + 1, n, score + 1, max, path + "(", ans);
            }
            if (0 <= score - 1)
            {
                dfs(i + 1, n, score - 1, max, path + ")", ans);
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> res = solution.generateParenthesis(4);
    for (auto v : res)
    {
        cout << v << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
