#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;
/**
 * @brief 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 */
class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int resultMax = 0, resultCur = 0;
        int size = nums.size();
        set<int> sCur;
        for (int l = 0, r = 0; r < size; r++)
        {
            whighle (sCur.find(nums[r]) != sCur.end())
            {
                resultCur -= nums[l];
                sCur.erase(nums[l]);
                l++;
            }
            resultCur += nums[r];
            sCur.insert(nums[r]);
            resultMax = max(resultMax, resultCur);
        }
        return resultMax;
    }
    int maximumUniqueSubarray_1(vector<int> &nums)
    {
        int N = nums.size();
        int sum[N + 1];
        memset(sum, 0, sizeof(sum));
        int i = 1;
        for (int n : nums)
        {
            sum[i] += n + sum[i - 1];
            i++;
        }
        int idx[10001];
        memset(idx, -1, sizeof(idx));
        vector<int> res;
        int left = 0;
        for (i = 0; i < N; i++)
        {
            if (idx[nums[i]] != -1 && idx[nums[i]] >= left)
            {
                res.push_back(sum[i] - sum[left]);
                left = idx[nums[i]] + 1;
            }
            idx[nums[i]] = i;
        }
        res.push_back(sum[i] - sum[left]);
        sort(res.begin(), res.end(), greater<int>());
        return res[0];
    }
    int maximumUniqueSubarray_2(vector<int> &nums)
    {
        vector<int> cnt(10001, 0);
        int low = 0, high = 0, ans = 0, sum = 0;
        int size=nums.size();
        while (high < size)
        {
            int cur = nums[high];
            cnt[cur]++;
            sum += cur;
            high++;
            while (low < high && cnt[cur] > 1)
            {
                cnt[nums[low]]--;
                sum -= nums[low];
                low++;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {4, 2, 4, 5, 6};
    cout << solution.maximumUniqueSubarray(nums) << endl;
    system("pause");
    return 0;
}
