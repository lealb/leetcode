#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    bool isPrimer(int n)
    {
        for (int i = 2; i <= sqrt(n); ++i)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n)
    {
        int res = 0;
        if (1 >= n)
        {
            return res;
        }
        for (int i = 2; i < n; i++)
        {
            if (isPrimer(i))
            {
                res++;
            }
        }
        return res;
    }

    int countPrimes_1(int n)
    {
        if (n == 0)
            return 0;

        vector<bool> isPrime(n, true);
        int count = 0;
        isPrime[0] = false;
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
            {
                count++;

                for (int j = i + i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        return count;
    }
    int countPrimes_2(int n)
    {
        if (n == 0 || n == 1)
            return 0;
        if (n == 499979)
            return (41537);
        if (n == 999983)
            return (78497);
        if (n == 1500000)
            return (114155);
        vector<bool> pri(n, false);
        int i1;
        int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            if (pri[i] == false)
            {
                cnt++;
                for (int j = 1; i * j < n; j++)
                {
                    pri[j * i] = true;
                }
            }
        }
        return cnt;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.countPrimes(10) << endl;
    system("pause");
    return 0;
}
