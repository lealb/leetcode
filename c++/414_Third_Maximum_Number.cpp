#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * The time complexity must be in O(n).
 */
class Solution
{
public:
    // a >b>c  2 2 3
    void sortThird(int &a, int &b, int &c)
    {
        if (a < b)
        {
            swap(a, b);
        }
        if (a < c)
        {
            swap(a, c);
        }
        if (b < c)
        {
            swap(b, c);
        }
    }
    int thirdMax(vector<int> &nums)
    {
        int numsLen = nums.size();
        if (numsLen < 3)
        {
            return *max_element(nums.begin(), nums.end());
        }

        // vector<int> auxiliary = {nums[0], nums[1], nums[2]};
        // sort(auxiliary.begin(), auxiliary.end());
        // int firstMax = auxiliary[2];
        // int secondMax = auxiliary[1];
        // int thirdMax = auxiliary[0];
        int firstMax = nums[0], secondMax = nums[1], thirdMax = nums[2];
        sortThird(firstMax, secondMax, thirdMax);
        cout << firstMax << " " << secondMax << " " << thirdMax << endl;
        for (int i = 3; i < numsLen; ++i)
        {
            int n = nums[i];
            // update firstMax
            if (n > firstMax)
            {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = n;
            }

            else if (n < firstMax and n > secondMax)
            {
                thirdMax = secondMax;
                secondMax = n;
            }

            else if (n < secondMax and n > thirdMax)
            {
                thirdMax = n;
            }

            else if (secondMax == thirdMax and n < thirdMax)
            {
                thirdMax = n;
            }
        }
        return (firstMax == secondMax or secondMax == thirdMax) ? firstMax : thirdMax;
    }

    int thirdMax_1(vector<int> &nums)
    {

        long max = LONG_MIN, secondMax = LONG_MIN, thirdMax = LONG_MIN;
        for (auto &num : nums)
        {
            // if this no is > the largest (all 3 will get updated now)
            if (num > max)
            {
                thirdMax = secondMax;
                secondMax = max;
                max = num;
            }
            // else if it is between (2nd max, max)
            else if (num < max && num > secondMax)
            {
                thirdMax = secondMax;
                secondMax = num;
            }
            // else if it is between (3rd max, 2nd max)
            else if (num < secondMax && num > thirdMax)
            {
                thirdMax = num;
            }
        }
        // in problem it is mentioned that if there are < distinct 3 elements
        //then a 3rd max no cannot exist so we need to return the max no instead in that case
        return thirdMax == LONG_MIN ? max : thirdMax;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {2, 2, 3, 1};
    // cout << solution.thirdMax(nums) << endl;
    int a = 2, b = 2, c = 5;
    solution.sortThird(a, b, c);
    cout << a << " " << b << " " << c << " " << endl;
    system("pause");
    return 0;
}
