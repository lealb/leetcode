#include <iostream>
#include <vector>

using namespace std;
/**
 * The input array won't violate no-adjacent-flowers rule.
 * The input array size is in the range of [1, 20000].
 * n is a non-negative integer which won't exceed the input array size.
 */
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int size = flowerbed.size(), count = 0;
        for (int i = 0; i < size; i++)
        {
            if ((i == 0 && flowerbed[i + 1] != 0) || (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) || (i = size - 1 && flowerbed[i - 1] != 0))
            {
                flowerbed[i] = 1;
                count++;
            }
        }
        // cout << count << endl;
        return count >= n;
    }
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int i = 0, count = 0, size = flowerbed.size();
        while (i < size)
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                count++;
            }
            i++;
        }
        return count >= n;
    }
    bool canPlaceFlowers_1(vector<int> &flowerbed, int n)
    {
        int i = 0, count = 0, size = flowerbed.size();
        while (i < size)
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i++] = 1;
                count++;
            }
            if (count >= n)
            {
                return true;
            }
            i++;
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 0, 0, 0, 1};
    cout << solution.canPlaceFlowers(nums, 2) << endl;
    system("pause");
    return 0;
}
