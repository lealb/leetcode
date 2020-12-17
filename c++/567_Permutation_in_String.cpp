#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    /**
     * @brief  判断s1的排列是否是s2的子串
     * 1.找出s1的所有排列
     * 2.判断是否是子串
     * Time Limit Exceeded
     * Time complexity : O(n!)
     * Space complexity : O(n^2)
     * @param s1 
     * @param s2 
     * @return true 
     * @return false 
     */
    bool checkInclusion(string s1, string s2)
    {
        if (s1.empty())
        {
            return false;
        }
        sort(s1.begin(), s1.end());
        if (s2.find(s1) != string::npos)
        {
            return true;
        }
        while (next_permutation(s1.begin(), s1.end()))
        {
            if (s2.find(s1) != string::npos)
            {
                return true;
            }
        }
        return false;
    }

    vector<string> permutation(string s)
    {
        if (s.empty())
        {
            return {};
        }
        set<string> res; //去重
        backTrack(s, 0, res);
        return vector<string>(res.begin(), res.end());
    }
    /**
     * @brief 交换法
     * 
     * @param s 
     * @param begin 
     * @param res 
     */
    void backTrack(string s, int begin, set<string> &res)
    {
        if (begin == s.size())
        {
            res.insert(s);
            return;
        }
        for (int i = begin; i < s.size(); i++)
        {
            swap(s[i], s[begin]);         //做出选择
            backTrack(s, begin + 1, res); //进入下次决策树
            swap(s[i], s[begin]);         //撤回选择
        }
    }

    /**
     * @brief STL
     * 
     * @param s 
     * @return vector<string> 
     */
    vector<string> permutation_1(string s)
    {
        if (s.empty())
            return {};
        sort(s.begin(), s.end());
        vector<string> res;
        res.push_back(s);
        while (next_permutation(s.begin(), s.end()))
        {
            res.push_back(s);
        }
        return res;
    }

    /**
     * @brief 判断是否是子串
     * 
     * @param s 字符串
     * @param sub 子串
     * @return true 
     * @return false 
     */
    bool isSubString(string s, string sub)
    {
        return s.find(sub) != string::npos;
    }

    /**
     * @brief count leeters
     * Time:O(l1+26*l2*(l2-l1))
     * Space:O(1) 26
     * @param s1 
     * @param s2 
     * @return true 
     * @return false 
     */
    bool checkInclusion_1(string s1, string s2)
    {
        int l1 = s1.length(), l2 = s2.length();
        if (l1 > l2)
        {
            return false;
        }
        vector<int> s1StrMap(26, 0);
        for (auto &s : s1)
        {
            s1StrMap[s - 'a']++;
        }
        for (int i = 0; i <= l2 - l1; i++)
        {
            vector<int> s2StrMap(26, 0);
            for (int j = 0; j < l1; j++)
            {
                s2StrMap[s2[i + j] - 'a']++;
            }
            for (int k = 0; k < 26; k++)
            {
                if (s1StrMap[k] != s2StrMap[k])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    bool checkInclusion_2(string s1, string s2)
    {
        int size_s1 = s1.size();
        int size_s2 = s2.size();
        vector<int> a(26), b(26);
        for (char ch : s1)
        {
            a[ch - 'a']++;
        }
        for (int i = 0; i < size_s2; ++i)
        {
            b[s2[i] - 'a']++;
            if (i >= size_s1)
            {
                b[s2[i - size_s1] - 'a']--;
            }
            if (a == b)
            {
                return true;
            }
        }
        return false;
    }
    bool checkInclusion_3(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size(), cnt = n1, left = 0;
        vector<int> m(128);
        for (char c : s1)
            ++m[c];
        for (int right = 0; right < n2; ++right)
        {
            if (m[s2[right]]-- > 0)
                --cnt;
            while (cnt == 0)
            {
                if (right - left + 1 == n1)
                    return true;
                if (++m[s2[left++]] > 0)
                    ++cnt;
            }
        }
        return false;
    }
    bool checkPermutation(vector<int> &s1, vector<int> &s2)
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion_4(string s1, string s2)
    {
        if (s1.length() == 0 || s2.length() == 0)
        {
            return false;
        }
        if (s1.length() > s2.length())
            return false;
        vector<int> dict(26, 0);
        vector<int> temp(26, 0);
        int counter = 0;
        for (auto i : s1)
        {
            dict[i - 'a'] += 1;
            temp[s2[counter] - 'a'] += 1;
            counter++;
        }
        for (int i = 0; i < s2.length() - s1.length(); i++)
        {
            if (checkPermutation(dict, temp))
                return true;
            temp[s2.at(i) - 'a']--;
            temp[s2.at(i + s1.length()) - 'a']++;
        }
        if (checkPermutation(dict, temp))
            return true;
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> res = solution.permutation_1("abc");
    for (auto &i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << solution.isSubString("eidboaoo", "ab") << endl;
    cout << solution.checkInclusion_3("db", "eidboaoo") << endl;
    system("pause");
    return 0;
}
