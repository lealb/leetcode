#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    /**
     * Time: 60ms
     */
    int jump(vector<int> &nums)
    {
        unordered_map<int, pair<int, int>> map;
        map[0] = pair<int, int>(0, 0);
        int step = 0;
        while (true)
        {
            int start = map[step].first;
            int end = map[step].second;
            if (end == nums.size() - 1)
            {
                return step;
            }
            int tmpEnd = -1;
            for (int i = start; i <= end; i++)
            {
                tmpEnd = max(tmpEnd, nums[i] + i);
            }
            map[++step] = pair<int, int>(end + 1, min(int(nums.size() - 1), tmpEnd));
        }
    }
    /**
     * Time:20ms
     */
    int jump_1(vector<int> &nums)
    {
        int jump = 0, pos = 0, des = 0, n = nums.size() - 1;
        for (int i = 0; i < n; i++)
        {
            des = max(des, i + nums[i]);
            if (pos == i)
            {
                pos = des;
                jump++;
            }
        }
        return jump;
    }
    /**
     * Time: 24ms
     */
    int jump_2(vector<int> &nums)
    {
        int n = nums.size();
        int step = 0, head = 0, tail = 0;
        while (tail < n - 1 && head <= tail)
        {
            int tail_new = tail;
            for (int i = head; i <= tail; i++)
            {
                tail_new = max(tail_new, nums[i] + i);
            }
            head = tail + 1;
            tail = tail_new;
            step++;
        }
        return step;
    }
    /**
     * Time:24ms
     */
    int jump_4(vector<int> &nums)
    {
        int end = 0;
        int farthest = 0;
        int jump = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            farthest = max(farthest, nums[i] + i);
            if (end == i)
            { // Time to jump
                end = farthest;
                jump++;
            }
        }
        return jump;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << solution.jump(nums) << endl;
    system("pause");
    return 0;
}
