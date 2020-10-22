#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 */
class Solution
{
public:
    /**
     * Brute force
     */
    int specialArray(vector<int> &nums)
    {
        int size = nums.size();
        for (int i = 1; i < 1000; i++)
        {
            int cnt = 0;
            for (int j = 0; j < size; j++)
            {
                if (nums[j] >= i)
                    cnt++;
            }
            if (cnt == i)
                return i;
        }
        return -1;
    }

    int specialArray_1(vector<int> &nums)
    {
        int arr[1000 + 1] = {0};
        for (int num : nums)
            arr[num]++;
        int total = nums.size();
        for (int i = 0; i <= 1000; i++)
        {
            if (i == total)
                return i;
            total -= arr[i];
        }
        return -1;
    }

    int specialArray_2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[j] >= i)
                {
                    if (n - j == i)
                        return i;
                    else
                        break;
                }
            }
        }
        return -1;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
