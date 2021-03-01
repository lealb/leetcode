#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n < 1)
        {
            return false;
        }
        while (n % 4 == 0)
        {
            n /= 4;
        }
        return n == 1;
    }
    bool isPowerOfFour_1(int n)
    {
        return n > 0 && !(n & (n - 1)) && (n & 1431655765);
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.isPowerOfFour(12) << endl;
    system("pause");
    return 0;
}
