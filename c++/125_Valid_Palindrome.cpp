#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int size = s.size();
        string newS = "";
        for (int i = 0; i < size; i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] <= '9' && s[i] >= '0'))
            {
                newS += s[i];
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                //+=32
                newS += s[i] - 'A' + 'a';
            }
            else
            {
                continue;
            }
        }
        // cout << newS << endl;
        int left = 0, right = newS.size() - 1;
        while (left <= right)
        {
            if (newS[left++] != newS[right--])
            {
                return false;
            }
        }
        return true;
    }
    bool isalphanumeric(char c)
    {
        return (c >= 'A' && c <= 'Z') ||
               (c >= 'a' && c <= 'z') ||
               (c >= '0' && c <= '9');
    }
    bool isUpper(char c)
    {
        return (c >= 'A' && c <= 'Z');
    }
    bool isPalindrome_1(string s)
    {
        int len = s.length();
        int lower = 0;
        int upper = len - 1;
        while (lower <= upper)
        {
            char lc, uc;
            if (isalphanumeric(s[lower]))
            {
                if (isUpper(s[lower]))
                    lc = s[lower] - 'A' + 'a';
                else
                    lc = s[lower];
            }
            else
            {
                lower++;
                continue;
            }
            if (isalphanumeric(s[upper]))
            {
                if (isUpper(s[upper]))
                    uc = s[upper] - 'A' + 'a';
                else
                    uc = s[upper];
            }
            else
            {
                upper--;
                continue;
            }
            if (lc != uc)
                return false;
            if (lower > upper)
                return true;
            lower++;
            upper--;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "A man, a plan, a canal: Panama";
    cout << solution.isPalindrome("0P") << endl;
    system("pause");
    return 0;
}
