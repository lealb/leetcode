#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int pairsWithAtmostDiff(vector<int> &nums, int n, int diff)
    {
        int left = 0, right = 1, count = 0;

        while (right < n)
        {
            if ((nums[right] - nums[left]) <= diff)
            {
                count += right - left;
                right++;
            }
            else
            {
                left++;
            }
            if (left == right)
                right++;
        }
        return count;
    }

    int smallestDistancePair(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int low = 0, high = nums[n - 1] - nums[0], ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int count = pairsWithAtmostDiff(nums, n, mid);
            if (count >= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
