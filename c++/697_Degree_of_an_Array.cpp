#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAX 50000
using namespace std;
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int cnt[50000][2]; // {index of first occurance, frequence of that element}
        memset(cnt, -1, sizeof(cnt));
        int size = nums.size(), maxFreq = 0, minLen = INT_MAX;

        for (int i = 0; i < size; ++i)
        {
            if (cnt[nums[i]][0] == -1)
            {
                cnt[nums[i]][0] = i, cnt[nums[i]][1] = 1;
            }
            else
            {
                cnt[nums[i]][1]++;
            }
            if (cnt[nums[i]][1] > maxFreq)
            {
                maxFreq = cnt[nums[i]][1], minLen = i - cnt[nums[i]][0] + 1;
            }
            else if (cnt[nums[i]][1] == maxFreq)
            {
                minLen = min(minLen, i - cnt[nums[i]][0] + 1);
            }
        }
        return minLen;
    }
    int findShortestSubArray_0(vector<int> &nums)
    {
        int start[MAX], end[MAX], degree[MAX] = {};
        int size = nums.size(), maxDegree = -1;
        fill(start, start + MAX, -1);
        fill(end, end + MAX, -1);
        for (int i = 0; i < size; ++i)
        {
            degree[nums[i]]++;
            maxDegree = max(maxDegree, degree[nums[i]]);
            if (start[nums[i]] == -1)
            {
                start[nums[i]] = end[nums[i]] = i;
            }
            else
            {
                end[nums[i]] = i;
            }
        }
        int minSubLen = MAX;
        for (int i = 0; i < MAX; i++)
        {
            if (degree[i] == maxDegree)
            {
                minSubLen = min(minSubLen, end[i] - start[i] + 1);
            }
        }
        return minSubLen;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 2, 3, 1};
    cout << solution.findShortestSubArray(nums) << endl;
    system("pause");
    return 0;
}
