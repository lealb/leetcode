#include <iostream>
#include <vector>
#include <map>
using namespace std;
/**
 * 2 <= nums.length <= 3 * 104
 * -1000 <= nums[i] <= 1000
 * nums is sorted in increasing order.
 * -1000 <= target <= 1000
 */
class Solution
{
public:
    /**
     * two points
     */
    vector<int> twoSum_0(vector<int> &numbers, int target)
    {
        int i = 0, j = numbers.size() - 1;
        while (i < j)
        {
            int sum = numbers[i] + numbers[j];
            if (sum < target)
            {
                i++;
            }
            else if (sum > target)
            {
                j--;
            }
            else
            {
                return {i + 1, j + 1};
            }
        }
        return {-1, -1};
    }
    vector<int> twoSum_1(vector<int> &nums, int target)
    {
        int N = nums.size();
        for (int i = 0; i < N - 1; i++)
        {
            int low = i + 1, high = N;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                if (nums[mid] == target - nums[i])
                    return {i + 1, mid + 1};
                else if (nums[mid] >= target - nums[i])
                    high = mid;
                else
                    low = mid + 1;
            }
            if (low != nums.size() && nums[low] == target - nums[i])
                return {i + 1, low + 1};
        }
        return {-1, -1};
    }

    vector<int> twoSum_2(vector<int> &numbers, int target)
    {
        // Map
        map<int, int> mp;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (mp.find(target - numbers[i]) != mp.end())
            {
                return {mp[target - numbers[i]] + 1, i + 1};
            }
            mp[numbers[i]] = i;
        }
        return {};
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {2, 3, 4};
    vector<int> res = solution.twoSum_0(nums, 6);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
