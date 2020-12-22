#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
class Solution
{
public:
    int uniqueLetterString(string s)
    {
        const long long int MOD = 1e9 + 7;
        int n = s.length();
        if (!n)
            return 0;

        int left[n];
        int right;
        vector<int> letterCounts(26, -1);
        for (int i = 0; i < n; i++)
        {
            left[i] = letterCounts[s[i] - 'A'];
            letterCounts[s[i] - 'A'] = i;
        }

        for (int i = 0; i < 26; i++)
        {
            letterCounts[i] = n;
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {

            right = letterCounts[s[i] - 'A'];
            letterCounts[s[i] - 'A'] = i;
            int x = i - left[i];
            int y = right - i;

            ans = (ans % MOD + (x % MOD * y % MOD) % MOD) % MOD;
        }

        return ans;
    }
    int uniqueLetterString_1(string s)
    {
        int index[26][2], res = 0, N = s.length(), mod = 1000000007;
        memset(index, -1, sizeof(int) * 52);
        for (int i = 0; i < N; ++i)
        {
            int c = s[i] - 'A';
            res = (res + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
            index[c][0] = index[c][1];
            index[c][1] = i;
        }
        for (int c = 0; c < 26; ++c)
        {
            res = (res + (N - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
        }
        return res;
    }
    int uniqueLetterString_2(string s)
    {
        /*
            includeTail[i] = includeTail[i-1] + res
                s           f      i
                0        +1     +1
            unique[i] = unique[i-1] + includeTail[i]
        */

        int tail = 0, unique = 0, c;
        pair<int, int> rightmost[26];
        memset(rightmost, -1, sizeof(rightmost));
        int N = s.size();
        for (int i = 0; i < N; ++i)
        {
            c = s[i] - 'A';
            tail += i + 1;
            if (rightmost[c].first != -1)
                tail -= 2 * (rightmost[c].first + 1);
            if (rightmost[c].second != -1)
                tail += rightmost[c].second + 1;

            rightmost[c].second = rightmost[c].first;
            rightmost[c].first = i;
            unique += tail;
        }
        return unique;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "ABC";
    cout << solution.uniqueLetterString_2(s) << endl;
    system("pause");
    return 0;
}
