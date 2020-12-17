#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * @brief 
 * 1 <= nums.length <= 104
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in non-decreasing order.
 */
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int size = nums.size();
        int left = 0, right = size - 1;
        vector<int> ans(size);
        while (left <= right)
        {
            if (abs(nums[left]) < abs(nums[right]))
            {
                ans[--size] = nums[right] * nums[right];
                --right;
            }
            else
            {
                ans[--size] = nums[left] * nums[left];
                ++left;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> ans = solution.sortedSquares(nums);
    for (auto &v : ans)
    {
        cout << v << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
