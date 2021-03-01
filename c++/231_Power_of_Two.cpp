#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        double res = log10(n) / log10(2);
        return res == (int)res;
    }
    bool isPowerOfTwo_1(int n)
    {

        if (n <= 0)
            return false;
        int i = 0;
        while (n && i < 2)
        {
            i += (n & 1);
            n /= 2;
        }
        return i == 1;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.isPowerOfTwo(10) << endl;
    system("pause");
    return 0;
}
