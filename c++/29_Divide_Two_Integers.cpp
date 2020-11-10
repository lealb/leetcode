#include <iostream>
#include <math.h>
using namespace std;
/**
 * 判断溢出是个十分重要的问题
 * -2^31 <= dividend, divisor <= 2^31 - 1
 * divisor != 0
 */
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        bool flag = false;
        if (divisor == INT_MIN)
            return dividend == INT_MIN ? 1 : 0;
        if (dividend == INT_MIN)
        {
            if (divisor == 1)
                return INT_MIN;
            if (divisor == -1)
                return INT_MAX;
            return (((dividend < 0) ^ (divisor < 0)) ? -1 : 1) * (di(abs(dividend + abs(divisor)), abs(divisor)).second + 1);
        }

        if (dividend < 0)
        {
            dividend = -dividend;
            flag = !flag;
        }

        if (0 == dividend || dividend < divisor)
        {
            return 0;
        }
        int factor = 0;

        if (divisor < 0)
        {
            divisor = -divisor;
            flag = !flag;
        }

        while (dividend >= divisor)
        {
            dividend -= divisor;
            factor++;
        }
        return flag ? -factor : factor;
    }
    /**
     * The common idea applied here : a/b = e^(ln(a))/e^(ln(b)) = e^(ln(a) - ln(b))
     */
    int divide_1(int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;
        if (divisor == 0)
            return INT_MAX;
        long long res = double(exp(log(fabs(dividend)) - log(fabs(divisor))));
        if ((dividend < 0) ^ (divisor < 0))
            res = -res;
        if (res > INT_MAX)
            res = INT_MAX;
        return res;
    }

    int divide(int a, int b)
    {
        // Edge case: INT_MIN is the only value that cannot be sign-flipped with absolute
        // value.  This causes all kinds of problems in the general algorithm, so we explicitly
        // handle "divide by 1" identity cases.  In all other cases, we increment INT_MIN so it
        // will successfully sign-flip - and given how imprecise integer division is, we should
        // be able to get away with it.
        int absABoost = 0;

        if (a == INT_MIN)
        {
            if (b == -1)
            {
                return INT_MAX;
            }
            else if (b == 1)
            {
                return INT_MIN;
            }
            else
            {
                ++a;
                absABoost = 1;
            }
        }

        if (b == INT_MIN)
        {
            if (a == INT_MAX)
            {
                return 0; // min has a larger absolute value (by 1) than max.
            }
            else
            {
                ++b;
            }
        }

        // Fast reject: If we're dividing an integer by a larger number, quit and return 0 now.
        // The larger number will not fit inside the smaller number.
        if (a < 0 && b < a)
        {
            return 0;
        }
        else if (a > 0 && b > a)
        {
            return 0;
        }

        unsigned int absA = abs(a);
        unsigned int absB = abs(b);
        int quotient = 0;

        while (static_cast<int>(absA) >= static_cast<int>(absB))
        {
            int bit = 0;
            while (bit <= 29 && (absA + absABoost >= (absB << (bit + 1))))
            {
                ++bit;
            }
            quotient += (1 << bit);
            absA -= (absB << bit);
        }
        return (a > 0) == (b > 0) ? quotient : -quotient;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.divide_1(-1, 1) << endl;
    return 0;
}
