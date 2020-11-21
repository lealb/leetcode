#include <iostream>
#include <vector>

using namespace std;
/**
 * The length of nums will be in the range [0, 10000].
 * Each element nums[i] will be an integer in the range [-1000, 1000].
*/
class Solution
{
public:
    /**
         * Approach #1: Prefix Sum
         */
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0, leftsum = 0, size = nums.size();
        for (int x : nums)
        {
            sum += x;
        }
        for (int i = 0; i < size; ++i)
        {
            if (leftsum == sum - leftsum - nums[i])
            {
                return i;
            }
            leftsum += nums[i];
        }
        return -1;
    }
    int pivotIndex_1(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> left(n + 2, 0);
        vector<int> right(n + 2, 0);
        for (int i = 1; i <= n; i++)
        {
            left[i] = left[i - 1] + nums[i - 1];
        }
        for (int i = n; i > 0; i--)
        {
            right[i] = right[i + 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; i++)
        {
            if (left[i] == right[i])
                return i - 1;
        }
        return -1;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
