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
        unordered_map<int, int> ansMap{};
        for (auto n : nums)
        {
            ansMap[n]++;
        }
        vector<pair<int, int>> ansVec;
        for (auto p : ansMap)
        {
            ansVec.push_back(p);
        }
        sort(ansVec.begin(), ansVec.end(), [](pair<int, int> &m1, pair<int, int> &m2) {
            return m1.second != m2.second ? m1.second < m2.second : m1.first > m2.first;
        });
        vector<int> ans;
        for (auto p : ansVec)
        {
            while (p.second--)
            {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
    vector<int> frequencySort_1(vector<int> &nums)
    {
        int cnt[201] = {};
        for (int n : nums)
        {
            cnt[n + 100]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return cnt[a + 100] == cnt[b + 100] ? a > b : cnt[a + 100] < cnt[b + 100];
        });
        return nums;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {-1, 1, -6, 4, 5, -6, 1, 4, 1};
    vector<int> ans = solution.frequencySort(nums);
    for (auto &v : ans)
    {
        cout << v << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
