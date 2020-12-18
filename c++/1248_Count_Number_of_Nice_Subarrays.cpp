#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * @brief 
 * 1 <= nums.length <= 50000
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
 * 
 */
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int res = 0, sum = 0, n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; ++i)
        {
            mpp[sum]++;
            sum += nums[i] & 1;
            res += mpp[sum - k];
        }
        return res;
    }
    /**
     * @brief Two Points
     * Time:O(n)
     * Space:O(n)
     * @param nums 
     * @param k 
     * @return int 
     */
    int numberOfSubarrays_1(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int> odds;
        odds.push_back(-1);
        // get odds poetion index
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] & 1)
            {
                odds.push_back(i);
            }
        }
        // -1,...,n
        odds.push_back(nums.size());
        // no odd nums
        if (odds.size() - 2 < k)
        {
            return 0;
        }

        int ans = 0;
        for (int i = 1; i + k < odds.size(); ++i)
        {
            int left = odds[i] - odds[i - 1];
            int right = odds[i + k] - odds[i + k - 1];
            ans += left * right;
        }
        return ans;
    }

    /**
    * @brief Two Points
    * Time:O(n)
    * Space:O(1)
    * @param nums 
    * @param k 
    * @return int 
    */
    int numberOfSubarrays_2(vector<int> &nums, int k)
    {
        return numberOfSubarrayWithAtmostKOddNumbers(nums, k) - numberOfSubarrayWithAtmostKOddNumbers(nums, k - 1);
    }
    int numberOfSubarrayWithAtmostKOddNumbers(vector<int> &nums, int k)
    {
        int n = nums.size();
        int si = 0, ei = 0, count = 0, presum = 0;
        while (ei < n)
        {
            if (nums[ei++] % 2)
            {
                presum++;
            }
            while (presum > k)
            {
                if (nums[si++] % 2)
                {
                    presum--;
                }
            }
            count += ei - si;
        }
        return count;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    cout << solution.numberOfSubarrays(nums, 2) << endl;
    system("pause");
    return 0;
}
