#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /**
     * Approach 1: Brute Force
     * O(N^3)
     */
    int findUnsortedSubarray_0(vector<int> &nums)
    {
        int size = nums.size();
        int res = size;
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j <= size; j++)
            {
                int minV = INT_MAX, maxV = INT_MIN, prev = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    minV = min(minV, nums[k]);
                    maxV = max(maxV, nums[k]);
                }
                if ((i > 0 && nums[i - 1] > minV) || (j < size && nums[j] < maxV))
                    continue;
                int k = 0;
                while (k < i && prev <= nums[k])
                {
                    prev = nums[k];
                    k++;
                }
                if (k != i)
                    continue;
                k = j;
                while (k < size && prev <= nums[k])
                {
                    prev = nums[k];
                    k++;
                }
                if (k == size)
                {
                    res = min(res, j - i);
                }
            }
        }
        return res;
    }

    /**
     * O(n^2)
     */
    int findUnsortedSubarray_1(vector<int> &nums)
    {
        int size = nums.size();
        int l = nums.size(), r = 0;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (nums[j] < nums[i])
                {
                    r = max(r, j);
                    l = min(l, i);
                }
            }
        }
        return r - l < 0 ? 0 : r - l + 1;
    }

    /**
     * Approach 1: Sorted
     */
    int findUnsortedSubarray_2(vector<int> &nums)
    {
        vector<int> snums;
        copy(nums.begin(), nums.end(), snums.begin());
        sort(snums.begin(), snums.end());
        int start = snums.size(), end = 0;
        for (int i = 0; i < snums.size(); i++)
        {
            if (snums[i] != nums[i])
            {
                start = min(start, i);
                end = max(end, i);
            }
        }
        return end - start >= 0 ? end - start + 1 : 0;
    }

    int findUnsortedSubarray_3(vector<int> &nums)
    {
        stack<int> numsStack;
        int l = nums.size(), r = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!numsStack.empty() && nums[numsStack.top()] > nums[i])
            {
                l = min(l, numsStack.top());
                numsStack.pop();
            }
            numsStack.push(i);
        }
        stack<int>().swap(numsStack);
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!numsStack.empty() && nums[numsStack.top()] < nums[i])
            {
                r = max(r, numsStack.top());
                numsStack.pop();
            }
            numsStack.push(i);
        }
        return r - l > 0 ? r - l + 1 : 0;
    }
    int findUnsortedSubarray_4(vector<int> &nums)
    {
        int minV = INT_MAX, maxV = INT_MIN;
        bool flag = false;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
                flag = true;
            if (flag)
                minV = min(minV, nums[i]);
        }
        flag = false;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] > nums[i + 1])
                flag = true;
            if (flag)
                maxV = max(maxV, nums[i]);
        }
        int l, r;
        for (l = 0; l < nums.size(); l++)
        {
            if (minV < nums[l])
                break;
        }
        for (r = nums.size() - 1; r >= 0; r--)
        {
            if (maxV > nums[r])
                break;
        }
        return r - l < 0 ? 0 : r - l + 1;
    }
    int findUnsortedSubarray_5(vector<int> &nums)
    {
        const int n = nums.size();
        int beg = -1, end = -2;
        int imax = nums[0], imin = nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            imax = max(imax, nums[i]);
            imin = min(imin, nums[n - 1 - i]);
            if (nums[i] < imax)
            {
                end = i;
            }
            if (nums[n - 1 - i] > imin)
            {
                beg = n - 1 - i;
            }
        }
        return end - beg + 1;
    }
    int findUnsortedSubarray_6(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int start = -1, end = -1, currMax = INT_MIN, currMin = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            currMax = max(currMax, nums[i]);
            if (currMax > nums[i])
            {
                if (start == -1 or currMin > nums[i])
                {
                    currMin = min(currMin, nums[i]);
                    start = i;
                }
                end = i;
            }
        }

        if (start == -1)
        {
            return 0;
        }

        int j = 0;
        while (j < n)
        {
            if (nums[j] > nums[start])
            {
                break;
            }
            j++;
        }
        return (end == -1 ? n : end) - j + 1;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    cout << solution.findUnsortedSubarray_3(nums) << endl;
    system("pause");
    return 0;
}
