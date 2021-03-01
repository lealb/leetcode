#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int addDigits(int num)
    {
        int res = 0;
        while (num)
        {
            res += num % 10;
            num /= 10;
        }
        return res < 10 ? res : addDigits(res);
    }

    int addDigits_1(int num)
    {

        while (num / 10)
            num = sumDigits(num);
        return num;
    }

    int sumDigits(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.addDigits(999999) << endl;
    system("pause");
    return 0;
}
