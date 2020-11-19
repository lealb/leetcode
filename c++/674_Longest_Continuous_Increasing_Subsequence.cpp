#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int findLengthOfLCIS_0(vector<int> &nums)
    {
        int ans = 0, anchor = 0, size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            if (i > 0 && nums[i - 1] >= nums[i])
            {
                anchor = i;
            }
            ans = max(ans, i - anchor + 1);
        }
        return ans;
    }
    int findLengthOfLCIS_1(vector<int> &nums)
    {
        auto len = 0;
        auto maxlen = 0;
        for (auto i = 0; i != nums.size(); ++i)
        {
            if (i == 0 || !(nums[i - 1] < nums[i]))
            {
                len = 0;
            }
            maxlen = max(maxlen, ++len);
        }
        return maxlen;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 2, 2};
    cout << solution.findLengthOfLCIS_0(nums) << endl;
    system("pause");
    return 0;
}
