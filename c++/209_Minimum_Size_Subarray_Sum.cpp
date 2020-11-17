#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    /**
     * Approach #1 Brute force [Time Limit Exceeded]
     * Time complexity: O(n^3)
     * For each element of array, we find all the subarrays starting from that index which is O(n^2)
     * Time complexity to find the sum of each subarray is O(n).
     * Thus, the total time complexity : O(n^2*n) = O(n^3)
     * Space complexity: O(1) extra space.
     */
    int minSubArrayLen_0(int s, vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }
                // Found the smallest subarray with sum>=s starting with index i,
                // hence move to next index
                if (sum >= s)
                {
                    ans = min(ans, (j - i + 1));
                    break;
                }
            }
        }
        return ans != INT_MAX ? ans : 0;
    }

    /**
     * Approach #2 A better brute force
     * Time complexity: O(n^2)
     * Time complexity to find all the subarrays is O(n^2)
     * Sum of the subarrays is calculated in O(1) time.
     * Thus, the total time complexity: O(n^2 * 1) = O(n^2)
     * Space complexity: O(n)O(n) extra space.
     * Additional O(n) space for sums vector than in Approach #1.
     */
    int minSubArrayLen_1(int s, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        vector<int> sums(n);
        sums[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            sums[i] = sums[i - 1] + nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                //Found the smallest subarray with sum>=s starting with index i, hence move to next index
                int sum = sums[j] - sums[i] + nums[i];
                if (sum >= s)
                {
                    ans = min(ans, (j - i + 1));
                    break;
                }
            }
        }
        return ans != INT_MAX ? ans : 0;
    }

    /**
     * Approach #3 Using Binary search
     * Time complexity: O(nlog(n)).
     * For each element in the vector, find the subarray starting from that index,
     *  and having sum greater than ss using binary search. 
     * Hence, the time required is O(n) for iteration over the vector and 
     * O(log(n)) for finding the subarray for each index using binary search.
     * Therefore, total time complexity = O(n∗log(n))
     * Space complexity: O(n). 
     * Additional O(n) space for sums vector
     */
    int minSubArrayLen_2(int s, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0); //size = n+1 for easier calculations
        //sums[0]=0 : Meaning that it is the sum of first 0 elements
        //sums[1]=A[0] : Sum of first 1 elements
        //ans so on...
        for (int i = 1; i <= n; i++)
            sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 1; i <= n; i++)
        {
            int to_find = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), to_find);
            if (bound != sums.end())
            {
                ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
            }
        }
        return ans != INT_MAX ? ans : 0;
    }

    /**
     * Approach #4 Using 2 pointers
     * Time complexity: O(n). 
     *  Single iteration of O(n).
     * Each element can be visited atmost twice, 
     * once by the right pointer(ii) and (atmost)once by the left pointer.
     * Space complexity: O(1) extra space. 
     * Only constant space required for left, sum, ans and ii.
     */
    int minSubArrayLen_3(int s, vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            while (sum >= s)
            {
                ans = min(ans, i + 1 - left);
                sum -= nums[left++];
            }
        }
        return ans != INT_MAX ? ans : 0;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int s = 7;
    cout << solution.minSubArrayLen_3(s, nums) << endl;
    system("pause");
    return 0;
}
