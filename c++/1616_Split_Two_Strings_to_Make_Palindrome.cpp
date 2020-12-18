#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j])
            ++i, --j;
        return i >= j;
    }
    /**
     * @brief Brute-force
     * O(N^2)
     * Time Limit Exceeded
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    bool checkPalindromeFormation(string a, string b)
    {
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if ((isPalindrome(a.substr(0, i) + b.substr(i))) || (isPalindrome(b.substr(0, i) + a.substr(i))))
            {
                return true;
            }
        }
        return false;
    }
    int findend(string &a)
    {
        int s = (a.size() - 1) / 2, e = a.size() / 2;
        if (a[s] != a[e])
        {
            s = e;
        }
        else
        {
            while (s - 1 >= 0 && a[s - 1] == a[e + 1])
            {
                s--, e++;
            }
        }
        return s;
    }
    bool checkPalindromeFormation_1(string a, string b)
    {
        int s = min(findend(a), findend(b));
        int flaga = 1, flagb = 1;
        for (int i = 0, j = a.size() - 1; i < s; ++i, --j)
        {
            if (a[i] != b[j])
                flaga = 0;
            if (b[i] != a[j])
                flagb = 0;
            if (!flaga && !flagb)
                return false;
        }
        return true;
    }
    /**
     * @brief Two Points
     * Time:O(n)
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    bool checkPalindromeFormation_2(const string &a, const string &b)
    {
        ios::sync_with_stdio(false);
        /* since a.size() == b.size() */
        const size_t size = a.size();
        if (2 > size)
        {
            return true;
        }
        return PrefixSuffix(a, b) || PrefixSuffix(b, a);
    }

    bool PrefixSuffix(const string &a, const string &b)
    {
        size_t low = 0;
        size_t high = a.size() - 1;
        while (low < high && a[low] == b[high])
        {
            ++low;
            --high;
        }
        return Palin(a, low, high) || Palin(b, low, high);
    }

    bool Palin(const string &s, size_t low, size_t high)
    {
        while (low < high)
        {
            if (s[low] != s[high])
            {
                return false;
            }
            ++low;
            --high;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string a = "ulacfd", b = "jizalu";
    cout << solution.checkPalindromeFormation_2(a, b) << endl;
    system("pause");
    return 0;
}
