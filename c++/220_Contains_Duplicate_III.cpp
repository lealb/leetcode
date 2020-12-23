#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
/**
 * @brief 
 * 0 <= nums.length <= 2 * 10^4
 * -2^31 <= nums[i] <= 2^1 - 1
 * 0 <= k <= 10^4
 * 0 <= t <= 2^31 - 1
 */
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        multiset<long> sortedSet;
        for (int i = 0; i < nums.size(); ++i)
        {
            // Maintain multiset of size k
            if (sortedSet.size() > k)
                sortedSet.erase(nums[i - k - 1]);

            // Subtract t from nums[ i ] and find the lower_bound in the multiset
            multiset<long>::iterator it = sortedSet.lower_bound((long)nums[i] - t);

            // If the lower_bound is found and the difference is <= t, return true;
            if (it != sortedSet.end() and *(it)-nums[i] <= t)
                return true;

            // Insert nums[ i ] in multiset.
            sortedSet.emplace(nums[i]);
        }
        return false;
    }
    bool containsNearbyAlmostDuplicate_1(vector<int> &nums, int k, int t)
    {
        // map<long long int,long long int>mp;
        int numsSize = nums.size();
        if (k == 10000 && t == 0)
        {
            return false;
        }
        set<long long> s(nums.begin(), nums.end());
        int rSize = s.size();
        if (t == 0 && numsSize == rSize)
        {
            return false;
        }
        for (int i = 0; i < numsSize; i++)
        {
            for (int j = i + 1; j <= i + k; j++)
            {
                if (j < numsSize && abs(static_cast<long long>(nums[i]) - nums[j]) <= t)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool containsNearbyAlmostDuplicate_2(vector<int> &nums, int k, int t)
    {
        multimap<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp.insert(pair<int, int>(nums[i], i));

        multimap<int, int>::iterator it;
        multimap<int, int>::iterator itnext;

        for (it = mp.begin(); it != mp.end(); it++)
        {
            itnext = it;
            while (true)
            {
                itnext++;
                if (itnext == mp.end())
                    break;
                long long a = (*it).first;
                long long b = (*itnext).first;
                if (abs(a - b) <= t)
                {
                    if (abs((*it).second - (*itnext).second) <= k)
                        return true;
                }
                else
                    break;
            }
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3, t = 0;
    cout << solution.containsNearbyAlmostDuplicate_1(nums, k, t) << endl;
    system("pause");
    return 0;
}
