#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /**
     * running time
     */
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int c = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        vector<vector<int>> res;
        if (1 >= c)
        {
            return 1 == c ? intervals : res;
        }
        int i = 0;
        for (i = 0; i < c - 1; i++)
        {
            if (intervals[i][1] >= intervals[i + 1][0])
            {
                if (intervals[i][1] < intervals[i + 1][1])
                {
                    res.push_back({intervals[i][0], intervals[i + 1][1]});
                }
                else
                {
                    res.push_back({intervals[i][0], intervals[i][1]});
                }
                i++;
            }
            else
            {
                res.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        if (i == c - 1)
        {
            res.push_back({intervals[c - 1][0], intervals[c - 1][1]});
        }
        return merge(res);
    }

    vector<vector<int>> merge_1(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        int n = intervals.size();
        if (n == 0)
            return ans;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++)
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

    vector<vector<int>> merge_2(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
            return intervals;

        vector<vector<int>> ans;
        vector<int> curr, next;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &x, const vector<int> &y) { return x[0] < y[0]; });
        curr = intervals[0];
        int ind = 1;
        int start = curr[0], end = curr[1];

        while (ind < intervals.size())
        {
            next = intervals[ind++];
            if (next[0] <= end)
                end = max(end, next[1]);
            else
            {
                ans.push_back({start, end});
                start = next[0];
                end = next[1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    // [1,3],[2,6],[8,10],[15,18]
    vector<vector<int>> nums = {{1, 4}, {0, 2}, {3, 5}};
    Solution solution = Solution();
    vector<vector<int>> res = solution.merge_1(nums);
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
