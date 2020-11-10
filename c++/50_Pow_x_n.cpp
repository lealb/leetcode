#include <iostream>
using namespace std;
class Solution
{
public:
    /**
     *Time Limit Exceeded 直接使用 for 
     */
public:
    double myPow(double x, int n)
    {
        return num_power(x, n);
    }
    /**
     * equal 
     */
    double myPow_1(double x, int n)
    {
        if (equal(x, 0.0))
            return 0;
        if (equal(x, 1.0) || n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;
        // 二分
        double ans = myPow_1(x, n / 2);
        ans *= ans;
        if (n % 2)
        {
            ans *= n > 0 ? x : 1 / x;
        }
        return ans;
    }
    bool equal(double num1, double num2)
    {
        //(num1 - num2) > -1e-6 && (num1 - num2) < 1e-6
        return abs(num1 - num2) < 1e-6;
    }

private:
    double num_power(double y, long i)
    {
        if (i < 0)
        {
            return num_power(1 / y, -i);
        }
        else
        {
            switch (i)
            {
            case 0:
                return 1;
            case 1:
                return y;
            }
            if (i % 2 == 0)
            {
                return num_power(y * y, i / 2);
            }
            else
            {
                return y * num_power(y * y, (i - 1) / 2);
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution solution = Solution();
    cout << solution.myPow_1(2, 10) << endl;
    return 0;
}
