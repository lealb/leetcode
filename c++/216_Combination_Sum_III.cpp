#include <iostream>
#include <vector>
using namespace std;
/**
 * 2 <= k <= 9
 * 1 <= n <= 60
 */
class Solution
{
public:
    void btrack(vector<vector<int>> &result, vector<int> &comb, int k, int n, int start)
    {
        if (n == 0 && k == 0)
        {
            result.push_back(comb);
            return;
        }
        for (int i = start; i < 10; i++)
        {
            comb.push_back(i);
            btrack(result, comb, k - 1, n - i, i + 1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> result;
        vector<int> comb;
        btrack(result, comb, k, n, 1);
        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> ans = solution.combinationSum3(3, 9);
    for (int i = 0; i < ans.size(); i++)
    {
        for (auto &num : ans[i])
        {
            cout << num << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
