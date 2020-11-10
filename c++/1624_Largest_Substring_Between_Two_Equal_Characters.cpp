#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * 1 <= s.length <= 300
 * s contains only lowercase English letters.
 */
class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        vector<int> mp(26, 0);
        int maxi = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i] - 'a'])
                maxi = max(maxi, (i - mp[s[i] - 'a']));
            else
                mp[s[i] - 'a'] = i + 1;
        }
        return maxi;
    }

    int maxLengthBetweenEqualCharacters_1(string s)
    {
        int maxLen = -1;
        int n = s.size();
        unordered_map<char, int> seen;
        for (int i = 0; i < n; ++i)
        {
            char curr = s[i];

            if (seen.find(curr) != seen.end())
                maxLen = max(maxLen, i - seen[curr] - 1);
            else
                seen[curr] = i;
        }
        return maxLen;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> testStr = {"aa", "abca", "cbzxy", "cabbac"};
    for (int i = 0; i < testStr.size(); i++)
    {
        cout << solution.maxLengthBetweenEqualCharacters(testStr[i]) << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
