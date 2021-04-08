#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    /**
     * @brief Dp
     * 
     * @param str
     * @return int 
     */
    int longestValidParentheses_0(string str)
    {

        int n = str.length(), ans = 0;
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++)
        {
            if (str[i] == ')' && i - dp[i - 1] - 1 >= 0 && str[i - dp[i - 1] - 1] == '(')
            {
                dp[i] = 2 + dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    /**
     * @brief stack
     * 
     * @param s 
     * @return int 
     */
    int longestValidParentheses_1(string s)
    {
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
                if (stk.empty())
                {
                    stk.push(i);
                }
                else
                {
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
        return maxans;
    }
    /**
     * @brief 正反遍历两次字符串
     * Time:O(N)
     * Space:O(1)
     * @param s 
     * @return int 
     */
    int longestValidParentheses(string s)
    {
        int left = 0, right = 0, maxlength = 0;
        int sLen = s.length();
        for (int i = 0; i < sLen; i++)
        {
            s[i] == '(' ? left++ : right++;
            if (left == right)
            {
                maxlength = max(maxlength, 2 * right);
            }
            else if (right > left)
            {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = sLen - 1; i >= 0; i--)
        {
            s[i] == '(' ? left++ : right++;
            if (left == right)
            {
                maxlength = max(maxlength, 2 * left);
            }
            else if (left > right)
            {
                left = right = 0;
            }
        }
        return maxlength;
    }
    /**
     * @brief 滑动窗口
     * 
     * @param s 
     * @return int 
     */
    int longestValidParentheses_2(string s)
    {
        int left = 0, right = 0;
        int ans = 0;
        unordered_map<int, int> resMap;
        while (1)
        {
            //以括号为中心
            left = s.find("()", right);
            if (-1 == left)
            {
                break;
            }
            right = left + 1;
            // 扩展窗口
            vector<int> expandWind = expand(s, left, right);
            left = expandWind[0], right = expandWind[1];
            while (resMap.find(left - 1) != resMap.end())
            {
                expandWind = expand(s, resMap[left - 1], right);
                left = expandWind[0], right = expandWind[1];
            }
            resMap[right] = left;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }

    vector<int> expand(string s, int left, int right)
    {
        while (s[left - 1] == '(' && s[right + 1] == ')')
        {
            left--;
            right++;
        }
        return {left, right};
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = ")(()()()))";
    // solution.longestValidParentheses_2(s);
    cout << solution.longestValidParentheses_2(s) << endl;
    system("pause");
    return 0;
}
