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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        int len = candidates.size();
        for (int i = 0; i < len && target >= candidates[i]; i++)
        {
            int factor = target / candidates[i];
            int residue = target % candidates[i];
            if (0 == residue)
            {
                res.push_back({(factor, candidates[i])});
            }
            else
            {
                while (i + 1 < len && target >= candidates[i + 1])
                {
                    if (candidates[i] == residue)
                    {
                        vector<int> tmp(factor, candidates[i + 1]);
                        tmp.push_back(residue);
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res;
    }
    vector<vector<int>> result;
    vector<vector<int>> combinationSum_1(vector<int> &candidates, int target)
    {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtrackFind(0, target, cur, candidates);
        return result;
    }

    void backtrackFind(int index, int target, vector<int> &cur, vector<int> &candidates)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            result.push_back(cur);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            cur.push_back(candidates[i]);
            backtrackFind(i, target - candidates[i], cur, candidates);
            cur.pop_back();
        }
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 3, 6, 1, 7};
    Solution solution;
    // sort(begin(nums), end(nums));
    vector<vector<int>> res = solution.combinationSum_1(nums, 7);
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
