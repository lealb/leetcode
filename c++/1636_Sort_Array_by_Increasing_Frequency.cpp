#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/**
 * @brief 
 * 1 <= nums.length <= 100
 * -100 <= nums[i] <= 100
 */
class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        int size = nums.size();
        unordered_map<int, int> ansMap;
        for (int i = 0; i < size; ++i)
        {
            if (ansMap.find(nums[i]) == ansMap.end())
            {
                ansMap.insert({nums[i], 1});
            }
            else
            {
                ansMap[nums[i]]++;
            }
        }

        sort(ansMap.begin(), ansMap.end(), comp);
        // [](pair<int, int> &m1, pair<int, int> &m2) {
        //     return m1.second != m2.second ? m1.second < m2.second : m1.first > m2.first;
        // }
        vector<int> ans;
        for (unordered_map<int, int>::iterator it = ansMap.begin(); it != ansMap.end(); it++)
        {
            while (it->second--)
            {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second == b.second ? a.first > b.first : a.second < b.second;
    }
    vector<int> frequencySort_1(vector<int> &nums)
    {
        unordered_map<int, int> map{};
        for (auto n : nums)
            map[n]++;
        vector<pair<int, int>> vec;
        for (auto p : map)
            vec.push_back(p);
        sort(vec.begin(), vec.end(), comp);

        vector<int> ans;
        for (auto p : vec)
        {
            while (p.second--)
            {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {-1, 1, -6, 4, 5, -6, 1, 4, 1};
    vector<int> ans = solution.frequencySort_1(nums);
    for (auto &v : ans)
    {
        cout << v << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
