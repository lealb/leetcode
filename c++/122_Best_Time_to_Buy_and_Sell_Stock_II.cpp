#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int calculate(vector<int> &prices, int s)
    {
        int size = prices.size();
        if (s >= size)
            return 0;
        int max = 0;
        for (int start = s; start < size; start++)
        {
            int maxprofit = 0;
            for (int i = start + 1; i < size; i++)
            {
                if (prices[start] < prices[i])
                {
                    int profit = calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxprofit)
                        maxprofit = profit;
                }
            }
            if (maxprofit > max)
                max = maxprofit;
        }
        return max;
    }
    int maxProfit_0(vector<int> &prices)
    {
        return calculate(prices, 0);
    }

    /**
     * Approach 2: Peak Valley Approach
     * Time complexity : O(n). Single pass.
     * Space complexity : O(1). Constant space required.
     */
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size(), i = 0;
        int valley = prices[0], peak = prices[0];
        int maxprofit = 0;
        while (i < size - 1)
        {
            while (i < size - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < size - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << solution.maxProfit(prices) << endl;
    system("pause");
    return 0;
}
