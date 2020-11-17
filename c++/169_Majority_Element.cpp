#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <time.h>
using namespace std;
class Solution
{
public:
    /**
     * 
     * Time Limit Exceeded
     */
    int majorityElement(vector<int> &nums)
    {
        int numsLen = nums.size();
        int target = nums[0];
        if (1 == numsLen)
        {
            return target;
        }

        for (int i = 1; i < numsLen; i++)
        {
            if (target == nums[i])
            {
                i++;
            }
            if (count(nums.begin(), nums.end(), target) > numsLen / 2)
            {
                return target;
            }
            target = nums[i];
        }
        return -1;
    }
    bool cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }

    // solution
    /**
     * Approach 1: Brute Force
     * Time complexity : O(n^2)
     * The brute force algorithm contains two nested for loops that each run for n iterations,
     *  adding up to quadratic time complexity.
     * Space complexity : O(1)
     * The brute force solution does not allocate additional space proportional to the input size.
     */
    int majorityElement_1(vector<int> &nums)
    {
        int majorityCount = nums.size() / 2;
        for (int num : nums)
        {
            int count = 0;
            for (int elem : nums)
            {
                if (elem == num)
                {
                    count += 1;
                }
            }
            if (count > majorityCount)
            {
                return num;
            }
        }
        return -1;
    }
    /**
     * Approach 2: HashMap
     * Time complexity : O(n)
     * Space complexity : O(n)
     */
    int majorityElement_2(vector<int> &nums)
    {
        int numsLen = nums.size();
        int target = nums[0];
        if (1 == numsLen)
        {
            return target;
        }
        unordered_map<int, int> ans;
        for (int i = 0; i < numsLen; i++)
        {
            if (ans.find(nums[i]) == ans.end())
            {
                // ans.insert({nums[i], 1});
                ans[nums[i]] = 1;
            }
            else
            {
                ans[nums[i]]++;
            }
        }
        //
        for (auto it = ans.begin(); it != ans.end(); it++)
        {
            // cout << it->first << ":" << it->second << endl;
            if (it->second > numsLen / 2)
            {
                return it->first;
            }
        }

        // sort(ans.begin(), ans.end(), cmp);
        return -1;
    }

    /**
     * Approach 3: Sorting
     * Time complexity : O(nlgn)
     * Sorting the array costs O(nlgn) time in Python and Java, 
     * so it dominates the overall runtime.
     * Space complexity : O(1) or O(n))
     * We sorted nums in place here - if that is not allowed, 
     * then we must spend linear additional space on a copy of nums and sort the copy instead.
     */
    int majorityElement_3(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    /**
     * Approach 4: Randomization
     * Time complexity : O(∞)
     * Space complexity : O(1)
     */
    int majorityElement_4(vector<int> &nums)
    {
        srand(time(nullptr));
        const int n = nums.size();
        while (true)
        {
            const int index = rand() % n;
            const int majority = nums[index];
            int count = 0;
            for (const int num : nums)
                if (num == majority && ++count > n / 2)
                    return num;
        }
        return -1;
    }

    /**
     * Approach 5: Divide and Conquer
     * Time complexity : O(nlgn)
     * Space complexity : O(lgn)
     */
    int countInRange(vector<int> &nums, int num, int lo, int hi)
    {
        int count = 0;
        for (int i = lo; i <= hi; i++)
        {
            if (nums[i] == num)
            {
                count++;
            }
        }
        return count;
    }

    int majorityElementRec(vector<int> &nums, int lo, int hi)
    {
        // base case; the only element in an array of size 1 is the majority
        // element.
        if (lo == hi)
        {
            return nums[lo];
        }

        // recurse on left and right halves of this slice.
        int mid = (hi - lo) / 2 + lo;
        int left = majorityElementRec(nums, lo, mid);
        int right = majorityElementRec(nums, mid + 1, hi);

        // if the two halves agree on the majority element, return it.
        if (left == right)
        {
            return left;
        }

        // otherwise, count each element and return the "winner".
        int leftCount = countInRange(nums, left, lo, hi);
        int rightCount = countInRange(nums, right, lo, hi);

        return leftCount > rightCount ? left : right;
    }

    int majorityElement_5(vector<int> &nums)
    {
        return majorityElementRec(nums, 0, nums.size() - 1);
    }

    /**
     * Approach 6: Boyer-Moore Voting Algorithm [投票算法]
     * Time complexity : O(n)
     * Boyer-Moore performs constant work exactly nn times, so the algorithm runs in linear time.
     * Space complexity : O(1)
     * Boyer-Moore allocates only constant additional memory
     */
    int majorityElement_6(vector<int> &nums)
    {
        int count = 0;
        int candidate = 0;

        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << solution.majorityElement_0(nums) << endl;
    system("pause");
    return 0;
}
