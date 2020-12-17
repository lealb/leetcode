#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool findSubString(string s, string sub)
    {
        int lenS = s.length(), lenSub = sub.length();
        int i = 0, j = 0;
        while (i < lenS && j < lenSub)
        {
            if (sub[j] == s[i])
            {
                ++j;
            }
            ++i;
        }
        return j == lenSub;
    }
    string findLongestWord(string s, vector<string> &d)
    {
        int size = d.size();
        // sorted
        sort(d.begin(), d.end());
        // sort(d.begin(), d.end(), [](string &a, string &b) {
        //     return (a.size() > b.size() || (a.size() == b.size() && a < b));
        // });
        string maxStr = "";
        for (int i = 0; i < size; ++i)
        {
            string currStr = "";
            if (findSubString(s, d[i]))
            {
                currStr = d[i];
            }
            maxStr = currStr.length() > maxStr.length() ? currStr : maxStr;
        }
        return maxStr;
    }
    string findLongestWord_1(string s, vector<string> &d)
    {
        string res = "";
        for (auto &w : d) //遍历d中的每一个字符串w
        {
            //如果w的长度小于定义的字符串res长度，或者长度相等且w的初始字母大于res的初始字母，就跳过
            if (w.length() < res.length() || (w.length() == res.length() && w > res))
            {
                continue;
            }
            //遍历w和s字符串
            for (int i = 0, j = 0; i < w.length() && j < s.length(); i++, j++)
            {
                //如果j小于s的长度，且s中的第j个字母不等于w中的第i个字母，就把j加1
                //正常如果s的第j个字母等于w的第i个字母，就把i和j都加1，现在把j又加了一遍1，说明跳过当前字母看后面的s中字母有没有w[i]
                while (j < s.length() && s[j] != w[i])
                {
                    j++;
                }
                //如果遍历到w的最后一个字母，且j小于s的长度，说明w全部在s里面
                if (i == w.length() - 1 && j < s.length())
                {
                    res = w;
                }
            }
        }
        return res;
    }

    bool isSubstr(const string &s, const string &temp)
    {
        int i = 0, j = 0;
        while (i < s.size() && j < temp.size())
        {
            if (s[i] == temp[j])
                ++j;
            ++i;
        }
        return (j == temp.size());
    }
    string findLongestWord_2(string s, vector<string> &d)
    {
        ios::sync_with_stdio(false);
        sort(d.begin(), d.end(), [](string &a, string &b) {
            return (a.size() > b.size() || (a.size() == b.size() && a < b));
        });
        for (int i = 0; i < d.size(); ++i)
        {
            if (isSubstr(s, d[i]))
                return d[i];
        }
        return "";
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "abpcplea";
    vector<string> d = {"ale", "apple", "monkey", "plea"};
    cout << solution.findLongestWord_1(s, d) << endl;
    // cout << solution.findSubString("abpcplea", "monkey") << endl;
    system("pause");
    return 0;
}
