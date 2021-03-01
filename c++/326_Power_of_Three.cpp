#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        return n > 0 && 1162261467 % n == 0;
    }
    bool isPowerOfThree_1(int n)
    {
        if (n < 1)
        {
            return false;
        }
        while (n % 3 == 0)
        {
            n /= 3;
        }
        return n == 1;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.isPowerOfThree(27) << endl;
    system("pause");
    return 0;
}
