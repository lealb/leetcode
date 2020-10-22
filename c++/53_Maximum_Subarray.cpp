#include <iostream>
#include <vector>

using namespace std;
/**
 * 1 <= nums.length <= 2 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 */
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int size = nums.size(), sum = nums[0], result = nums[0];
        if (1 == size)
        {
            return result;
        }
        for (int i = 1; i < size; i++)
        {
            sum = max(nums[i], sum + nums[i]);
            result = sum > result ? sum : result;
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << solution.maxSubArray(nums) << endl;
    system("pause");
    return 0;
}
