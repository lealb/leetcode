#include <iostream>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int haystackLen = haystack.length();
        if ("" == needle)
        {
            return 0;
        }
        int needleLen = needle.length();
        // middleLen>haystackLen
        int j = 0;
        for (int i = 0; i < haystackLen; i++)
        {
            if (haystack[i] == needle[j])
            {
                j++;
                if (j == needleLen)
                {
                    return i - j + 1;
                }
            }
            else
            {
                i -= j;
                j = 0;
            }
        }
        return -1;
    }
    /**
     *  use find
     */
    int strStr_1(string haystack, string needle)
    {
        return haystack.find(needle);
    }
    int strStr_2(string haystack, string needle)
    {
        if (needle.size() == 0)
        {
            return 0;
        }
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i < n - m + 1; i++)
        {
            int j = 0;
            while (haystack[i + j] == needle[j])
            {
                j++;
                if (j == m)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};
int main(int argc, char const *argv[])
{
    string haystack = "mississippi", needle = "issip";
    Solution solution;
    cout << solution.strStr_2(haystack, needle);
    return 0;
}
