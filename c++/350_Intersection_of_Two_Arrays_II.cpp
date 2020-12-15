#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/**
 * @brief 
 * What if the given array is already sorted? How would you optimize your algorithm?
 *  two pointer/ divide
 * What if nums1's size is small compared to nums2's size? Which algorithm is better?
 * What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
 */
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> occurences;
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++)
        {
            occurences[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (occurences.count(nums2[i]))
            {
                occurences[nums2[i]]--;
                result.push_back(nums2[i]);
                if (occurences[nums2[i]] == 0)
                {
                    occurences.erase(nums2[i]);
                }
            }
        }
        return result;
    }
    vector<int> intersect_1(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
                i++;
            if (nums1[i] > nums2[j])
                j++;
            else if (nums1[i] == nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> ans = solution.intersect_1(nums1, nums2);
    for (auto v : ans)
    {
        cout << v << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
