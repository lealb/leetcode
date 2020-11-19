#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
/**
 * 0 <= i, j < nums.length
 * i != j
 * |nums[i] - nums[j]| == k
*/
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int ans = 0, size = nums.size();
        unordered_map<int, unordered_set<int>> myMap;
        for (int i = 0; i < size; i++)
        {
            if (myMap.count(nums[i] + k) and !myMap[nums[i] + k].count(nums[i]))
            {
                myMap[nums[i] + k].insert(nums[i]);
                myMap[nums[i]].insert(nums[i] + k);
                ans++;
            }
            if (myMap.count(nums[i] - k) and !myMap[nums[i] - k].count(nums[i]))
            {
                myMap[nums[i] - k].insert(nums[i]);
                myMap[nums[i]].insert(nums[i] - k);
                ans++;
            }
            myMap[nums[i]].insert(INT_MAX);
        }
        return ans;
    }
    int findPairs_1(vector<int> &nums, int k)
    {
        unordered_map<int, int> dp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!dp.count(nums[i]))
                dp[nums[i]] = 1;
            else
                dp[nums[i]]++;
        }
        int count = 0;
        for (auto itr : dp)
        {
            int val = itr.first + k;
            if (val == itr.first && dp[val] > 1)
            {
                count++;
            }
            else if (dp.count(val) && val != itr.first)
            {
                count++;
            }
        }
        return count;
    }
    int findPairs_2(vector<int> &nums, int k)
    {
        if (nums.size() <= 1)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int count = 0;
        int i = 0, j = 1;
        pair<int, int> last = make_pair(-10000001, -10000001);
        while (j < nums.size())
        {
            int diff = nums[j] - nums[i];
            if (i == j)
            {
                j++;
            }
            else if (diff < k)
            {
                j++;
            }
            else if (diff > k)
            {
                i++;
            }
            else
            { // diff == k
                pair<int, int> key = make_pair(nums[i], nums[j]);
                if (key != last)
                {
                    count++;
                    last = key;
                }
                i++, j++;
            }
        }
        return count;
    }
    /**
     * Two pointers
     * T:20ms
     */
    int findPairs_4(vector<int> &nums, int k)
    {
        if (k < 0)
        {
            return 0;
        }

        int N = nums.size();
        sort(nums.begin(), nums.end());
        int total = 0;
        for (int i = 0, j = 0; i < N; i++)
        {
            j = max(j, i + 1);
            while (j < N && nums[j] - nums[i] < k)
            {
                j++;
            }
            if (j < N && nums[j] - nums[i] == k)
            {
                total++;
            }
            while (i + 1 < N && nums[i + 1] == nums[i])
            {
                i++;
            }
        }
        return total;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
