#include <iostream>
#include <vector>

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
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
