#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// O(n^2) time, O(1) space
vector<int> twoSum_1(vector<int> &nums, int target)
{
    int size = nums.size();
    vector<int> res = {0, 0};
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (target == nums[i] + nums[j])
            {
                res[0] = i;
                res[1] = j;
            }
        }
    }
    return res;
}
//O(nlog(n)) time, O(1) space
vector<int> twoSum_2(vector<int> &nums, int target)
{
    int size = nums.size();
    vector<int> O_nums = nums;
    sort(nums.begin(), nums.end());
    vector<int> res = {0, 0};
    // 二分查找
    int vLow = nums[0];
    int vHigh = nums[size - 1];
    for (int low = 0, high = size - 1; low < high && target != vLow + vHigh;)
    {
        if (target < nums[low] + nums[high])
        {
            --high;
            vHigh = nums[high];
            cout << high << endl;
        }
        else
        {
            ++low;
            vLow = nums[low];
            cout << low << endl;
        }
    }
    // res[0] = getIndex(O_nums, vLow);
    // res[1] = getIndex(O_nums, vHigh);
    return res;
}
// hash map //O(n) time, O(n) space
vector<int> twoSum_3(vector<int> &nums, int target)
{
    unordered_map<int, int> m;
    for (int i{0}; i < nums.size(); i++)
    {
        if (m.find(target - nums[i]) != m.end())
            return {m[target - nums[i]], i};
        m[nums[i]] = i;
    }
    return {-1,-1};
}
int main(int argc, char const *argv[])
{
    vector<int> nums = {21, 2, 3, 1, 3};
    vector<int> res = twoSum_3(nums, 6);
    int size = res.size();
    for (int i = 0; i < size; i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
