#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    /**
     * Time complexity : O(n). We traverse the numsnums array of size nn once only.
     * Space complexity : O(1). Constant extra space is used.
     */
    int findPeakElement_0(vector<int> &nums)
    {
        int numsLen = nums.size();
        for (int i = 0; i < numsLen - 1; i++)
        {
            if (nums[i] > nums[i + 1])
                return i;
        }
        return numsLen - 1;
    }

    int findPeakElement_1(vector<int> &nums)
    {
        return search(nums, 0, nums.size() - 1);
    }
    int search(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1])
            return search(nums, l, mid);
        return search(nums, mid + 1, r);
    }

    int findPeakElement_2(vector<int> &nums))
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << solution.findPeakElement_0(nums) << endl;
    // system("pause");
    return 0;
}
