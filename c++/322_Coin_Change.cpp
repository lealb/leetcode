#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int coin : coins)
        {
            for (int i = coin; i <= amount; ++i)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << solution.coinChange(coins, amount) << endl;
    system("pause");
    return 0;
}
