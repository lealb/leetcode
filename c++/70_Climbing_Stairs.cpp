#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    /**
     * Time Limit Exceeded
     */
    int climbStairs(int n)
    {
        if (2 >= n)
        {
            return n;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
    int climbStairs_1(int n)
    {
        if (2 >= n)
        {
            return n;
        }
        vector<int> cache(n + 1);
        cache[1] = 1;
        cache[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
        return cache[n];
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.climbStairs(10) << endl;
    system("pause");
    return 0;
}
