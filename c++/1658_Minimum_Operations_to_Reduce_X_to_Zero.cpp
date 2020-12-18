#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * 1 <= x <= 10^9
 */
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        //前缀和以及后缀和 俩递增序列
        vector<int> prefix(n + 1), suffix(n + 2);
        for (int i = 1, j = n; i <= n; i++, j--)
        {
            prefix[i] = prefix[i - 1] + nums[i - 1], suffix[j] = suffix[j + 1] + nums[j - 1];
        }
        //防止重叠选取 则必须所有和加起来大于等于x才行
        if (prefix[n] < x)
        {
            return -1;
        }
        int ans = -1;
        for (int i = 0, j = 1; i <= n && j <= n + 1; i++)
        {
            //相当于在两个递增序列 0~i 及n+1~j 找到和为x的下标 双指针即可
            while (j <= n + 1 && prefix[i] + suffix[j] > x)
            {
                j++;
            }
            //因前缀和一直在增大 故而让后缀和减小到合适位置
            if (j <= n + 1 && prefix[i] + suffix[j] == x && (ans == -1 || ans > i + n - j + 1))
            {
                ans = i + n - j + 1;
            }
        }
        return ans;
    }
    int minOperations_1(vector<int> &nums, int x)
    {
        int n = nums.size();
        int right = n;
        int numOps = 0, minOps = n + 1;
        while (right >= 1 && x > 0)
        {
            --right;
            x -= nums[right];
        }
        if (x == 0)
            minOps = n - right;
        for (int left = 0; left < n; ++left)
        {
            x -= nums[left];
            for (; right < n and x < 0; ++right)
                x += nums[right];
            if (x < 0)
                break;
            else if (x == 0)
                minOps = min(minOps, n - right + left + 1);
        }
        return minOps == n + 1 ? -1 : minOps;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 2, 20, 1, 1, 3};
    cout << solution.minOperations(nums, 10) << endl;
    system("pause");
    return 0;
}
