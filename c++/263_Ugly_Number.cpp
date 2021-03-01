#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool isUgly(int num)
    {
        while (num > 1)
        {
            if (num % 2 == 0)
            {
                num /= 2;
                continue;
            }
            if (num % 3 == 0)
            {
                num /= 3;
                continue;
            }
            if (num % 5 == 0)
            {
                num /= 5;
                continue;
            }
            break;
        }
        return num == 1;
    }
    bool isUgly_1(int num)
    {
        if (num <= 0)
            return false;
        if (num == 1)
            return true;

        for (int i = 2; i <= 5; i++)
        {
            while (num % i == 0)
            {
                num = num / i;
            }
        }
        return num == 1;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.isUgly(12) << endl;
    system("pause");
    return 0;
}
