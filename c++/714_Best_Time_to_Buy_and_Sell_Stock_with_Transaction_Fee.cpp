#include <iostream>
#include <vector>

using namespace std;
/**
 * 0 < prices.length <= 50000.
 * 0 < prices[i] < 50000.
 * 0 <= fee < 50000.
*/
class Solution
{
public:
    /**
     * Approach #1: Dynamic Programming
     */
    int maxProfit_0(vector<int> &prices, int fee)
    {
        // 表示第i天未购买股票，所得到的最大利润
        // 表示第i天购买股票，所得的最大利润，默认第一天购买股票
        int cash = 0, hold = -prices[0];
        int size = prices.size();
        for (int i = 1; i < size; i++)
        {
            // 更新最大利润,未购买，但可卖出
            cash = max(cash, hold + prices[i] - fee);
            // 购买股票
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    cout << solution.maxProfit_0(prices, 2) << endl;
    system("pause");
    return 0;
}
