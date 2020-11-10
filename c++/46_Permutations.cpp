#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /**
     * Time:4ms
     */
    vector<vector<int>> permute(vector<int> &nums)
    {
        int len = nums.size();
        if (1 >= len)
        {
            return {nums};
        }
        vector<vector<int>> answer;
        permute(answer, nums, 0, len - 1);
        return answer;
    }
    void permute(vector<vector<int>> &answer, vector<int> this_arr, int i, int j)
    {
        if (i == j)
        {
            return answer.push_back(this_arr);
        }
        for (int x = i; x <= j; x++)
        {
            swap(this_arr[x], this_arr[i]);
            permute(answer, this_arr, (i + 1), j);
            swap(this_arr[x], this_arr[i]);
        }
    }
    vector<vector<int>> permute_1(vector<int> &nums)
    {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        v.push_back(nums);
        while (next_permutation(nums.begin(), nums.end()))
            v.push_back(nums);
        return v;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3};
    Solution solution = Solution();
    vector<vector<int>> res = solution.permute(nums);
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
