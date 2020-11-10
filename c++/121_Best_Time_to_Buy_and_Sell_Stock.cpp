#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    /**
     * Approach 1: Brute Force
     * Time complexity : O(n^2)
     *  Loop runs n(n−1)/2 times.
     * Space complexity : O(1) 
     * Only two variables - maxprofit and profit are used.
     */
    int maxProfit(vector<int> &prices)
    {
        int maxprofit = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                int profit = prices[j] - prices[i];
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }
        return maxprofit;
    }

    /**
     * Approach 2: One Pass
     * Time complexity : O(n). Only a single pass is needed.
     * Space complexity : O(1). Only two variables are used.
     */
    int maxProfit_1(vector<int> &prices)
    {
        int size = prices.size(), minPrice = INT_MAX, maxProfit = 0;
        for (int i = 0; i < size; i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            else if (prices[i] - minPrice > maxProfit)
            {
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
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
