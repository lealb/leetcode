#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        vector<string> v;
        string temp = "";
        int sLen = s.length();
        for (int i = 0; i < sLen; i++)
        {
            if (s[i] != ' ')
            {
                temp += s[i];
            }
            if (s[i] == ' ' || i == sLen - 1)
            {
                v.push_back(temp);
                temp.clear();
            }
        }
        int parrernLen = pattern.length();
        if (parrernLen != v.size())
        {
            return false;
        }
        for (int i = 0; i < parrernLen; i++)
        {
            if (m1.find(pattern[i]) == m1.end())
            {
                m1[pattern[i]] = v[i];
            }
            else
            {
                if (m1[pattern[i]] != v[i])
                {
                    return false;
                }
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (m2.find(v[i]) == m2.end())
            {
                m2[v[i]] = pattern[i];
            }
            else
            {
                if (m2[v[i]] != pattern[i])
                    return false;
            }
        }
        return true;
    }
    bool wordPattern_1(string pattern, string s)
    {
        unordered_map<string, char> mp;
        unordered_map<char, string> mp2;
        int j = 0;
        string t = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (mp[t] && mp[t] != pattern[j])
                {
                    return false;
                }
                if (mp2[pattern[j]].size() && mp2[pattern[j]] != t)
                {
                    return false;
                }
                mp[t] = pattern[j];
                mp2[pattern[j]] = t;
                j++;
                t = "";
            }
            else
            {
                t += s[i];
            }
        }
        if (mp[t] && mp[t] != pattern[j])
        {
            return false;
        }
        if (mp2[pattern[j]].size() && mp2[pattern[j]] != t)
        {
            return false;
        }
        mp[t] = pattern[j];
        mp2[pattern[j]] = t;
        j++;
        return j == pattern.size();
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
