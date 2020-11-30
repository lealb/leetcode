#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    unsigned long long mySqrt(unsigned long long x)
    {
        unsigned long long l = 0;
        unsigned long long r = x;
        unsigned long long m, ans = 0;

        if (x <= 1)
        {
            return x;
        }
        while (l <= r)
        {
            m = l + (r - l) >> 2;
            if (m * m == x)
            {
                return m;
            }
            else if (m * m < x)
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }
    int mySqrt_1(int x)
    {
        int low = 1, high = x;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (pow(mid, 2) == x)
                return mid;
            if (pow(mid, 2) < x)
                low = mid + 1;
            if (pow(mid, 2) > x)
                high = mid - 1;
        }
        return low - 1;
    }
    int mySqrt_2(int x)
    {
        int l = 0, r = x;
        while (l < r)
        {
            long long mid = l + r + 1ll >> 1; //此处的1ll很关键
            // mid <= x/mid
            if (mid * mid <= x)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }

    /**
     * @brief 	Time Limit Exceeded
     * 
     * @param x 
     * @return int 
     */
    int mySqrt_3(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        int x0 = x >> 2;
        int lastRoot = x0;
        while (1)
        {
            int curRoot = 1 / 2 * x0 + x / (2 * x0);
            if (abs(curRoot - lastRoot) < 0.1)
            {
                return int(curRoot);
            }
            lastRoot = curRoot;
            x0 = curRoot;
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.mySqrt_3(3) << endl;
    system("pause");
    return 0;
}
