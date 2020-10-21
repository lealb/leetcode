#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Time complexity N.N! Space O(N), including space for result it would be O(N.N!)
//Code is wrong in the link here but explanation is good : https://leetcode.com/problems/subsets-ii/discuss/30156/Subset-I-II-and-Perm-I-II-Difference-Explained
class Solution
{
public:
    // if duplicates are present sort
    // permutations need swap in recursive but subsets don't; instead subsets use vector push_back and pop
    // susbsets compare i && i-1 whereas permutations compare i & begin elements
    // IN permutations position matter whereas in subsets it doesnt, that's why it uses begin for recursive
    // susbets call recursive with i+1 whereas permutations call with begin+1
    // subsets need to pass in another vector to keep subsets in addition to final result vector
    // note that nums is passed as value not reference so that it doesnt get modified
    void recur(vector<int> nums, int begin, int end, vector<vector<int>> &res)
    {
        if (begin == end - 1)
        {
            res.push_back(nums);
            return;
        }
        for (auto i = begin; i < end; i++)
        {
            if (i != begin && nums[i] == nums[begin])
                continue;
            swap(nums[i], nums[begin]);
            recur(nums, begin + 1, end, res);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &num)
    {
        //sort is needed when duplicates are present
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        recur(num, 0, num.size(), res);
        return res;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 1, 2};
    Solution solution = Solution();
    vector<vector<int>> res = solution.permuteUnique(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (auto r : res[i])
        {
            cout << r << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
