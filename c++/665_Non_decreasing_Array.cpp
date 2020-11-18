#include <iostream>
#include <vector>

using namespace std;
/**
 * 1 <= n <= 10 ^ 4
 * - 10 ^ 5 <= nums[i] <= 10 ^ 5
 */
class Solution
{
public:
    bool checkPossibility_0(vector<int> &nums)
    {
        int numsSize = nums.size(), nChanges = 0;
        if (numsSize <= 2)
        {
            return true;
        }
        if (nums[0] > nums[1])
        {
            ++nChanges;
        }
        for (int i = 1; i < numsSize - 1; ++i)
        {
            if (nums[i] > nums[i + 1])
            {
                if (nums[i - 1] > nums[i + 1])
                {
                    nums[i + 1] = nums[i];
                }
                if (nChanges == 1)
                {
                    return false;
                }
                ++nChanges;
            }
        }
        return true;
    }
    /**
     *  max_till 意义何在？？ 为何会快些
     */
    bool checkPossibility_1(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        int max_till = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            // first
            if (nums[i] > nums[i + 1])
            {
                // second
                if (max_till <= nums[i + 1])
                {
                    nums[i] = nums[i + 1];
                }
                else
                {
                    nums[i + 1] = nums[i];
                }
                count++;
            }
            max_till = nums[i];
            // if (count > 1)
            // {
            //     return false;
            // }
        }
        return count <= 1;
    }
    bool checkPossibility_2(vector<int> &nums)
    {
        int cnt = 0, size = nums.size();
        int dropIdx = -1;
        for (int i = 0; i < size - 1; i++)
        {
            if (nums[i + 1] < nums[i])
            {
                cnt++;
                dropIdx = i;
            }
            if (cnt > 1)
            {
                return false;
            }
        }

        if (cnt == 0) // non-decreasing
        {
            return true;
        }
        else // one anomaly
        {
            if (nums[0] > nums[1])
                return true;
            if (nums[nums.size() - 1] < nums[size - 2])
                return true;
            if (nums[dropIdx + 1] >= nums[dropIdx - 1])
                return true;
            if (nums[dropIdx + 2] >= nums[dropIdx])
                return true;
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 2, 3, 5, 1};
    cout << solution.checkPossibility_1(nums) << endl;
    system("pause");
    return 0;
}
