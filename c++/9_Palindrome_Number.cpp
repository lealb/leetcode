#include <iostream>
#include<deque>
using namespace std;
bool isPalindrome_0(int x)
{
    // Special cases:
    // As discussed above, when x < 0, x is not a palindrome.
    // Also if the last digit of the number is 0, in order to be a palindrome,
    // the first digit of the number also needs to be 0.
    // Only 0 satisfy this property.
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber)
    {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
    // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
    // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
    return x == revertedNumber || x == revertedNumber / 10;
}
//Runtime: 28 ms Memory Usage: 6 MB
bool isPalindrome_1(int x)
{
    if (x >= 0)
    {
        long long int y = 0;
        int x0 = x;
        while (x != 0)
        {
            y = y * 10 + x % 10;
            if (y > INT_MAX)
            {
                return false;
            }
            x /= 10;
        }
        return x0 == y;
    }
    return false;
}
bool isPalindrome_2(int x)
{
    if (x < 0)
        return false;
    deque<int> dq;
    while (x > 0)
    {
        dq.push_back(x % 10);
        x /= 10;
    }
    while (!dq.empty())
    {
        if (dq.front() != dq.back())
            return false;
        dq.pop_front();
        if (dq.size() <= 1)
            return true;
        dq.pop_back();
        if (dq.size() <= 1)
            return true;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    cout << isPalindrome_1(1534236469) << endl;
    return 0;
}
