#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief 
 * 1 <= arr.length <= 10^4
 * 0 <= arr[i] <= 10^4
 * one pass
 * O(1) Space
 */
class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int N = arr.size();
        int ans = 0, base = 0;
        while (base < N)
        {
            int end = base;
            // if base is a left-boundary
            if (end + 1 < N && arr[end] < arr[end + 1])
            {
                // set end to the peak of this potential mountain
                while (end + 1 < N && arr[end] < arr[end + 1])
                    end++;
                // if end is really a peak..
                if (end + 1 < N && arr[end] > arr[end + 1])
                {
                    // set end to the right-boundary of mountain
                    while (end + 1 < N && arr[end] > arr[end + 1])
                        end++;
                    // record candidate answer
                    ans = max(ans, end - base + 1);
                }
            }
            base = max(end, base + 1);
        }
        return ans;
    }
    int longestMountain_1(vector<int> &arr)
    {
        int size = arr.size();
        int res = 0, up = 0, down = 0;
        for (int i = 1; i < size; ++i)
        {
            if (down && arr[i - 1] < arr[i] || arr[i - 1] == arr[i])
            {
                up = down = 0;
            }
            arr[i - 1] < arr[i] ? (up++) : (down++);
            // down += arr[i - 1] > arr[i];
            if (up && down)
            {
                res = max(res, up + down + 1);
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 1, 4, 7, 3, 2, 5};
    cout << solution.longestMountain_1(nums) << endl;
    system("pause");
    return 0;
}
