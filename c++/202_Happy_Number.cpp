#include <iostream>
#include <vector>
#include <unordered_set>
#include <math.h>
using namespace std;
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> us{n};
        while (n != 1)
        {
            int sum = 0;
            while (n)
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            // if sum in set,是否处于循环中
            if (us.count(sum))
            {
                return false;
            }
            us.insert(sum);
            // replace
            n = sum;
        }
        return true;
    }

    bool isHappy_1(int n)
    {
        int sum;
        //1-6
        while (n > 6)
        {
            int num = n;
            sum = 0;
            while (num != 0)
            {
                sum += pow(num % 10, 2);
                num /= 10;
            }
            cout << sum << " ";
            n = sum;
        }
        return n == 1;
    }

    int bitSquareSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
    /**
     * @brief 快慢指针
     * 
     * @param n 
     * @return true 
     * @return false 
     */
    bool isHappy_2(int n)
    {
        int slow = n, fast = n;
        do
        {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        } while (slow != fast);

        return slow == 1;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.isHappy_1(15) << endl;
    system("pause");
    return 0;
}
