#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int numsLength = nums.size();
        if (nums.empty() || nums.size() <= 3)
        {
            return {};
        }
        for (int i = 0; i < numsLength; i++)
        {
            for (int j = i + 1; j < numsLength; j++)
            {
                for (int k = j + 1; k < numsLength; k++)
                {
                    if (0 == nums[i] + nums[j] + nums[k])
                    {
                        res.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return res;
    }
    vector<vector<int>> threeSum_1(vector<int> &nums)
    {
        int numsLength = nums.size();
        vector<vector<int>> res;
        if (nums.empty() || numsLength < 3)
        {
            return res;
        }
        // 0- sorted
        sort(nums.begin(), nums.end());
        // first fix an element ans search for a pair such that these 3
        // end as numsLength-2
        for (int i = 0; i < numsLength - 2; i++)
        {
            if (nums[i] > 0)
                break;
            // if it is equal to last element, this will result into dupilcacy
            // so we will skip this
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // use left and right point move
            int left = i + 1, right = numsLength - 1;
            // now we are left with a typical binary search problem
            while (left < right)
            {
                if (0 == nums[i] + nums[left] + nums[right])
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    // there might be other triplets including a
                    // so we will increase j till num[j] == b
                    // & decrease k till num[k] == c to avoid duplicacy
                    while (left < right && nums[left] == nums[++left])
                        ;
                    while (right > left && nums[right] == nums[--right])
                        ;
                }
                else if (0 < nums[i] + nums[left] + nums[right])
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return res;
    }

    /**
     * Runtime: 64 ms O(n^2)
     */
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        //two pointer
        int numsLength = nums.size();
        vector<vector<int>> res;
        if (nums.empty() || numsLength < 3)
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < numsLength; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int start = i + 1;
            int end = numsLength - 1;
            int target = -1 * nums[i];
            while (start < end)
            {
                int sum = nums[start] + nums[end];
                if (sum == target)
                {
                    res.push_back({nums[i], nums[start], nums[end]});
                    int temp1 = nums[start];
                    int temp2 = nums[end];
                    while (start < end && nums[start] == temp1)
                        start++;
                    while (start < end && nums[end] == temp2)
                        end--;
                }
                else if (sum > target)
                    end--;
                else
                    start++;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution solution = Solution();
    vector<vector<int>> res = solution.threeSum_1(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        for (auto r : res[i])
        {
            cout << r << " ";
        }
        cout << endl;
    }

    return 0;
}
