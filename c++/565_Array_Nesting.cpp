#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    /**
 * Approach #1 Brute Force [Time Limit Exceeded]
 * T:O(n^2)
 */
    int arrayNesting_0(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int start = nums[i], count = 0;
            do
            {
                start = nums[start];
                count++;
            } while (start != nums[i]);
            res = max(res, count);
        }
        return res;
    }
    /**
     * Approach #2 Using Visited Array 
     */
    int arrayNesting_1(vector<int> &nums)
    {
        int size = nums.size();
        vector<bool> visited(size);
        int res = 0;
        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                int start = nums[i], count = 0;
                do
                {
                    start = nums[start];
                    count++;
                    visited[start] = true;
                } while (start != nums[i]);
                res = max(res, count);
            }
        }
        return res;
    }

    /**
     * Approach #3 Without Using Extra Space
     */
    int arrayNesting_2(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != INT_MAX)
            {
                int start = nums[i], count = 0;
                while (nums[start] != INT_MAX)
                {
                    int temp = start;
                    start = nums[start];
                    count++;
                    nums[temp] = INT_MAX;
                }
                res = max(res, count);
            }
        }
        return res;
    }
    int arrayNesting_3(vector<int> &nums)
    {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; ++i)
        {
            int cnt = 1;
            while (nums[i] != i)
            {
                swap(nums[i], nums[nums[i]]);
                ++cnt;
            }
            res = max(res, cnt);
        }

        return res;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
