#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief 
 * S will consist of lowercase letters and have length in range [1, 500].
 */
class Solution
{
public:
    string reorganizeString(string s)
    {
        int mostFreq = 0, i = 0;
        int size = s.length();
        vector<char> countLetters(26, 0);
        for (char c : s)
        {
            if (++countLetters[c - 'a'] > countLetters[mostFreq])
            {
                mostFreq = c - 'a';
            }
        }
        if (2 * countLetters[mostFreq] - 1 > size)
        {
            return "";
        }
        while (countLetters[mostFreq])
        {
            s[i] = 'a' + mostFreq;
            countLetters[mostFreq]--;
            i += 2;
        }
        for (int j = 0; j < 26; j++)
        {
            while (countLetters[j])
            {
                if (i >= size)
                    i = 1;
                s[i] = 'a' + j;
                countLetters[j]--;
                i += 2;
            }
        }
        return s;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "aabccbb";
    cout << solution.reorganizeString(s) << endl;
    system("pause");
    return 0;
}
