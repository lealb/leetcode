#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    /**
     * Approach #2: Construction
     */
    vector<int> constructArray_0(int n, int k)
    {
        vector<int> ans(n);
        int c = 0;
        for (int v = 1; v < n - k; v++)
        {
            ans[c++] = v;
        }
        for (int i = 0; i <= k; i++)
        {
            ans[c++] = (i % 2 == 0) ? (n - k + i / 2) : (n - i / 2);
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = solution.constructArray_0(4,3);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
