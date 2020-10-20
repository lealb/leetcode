#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * All elements of candidates are distinct.
 * 1 <= target <= 500
 */
class Solution
{
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtrackFind(0, target, cur, candidates);
        return result;
    }

    void backtrackFind(int index, int target, vector<int> &cur, vector<int> &candidates)
    {
        if (target == 0)
        {
            result.push_back(cur);
            return;
        }

        for (int i = index; i < candidates.size() && target >= candidates[i]; i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            cur.push_back(candidates[i]);
            backtrackFind(i + 1, target - candidates[i], cur, candidates);
            cur.pop_back();
        }
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    Solution solution;
    // sort(begin(nums), end(nums));
    vector<vector<int>> res = solution.combinationSum2(nums, 8);
    for (int i = 0; i < res.size(); i++)
    {
        for (auto r : res[i])
        {
            cout << r << " ";
        }
        cout << endl;
    }
    // system("pause");
    return 0;
}
