#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;
/**
 * @brief 
 * Each element in the result must be unique.
 * The result can be in any order.
 */
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int nums1Len = nums1.size(), nums2Len = nums2.size();
        vector<int> ans;
        if (0 == nums1Len || 0 == nums2Len)
        {
            return {};
        }
        vector<int> maxNums = nums1Len > nums2Len ? nums1 : nums2;
        vector<int> minNums = nums1Len < nums2Len ? nums1 : nums2;
        int left = 0, right = minNums.size() - 1;
        while (left <= right)
        {
            if (find(maxNums.begin(), maxNums.end(), minNums[left++]) != maxNums.end() && find(ans.begin(), ans.end(), minNums[left++]) == ans.end())
            {
                ans.push_back(minNums[left++]);
            }
        }
        return ans;
    }
    vector<int> intersection_1(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        if (nums1.size() == 0 || nums2.size() == 0)
        {
            return res;
        }
        unordered_set<int> frq;
        for (int i = 0; i < nums2.size(); ++i)
        {
            frq.insert(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); ++i)
        {
            if (frq.count(nums1[i]) > 0 && count(res.begin(), res.end(), nums1[i]) == 0)
            {
                res.push_back(nums1[i]);
            }
        }

        std::sort(res.begin(), res.end());
        std::unique(res.begin(), res.end());
        return res;
    }
    vector<int> intersection_2(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());

        // printSet(s1);
        // printSet(s2);

        vector<int> res;
        for (auto it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end() && it2 != s2.end();)
        {
            if (*it1 < *it2)
            {
                it1++;
            }
            if (*it1 > *it2)
            {
                it2++;
            }
            if (*it1 == *it2)
            {
                res.push_back(*it1);
                it1++;
                it2++;
            }
        }
        return res;
    }
    vector<int> intersection_3(vector<int> &arr1, vector<int> &arr2)
    {
        int i, n = arr1.size();
        vector<int> out;
        set<int> S;
        for (i = 0; i < n; i++)
            S.insert(arr1[i]);
        n = arr2.size();
        for (i = 0; i < n; i++)
        {
            if (S.find(arr2[i]) != S.end())
            {
                out.push_back(arr2[i]);
                S.erase(S.find(arr2[i]));
            }
        }
        return out;
    }
    vector<int> intersection_4(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> first(nums1.begin(), nums1.end());
        unordered_set<int> res;
        vector<int> sol;
        for (int num : nums2)
        {
            if (first.find(num) != first.end())
            {
                res.insert(num);
            }
        }

        sol.insert(sol.end(), res.begin(), res.end());

        return sol;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2, 5, 6};
    vector<int> ans = solution.intersection_2(nums1, nums2);
    for (auto v : ans)
    {
        cout << v << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
