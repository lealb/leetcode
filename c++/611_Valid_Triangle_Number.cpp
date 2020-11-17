#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /**
     * Approach 1: Brute Force
     * O(n^3)
     */
    int triangleNumber_0(vector<int> &nums)
    {
        int count = 0, size = nums.size();
        for (int i = 0; i < size - 2; i++)
        {
            for (int j = i + 1; j < size - 1; j++)
            {
                for (int k = j + 1; k < size; k++)
                {
                    if (nums[i] + nums[j] > nums[k] && nums[i] + nums[k] > nums[j] && nums[j] + nums[k] > nums[i])
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    /**
     * Approach 2: Using Binary Search
     * Time: O(n^2logn)
     * Space: O(logn)
     */
    int triangleNumber(vector<int> &nums)
    {
        int count = 0, size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; i++)
        {
            int k = i + 2;
            for (int j = i + 1; j < size - 1 && nums[i] != 0; j++)
            {
                k = binarySearch(nums, k, size - 1, nums[i] + nums[j]);
                count += k - j - 1;
            }
        }
        return count;
    }
    int binarySearch(vector<int> &nums, int l, int r, int x)
    {
        while (r >= l && r < nums.size())
        {
            int mid = (l + r) / 2;
            if (nums[mid] >= x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }

    /**
     * Approach 3: Linear Scan
     * Time complexity : O(n^2)
     * Space : O(logn)
     */
    int triangleNumber(vector<int> &nums)
    {
        int count = 0, size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; i++)
        {
            int k = i + 2;
            for (int j = i + 1; j < size - 1 && nums[i] != 0; j++)
            {
                while (k < size && nums[i] + nums[j] > nums[k])
                {
                    k++;
                }
                count += k - j - 1;
            }
        }
        return count;
    }
};
int main()
{
    Solution solution;

    return 0;
}
