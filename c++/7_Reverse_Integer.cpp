#include <iostream>
#include <math.h>
#include <vector>
#include<limits.h>
using namespace std;
//7. [−2^31,  2^31 − 1].
int reverse(int x)
{
    vector<int> res{0};
    while (x)
    {
        res.push_back(x % 10);
        x /= 10;
    }
    int total = res.size();
    long long int result = 0;
    for (int i = 0; i < total; i++)
    {
        result += pow(10, total - i - 1) * res[i];
    }
    cout << result << endl;
    return (result > pow(-2, 31) || result < pow(2, 31) - 1) ? result : 0;
}
int reverse_array(int x)
{
    int res = 0;
    while (x)
    {
        int tmp = x % 10;
        cout << res << " " << tmp << endl;
        if (res > 214748364 || (res == 214748364 && tmp > 7))
        {
            return 0;
        }
        if (res < -214748364 || (res == -214748364 && tmp < -8))
        {
            return 0;
        }
        res = res * 10 + tmp;
        x /= 10;
    }
    return res;
}
int reverse2(int x)
{
    long long int ans = 0;
    while (x != 0)
    {
        ans = ans * 10 + x % 10;
        x = x / 10;
    }
    return (ans < INT_MIN || ans > INT_MAX) ? 0 : ans;
}
int main(int argc, char const *argv[])
{
    vector<int> res{0};
    int x = 1534236469; // runtime 1534236469
    cout << reverse(x) << endl;
    return 0;
}
