#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /**
     * @brief sorted
     * O(NlogN)
     * 
     * @param nums 
     */
    void sortColors(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
    }

    /**
     * @brief 
     * Time: O(n)
     * Space: O(1)
     * count ++
     * @param nums 
     */
    void sortColors_1(vector<int> &nums)
    {
        int ones = 0, zeros = 0, twos = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 0)
                zeros++;
            else if (nums[i] == 1)
                ones++;
            else
                twos++;
        }
        int i = 0;
        for (; i < zeros; i++)
            nums[i] = 0;
        for (; i < ones + zeros; i++)
            nums[i] = 1;
        for (; i < nums.size(); i++)
            nums[i] = 2;
    }
    void sortColors_2(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        int mid = 0;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            // 2
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    solution.sortColors_2(nums);
    for (auto n : nums)
    {
        cout << n << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
