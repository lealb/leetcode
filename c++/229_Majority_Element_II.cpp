#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
/**
 * 1 <= nums.length <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 * find n/3
 */
class Solution
{
public:
    /**
     * Hashmap 
     */
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> count;
        unordered_set<int> numsSet;
        int numsLen = nums.size() / 3;
        for (auto num : nums)
        {
            if (++count[num] > numsLen)
            {
                numsSet.insert(num);
            }
        }
        return {numsSet.begin(), numsSet.end()};
    }
    vector<int> majorityElement_1(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        vector<int> resp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int numsLen = nums.size() / 3;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second > numsLen)
            {
                resp.push_back(it->first);
            }
        }
        return resp;
    }
    vector<int> majorityElement_2(vector<int> &nums)
    {
        int cnt1 = 0, cnt2 = 0;
        int el1 = -1, el2 = -1;
        int n = nums.size();
        for (auto x : nums)
        {

            if (x == el1)
                cnt1++;
            else if (x == el2)
                cnt2++;
            else if (cnt1 == 0)
            {
                el1 = x;
                cnt1++;
            }
            else if (cnt2 == 0)
                el2 = x, cnt2++;
            else
                cnt1--, cnt2--;
        }
        cnt1 = 0, cnt2 = 0;
        for (auto x : nums)
        {
            if (x == el1)
                cnt1++;
            else if (x == el2)
                cnt2++;
        }
        vector<int> v;

        if ((n / 3) < cnt1)
            v.push_back(el1);
        if ((n / 3) < cnt2)
            v.push_back(el2);
        return v;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2};
    vector<int> res = solution.majorityElement(nums);
    for (auto &r : res)
    {
        cout << r << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
