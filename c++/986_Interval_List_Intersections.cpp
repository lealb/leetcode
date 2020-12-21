#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        int aSize = A.size(), bSize = B.size();
        while (i < aSize && j < bSize)
        {
            // Let's check if A[i] intersects B[j].
            // low - the startpoint of the intersection
            // high - the endpoint of the intersection
            int low = max(A[i][0], B[j][0]);
            int high = min(A[i][1], B[j][1]);
            if (low <= high)
            {
                ans.push_back({low, high});
            }
            // Remove the interval with the smallest endpoint
            A[i][1] < B[j][1] ? i++ : j++;
        }
        return ans;
    }
    vector<vector<int>> intervalIntersection_1(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        if (A.empty() || B.empty())
        {
            return vector<vector<int>>();
        }
        int an = A.size(), bn = B.size(), i = 0, j = 0;
        vector<vector<int>> res;
        while (i < an && j < bn)
        {
            if (A[i][1] < B[j][0])
                ++i;
            else if (B[j][1] < A[i][0])
                ++j;
            else
            {
                res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
                A[i][1] < B[j][1] ? ++i : ++j;
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> A = {{0, 2}, {5, 10}, {13, 23}, {24, 25}}, B = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    vector<vector<int>> ans = solution.intervalIntersection(A, B);
    for (auto &v : ans)
    {
        cout << "[" << v[0] << "," << v[1] << "], ";
    }
    cout << endl;
    system("pause");
    return 0;
}
