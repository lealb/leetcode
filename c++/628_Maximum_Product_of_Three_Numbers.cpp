#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 3 <= size <= 104
 * -1000 <= nums[i] <= 1000
 */
class Solution
{
public:
    /**
     * O(nlogn)
     * O(logn)
     */
    int maximumProduct(vector<int> &nums)
    {
        int size = nums.size();
        // sort
        sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums[size - 1], nums[size - 1] * nums[size - 2] * nums[size - 3]);
    }
    int maximumProduct_1(vector<int> &nums)
    {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (int n : nums)
        {
            if (n <= min1)
            {
                min2 = min1;
                min1 = n;
            }
            // n lies between min1 and min2
            else if (n <= min2)
            {
                min2 = n;
            }
            // n is greater than max1, max2 and max3
            if (n >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = n;
            }
            // n lies betweeen max1 and max2   max2<= n<max1
            else if (n >= max2)
            {
                max3 = max2;
                max2 = n;
            }
            // n lies betwen max2 and max3
            else if (n >= max3)
            {
                max3 = n;
            }
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 5};
    cout << solution.maximumProduct_1(nums) << endl;
    system("pause");
    return 0;
}
