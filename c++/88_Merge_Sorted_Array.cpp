#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * -10^9 <= nums1[i], nums2[i] <= 10^9
 * nums1.length == m + n
 * nums2.length == n
 */
class Solution
{
public:
    /**
     * Time: 4ms stl
     * Space: 9.3m
     */
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        copy(nums2.begin(), nums2.end(), nums1.begin() + m);
        sort(nums1.begin(), nums1.end());
    }
    void merge_1(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int index = m + n - 1; index >= 0; --index)
        {
            // while we have valid pointers for n & m, take
            // the biggest at each location and place it in
            // the position at index
            if (m > 0 && n > 0)
            {
                if (nums1[m - 1] >= nums2[n - 1])
                {
                    nums1[index] = nums1[--m];
                }
                else
                {
                    nums1[index] = nums2[--n];
                }
            }
            else if (n > 0)
            {
                // otherwise just finish merging the second
                // set and we're done
                nums1[index] = nums2[--n];
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    solution.merge_1(nums1, 3, nums2, 3);
    for (size_t i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
