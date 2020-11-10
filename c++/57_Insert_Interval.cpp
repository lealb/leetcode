#include <iostream>
#include <vector>

using namespace std;
/**
 * 0 <= intervals.length <= 104
 * intervals[i].length == 2
 * 0 <= intervals[i][0] <= intervals[i][1] <= 10^5
 * intervals is sorted by intervals[i][0] in ascending order.
 * newInterval.length == 2
 * 0 <= newInterval[0] <= newInterval[1] <= 10^5
 */
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int size = intervals.size();
        if (0 == size)
        {
            return {newInterval};
        }
        vector<vector<int>> ans;
        // intervals.insert(newInterval);
        for (int i = 0; i < size; i++)
        {
            if (intervals[i][0] >= newInterval[0])
            {
                intervals.emplace(intervals.begin() + i + 1, newInterval);
                break;
            }
        }
        ans.push_back(intervals[0]);
        for (int i = 1; i < size + 1; i++)
        {
            int tempSize = ans.size();
            if (ans[tempSize - 1][1] < intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                ans[tempSize - 1][1] = max(intervals[i][1], ans[tempSize - 1][1]);
            }
        }
        return ans;
    }
    vector<vector<int>> insert_1(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size(), i = 0;
        if (0 == n)
        {
            return {newInterval};
        }
        vector<vector<int>> res;
        while (i < n && intervals[i][1] < newInterval[0])
            res.push_back(intervals[i++]);

        while (i < n && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while (i < n)
            res.push_back(intervals[i++]);
        return res;
    }
};
int main(int argc, char const *argv[])
{
    vector<vector<int>> nums = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    Solution solution = Solution();
    vector<vector<int>> res = solution.insert_1(nums, newInterval);
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
