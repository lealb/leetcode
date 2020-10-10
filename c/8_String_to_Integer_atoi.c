#include <stdio.h>
#include <limits.h>
int myAtoi(char *str)
{
    char *iter = str;
    while (*iter == ' ')
    {
        iter++;
    }
    char sign = 1;
    if (*iter == '-' || *iter == '+')
    {
        sign *= *iter == '-' ? -1 : 1;
        iter++;
    }
    int integer = 0;
    while (*iter >= '0' && *iter <= '9')
    {
        if ((integer == INT_MAX / 10 && *iter - '0' > INT_MAX % 10) || integer > INT_MAX / 10)
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        integer = integer * 10 + (*iter - '0');
        iter++;
    }
    return integer * sign;
}

int main(int argc, char const *argv[])
{
    char *testStr[7] = {"42", "   -43", "4193 with words", "words and 987", "-91283472332", "  -4.53  ", "21474836460"};
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", myAtoi(testStr[i]));
    }
    return 0;
}
