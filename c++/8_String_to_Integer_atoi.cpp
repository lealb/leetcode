/**
 * 
 * Only the space character ' ' is considered a whitespace character.
 * Assume we are dealing with an environment that could only store integers within the 32-bit signed
 *  integer range: [−231,  231 − 1]. 
 * If the numerical value is out of the range of representable values,
 *  INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 * 须知：
 * 1. 字符转换
 *   result * 10 + (str[i] - '0') 【ASCII】
 * 2. 越界判
 *  result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)
*/
#include <iostream>
using namespace std;
class Solution
{
public:
    /**
     * 0 <= s.length <= 200
     * s consists of English letters (lower-case and upper-case), digits, ' ', '+', '-' and '.'.
     */
    int myAtoi(string str)
    {
        int strLength = str.length();
        if (strLength == 0)
            return 0;
        int i = 0;
        //Discard whitespaces in the beginning
        while (i < strLength && str[i] == ' ')
        {
            i++;
        }
        int sign = 1;
        // Check if optional sign if it exists
        if (i < strLength && (str[i] == '+' || str[i] == '-'))
        {
            sign = (str[i++] == '-') ? -1 : 1;
        }
        int result = 0;
        // Build the result and check for overflow/underflow condition
        while (i < strLength && str[i] >= '0' && str[i] <= '9')
        {
            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + (str[i++] - '0');
        }
        return result * sign;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution = Solution();
    string testStr[6] = {"42", "   -42", "4193 with words", "words and 987", "-91283472332","  -4.53  "};
    for (int i = 0; i < 6; i++)
    {
        cout << solution.myAtoi(testStr[i]) << " ";
    }
    return 0;
}
