#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/**
 * 20 <= arr.length <= 1000
 * arr.length is a multiple of 20.
 * 0 <= arr[i] <= 105
 */
class Solution
{
public:
    double trimMean(vector<int> &arr)
    {
        int size = arr.size();
        sort(arr.begin(), arr.end());
        int left = size * 0.05, right = size * (1 - 0.05);
        double sum = 0;
        for (int i = left; i < right; i++)
        {
            sum += arr[i];
        }
        return sum / (right - left);
    }

    double trimMean_1(vector<int> &arr)
    {
        auto sz = arr.size();
        int skip = sz / 20;
        nth_element(begin(arr), begin(arr) + skip, end(arr));
        nth_element(begin(arr) + skip, begin(arr) + sz - skip, end(arr));
        return (double)accumulate(begin(arr) + skip, begin(arr) + sz - skip, 0) / (sz - skip * 2);
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {6, 0, 7, 0, 7, 5, 7, 8, 3, 4, 0, 7, 8, 1, 6, 8, 1, 1, 2, 4, 8, 1, 9, 5, 4, 3, 8, 5, 10, 8, 6, 6, 1, 0, 6, 10, 8, 2, 3, 4};
    cout << solution.trimMean_1(nums) << endl;
    system("pause");
    return 0;
}
