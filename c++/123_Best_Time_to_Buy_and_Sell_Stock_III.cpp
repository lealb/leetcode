#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    /**
     * 1st: x-p1
     * 2nd: y-(x-p1)
     */
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        if (!size)
            return 0;
        int buy1 = INT_MAX, profit1 = INT_MIN;
        int buy2 = INT_MAX, profit2 = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            buy1 = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2 = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
    int maxProfit_1(vector<int> &prices)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int size = prices.size();
        int left[size], right[size];
        left[0] = 0, right[size - 1] = 0;
        int leftProfit = prices[0], rightProfit = prices[size - 1];
        // for (int i = 1, j = size - 2; i < size && j >= 0; i++, j--)
        // {
        //     leftProfit = min(leftProfit, prices[i]);
        //     left[i] = max(left[i - 1], prices[i] - leftProfit);
        //     rightProfit = max(rightProfit, prices[j]);
        //     right[j] = max(right[j + 1], rightProfit - prices[j]);
        // }
        for (int i = 1; i < size; i++)
        {
            leftProfit = min(leftProfit, prices[i]);
            left[i] = max(left[i - 1], prices[i] - leftProfit);
        }
        for (int i = size - 2; i >= 0; i--)
        {
            rightProfit = max(rightProfit, prices[i]);
            right[i] = max(right[i + 1], rightProfit - prices[i]);
        }
        int ans = 0;
        for (int i = 0; i < size; i++)
        {
            ans = max(ans, left[i] + right[i]);
        }
        return ans;
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
