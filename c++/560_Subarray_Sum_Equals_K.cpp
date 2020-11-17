#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    /**
     * Approach 1: Brute Force
     * O(N^3)
     */
    int subarraySum_0(vector<int> &nums, int k)
    {
        int count = 0, size = nums.size();
        for (int start = 0; start < size; start++)
        {
            for (int end = start + 1; end <= size; end++)
            {
                int sum = 0;
                for (int i = start; i < end; i++)
                {
                    sum += nums[i];
                    if (sum == k)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    /**
     * Approach 2: Using Cumulative Sum
     * T:O(n^2)
     * S:O(n)
     */
    int subarraySum_1(vector<int> &nums, int k)
    {
        int count = 0, size = nums.size();
        vector<int> sum(size + 1);
        sum[0] = 0;
        for (int i = 1; i <= size; i++)
        {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for (int start = 0; start < size; start++)
        {
            for (int end = start + 1; end <= size; end++)
            {
                if (sum[end] - sum[start] == k)
                {
                    count++;
                }
            }
        }
        return count;
    }

    /**
     * Approach 3: Without Space
     * Time complexity : O(n^2) We need to consider every subarray possible.
     * Space complexity : O(1). Constant space is used.
     */
    int subarraySum_2(vector<int> &nums, int k)
    {
        int count = 0, size = nums.size();
        for (int start = 0; start < size; start++)
        {
            int sum = 0;
            for (int end = start; end < size; end++)
            {
                sum += nums[end];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }

    /**
     * Hash Map
     * O(n)
     */
    int subarraySum_3(vector<int> &nums, int k)
    {
        int ans = 0, size = nums.size();
        unordered_map<int, int> sumMap;
        sumMap[0] = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sumMap.find(sum - k) != sumMap.end())
            {
                ans += sumMap[sum - k];
            }
            sumMap[sum]++;
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {-1, 1, 0};
    cout << solution.subarraySum_3(nums, 0) << endl;
    system("pause");
    return 0;
}
