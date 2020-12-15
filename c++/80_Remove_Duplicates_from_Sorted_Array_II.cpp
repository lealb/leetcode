#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief 
 * 0 <= nums.length <= 3 * 104
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in ascending order.
 * Space Must be O(1)
 */
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int size = nums.size();
        int low = 0;
        int i = 0;
        while (i < size)
        {
            int tmp = nums[i];
            nums[low++] = nums[i++];
            if (i == size || nums[i] != tmp)
                continue;
            int j = i + 1;
            // same
            while (j < size && nums[j] == tmp)
            {
                j++;
            }
            nums[low++] = tmp;
            i = j;
        }
        return low;
    }
    int removeDuplicates_1(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
        {
            return n;
        }
        for (auto it = nums.begin() + 2; it != nums.end();)
        {
            if (*it == *(it - 1) && *(it - 1) == *(it - 2))
            {
                nums.erase(it);
            }
            else
            {
                it++;
            }
        }
        return nums.size();
    }
    int removeDuplicates_2(vector<int> &nums)
    {
        int j = 0;
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[++j] = nums[i];
                cnt = 0;
            }
            else if (cnt < 1)
            {
                nums[++j] = nums[i];
                cnt++;
            }
        }
        for (int i = nums.size() - 1; i > j; i--)
        {
            nums.pop_back();
        }
        return nums.size();
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << solution.removeDuplicates(nums) << endl;
    system("pause");
    return 0;
}
