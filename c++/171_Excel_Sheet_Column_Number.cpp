#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
    int titleToNumber(string s)
    {
        int num = 0, sLen = s.length();
        for (int i = 0; i < sLen; i++)
        {
            num += (++s[i] - 'A') * pow(26, sLen - i - 1);
        }
        return num;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.titleToNumber("ZY") << endl;
    system("pause");
    return 0;
}
