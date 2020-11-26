#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool isNumber(string s)
    {
        if (s.length() == 0)
            return false;
        int i = 0, n = s.length() - 1;
        bool e = false, dot = false, digit = false;

        while (i < s.length() && s[i] == ' ')
            i++; // removing white spaces
        while (n >= 0 && s[n] == ' ')
            n--;
        if (s[i] == '+' || s[i] == '-')
            i++;
        if (i > n)
            return false;
        for (; i <= n; i++)
        {
            if (isdigit(s[i]))
            {
                digit = true; // atleast one digit
                continue;
            }
            else if (s[i] == 'e' && digit && i != n && !e)
            { //atmost one exponent with atleast one digit
                e = true;
                if (s[i + 1] == '+' || s[i + 1] == '-') // sign is only allowed after 'e'
                    if (i == n - 1)
                        return false;
                    else
                        i++;
            }
            else if (s[i] == '.' && !dot && !e)
                dot = true; // atmost one dot
            else
                return false;
        }
        return digit;
    }
    bool isNumber_1(string s)
    {
        char *begin = &s[0];

        // Trim left whitespaces
        while (isblank(*begin))
            begin++;

        if (*begin == 0)
            return false;

        strtod(begin, &begin);

        // Trim right whitespaces
        while (isblank(*begin))
            begin++;
        return *begin == 0;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
