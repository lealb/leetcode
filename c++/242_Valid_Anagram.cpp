#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    bool isAnagram_1(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        vector<int> counts(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (counts[i])
            {
                return false;
            }
        }
        // cout << accumulate(counts.begin(), counts.end(), 0) << endl;
        // return accumulate(counts.begin(), counts.end(), 0) == 0;
        return true;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "s", t = "t";
    cout << solution.isAnagram_1(s, t) << endl;
    system("pause");
    return 0;
}
