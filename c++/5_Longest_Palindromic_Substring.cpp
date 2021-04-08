#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    /**
     * @brief 动态规划
     * 
     * 
     * @param s 
     * @return string 
     */
    string longestPalindrome_0(string s)
    {
        int n = s.size();
        // dp[left][right]标记从i到j是否是字串
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        // length表示判断的字串的长度
        // left表示字串的左边起始位置
        // right表示字串的右边起始位置
        for (int length = 0; length < n; length++)
        {
            for (int left = 0; left + length < n; left++)
            {
                int right = left + length;
                // 即字符串长度为1时，矩阵对角线
                if (length == 0)
                    dp[left][right] = 1;
                // 字符串长度为2的时候，只需判断两者是否相等
                else if (length == 1)
                    dp[left][right] = (s[left] == s[right]);
                else
                {
                    // 字符串长度大于等于3之后
                    // 其是否是回文串取决于当前left和right及更小一号的字符串
                    // 更新参考值为矩阵的左下方
                    dp[left][right] = (s[left] == s[right] && dp[left + 1][right - 1]);
                }
                // 如果当前left位置到right位置的字串能够构成回文串，并且现在长度+1后大于之前记忆中的子回文串的长度，那么更新回文串！这里也可以优化成记录起始位置和长度的两个int，返回时再截取
                if (dp[left][right] && (length + 1) > ans.size())
                {
                    ans = s.substr(left, length + 1);
                }
            }
        }
        return ans;
    }

    pair<int, int> expandAroundCenter(const string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
    /**
     * @brief 中心扩散法
     * 
     * @param s 
     * @return string 
     */
    string longestPalindrome_1(string s)
    {
        int bestLeft = 0, bestRight = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int left = i, right = i;
            // grow to the right
            while (right + 1 < s.length() && s[right + 1] == s[left])
            {
                right++;
            }
            // imagine "abbbbbbba": once we find the long string of b's, we
            // shouldn't search in it again
            i = right;

            // grow to the left and right
            while (left - 1 >= 0 && right + 1 < s.length() &&
                   s[left - 1] == s[right + 1])
            {
                right++;
                left--;
            }

            if (right - left + 1 > bestRight - bestLeft + 1)
            {
                bestLeft = left;
                bestRight = right;
            }
        }
        return s.substr(bestLeft, bestRight - bestLeft + 1);
    }
    string longestPalindrome(string s)
    {
        if (s.empty())
        {
            return "";
        }
        int sLen = s.size();
        if (sLen == 1)
        {
            return s;
        }
        int minStart = 0, maxLen = 1;
        for (int i = 0; i < sLen;)
        {
            if (sLen - i <= maxLen / 2)
            {
                break;
            }
            int j = i, k = i;
            while (k < sLen - 1 && s[k + 1] == s[k])
            {
                // Skip duplicate characters.
                ++k;
            }
            i = k + 1;
            while (k < sLen - 1 && j > 0 && s[k + 1] == s[j - 1])
            {
                ++k;
                --j;
            } // Expand.
            int newLen = k - j + 1;
            if (newLen > maxLen)
            {
                minStart = j;
                maxLen = newLen;
            }
        }
        return s.substr(minStart, maxLen);
    }
    /**
     * @brief Manacher 算法
     * 
     * @param s 
     * @return string 
     */
    string longestPalindrome_2(string s)
    {
        int start = 0, end = -1;
        string t = "#";
        for (char c : s)
        {
            t += c;
            t += '#';
        }
        t += '#';
        s = t;

        vector<int> arm_len;
        int right = -1, j = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            int cur_arm_len;
            if (right >= i)
            {
                int i_sym = j * 2 - i;
                int min_arm_len = min(arm_len[i_sym], right - i);
                cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
            }
            else
            {
                cur_arm_len = expand(s, i, i);
            }
            arm_len.push_back(cur_arm_len);
            if (i + cur_arm_len > right)
            {
                j = i;
                right = i + cur_arm_len;
            }
            if (cur_arm_len * 2 + 1 > end - start)
            {
                start = i - cur_arm_len;
                end = i + cur_arm_len;
            }
        }

        string ans;
        for (int i = start; i <= end; ++i)
        {
            if (s[i] != '#')
            {
                ans += s[i];
            }
        }
        return ans;
    }
    int expand(const string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return (right - left - 2) / 2;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "babad";
    cout << solution.longestPalindrome(s) << endl;
    system("pause");
    return 0;
}
