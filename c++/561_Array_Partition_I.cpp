#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 1 <= n <= 10^4
 * nums.length == 2 * n
 * -10^4 <= nums[i] <= 10^4
 */
class Solution
{
public:
    /**
     * Sorted
     * O(nlogn)
     */
    int arrayPairSum(vector<int> &nums)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < size; i += 2)
        {
            ans += nums[i];
        }
        return ans;
    }
    int arrayPairSum_1(vector<int> &nums)
    {
        vector<int> arr(20001);
        int lim = 10000;
        for (int num : nums)
        {
            arr[num + lim]++;
        }
        int d = 0, sum = 0;
        for (int i = -10000; i <= 10000; i++)
        {
            sum += (arr[i + lim] + 1 - d) / 2 * i;
            d = (2 + arr[i + lim] - d) % 2;
        }
        return sum;
    }
    int arrayPairSum_2(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int max = 10000;
        // sort nums?
        vector<int> count(2 * max + 2, 0), sorted(nums.size());
        for (auto i : nums)
        {
            count[max + i + 1]++;
        }

        for (int i = 1; i < count.size(); i++)
        {
            count[i] += count[i - 1];
        }

        for (auto i : nums)
        {
            sorted[count[max + 1 + i] - 1] = i;
            count[max + 1 + i]--;
        }

        int sum = 0;
        for (int i = 0; i < sorted.size(); i += 2)
        {
            sum += sorted[i];
        }

        return sum;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {6, 2, 6, 5, 1, 2};
    cout << solution.arrayPairSum_1(nums) << endl;
    system("pause");
    return 0;
}
