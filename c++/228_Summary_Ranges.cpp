#include <iostream>
#include <vector>

using namespace std;
/**
 * 0 <= nums.length <= 20
 * -2^31 <= nums[i] <= 2^31 - 1
 * All the values of nums are unique.
 * nums is sorted in ascending order.
 */
class Solution
{
public:
    /**
     *  slice
     * Time: O(n)
     * Space: O(1)
     */
    vector<string> summaryRanges(vector<int> &nums)
    {
        int numsLen = nums.size();
        // start: start of window, end: next index of window
        // [start, end)
        int start = 0, end = 1;
        vector<string> result;

        while (end <= numsLen)
        {
            // find the window of consecutive numbers
            while (end < numsLen && (long)nums[end] - nums[end - 1] == 1)
            {
                ++end;
            }
            // add the interval
            if (nums[start] != nums[end - 1])
            {
                result.emplace_back(to_string(nums[start]) + "->" + to_string(nums[end - 1]));
            }
            // single element window
            else
            {
                result.emplace_back(to_string(nums[start]));
            }
            start = end;
            ++end;
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
