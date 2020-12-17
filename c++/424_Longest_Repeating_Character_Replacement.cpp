#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> letterCount(26, 0);
        int maxLen = 0, start = 0, end = 0, mostLetter = 0;
        int size = s.size();
        while (end < size)
        {
            letterCount[s[end] - 'A']++;
            mostLetter = max(mostLetter, letterCount[s[end] - 'A']);
            if (end - start + 1 - mostLetter > k)
            {
                letterCount[s[start] - 'A']--;
                start++;
            }
            maxLen = max(maxLen, end - start + 1);
            end++;
        }
        return maxLen;
    }
    int ans = 0;
    bool found(int len, string s, int k)
    {
        vector<int> cnt(26);
        for (int i = 0; i < len; ++i)
        {
            cnt[s[i] - 'A']++;
            if (cnt[s[i] - 'A'] + k >= len)
            {
                ans = len;
                return true;
            }
        }
        for (int i = len; s[i]; ++i)
        {
            cnt[s[i - len] - 'A']--;
            cnt[s[i] - 'A']++;
            if (cnt[s[i] - 'A'] + k >= len)
            {
                ans = len;
                return true;
            }
        }
        return false;
    }
    /**
     * @brief Binary Search | O(N*log(N-K)); O(1)
     * 
     * @param s 
     * @param k 
     * @return int 
     */
    int characterReplacement_1(string s, int k)
    {
        int l = k, r = s.size();
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            found(m, s, k) ? l = m + 1 : r = m - 1;
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
