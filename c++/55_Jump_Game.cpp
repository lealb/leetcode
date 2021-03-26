#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int step = 1, size = nums.size();
        for (int i = size - 2; i >= 0; --i)
        {
            if (nums[i] >= step)
            {
                step = 1;
            }
            else
            {
                step++;
            }
            // 遍历完之后还需要大于1步才能到达即为false
            if (i == 0 && step > 1)
            {
                return false;
            }
        }
        return true;
    }
    bool canJump_1(vector<int> &nums)
    {
        if (nums.empty())
            return false;
        if (nums.size() == 1)
            return true;
        int jump_to = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (nums[i] >= jump_to - i)
            {
                jump_to = i;
                if (i == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << solution.canJump(nums) << endl;
    system("pause");
    return 0;
}
