#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        if (nums.empty())
        {
            return 0;
        }
        int i = n - 1, j = n - 1;
        while (i >= 0)
        {
            if (nums[i] == val)
            {
                swap(nums[i], nums[j]);
                j--;
            }
            i--;
        }
        while (!nums.empty() && nums.back() == val)
        {
            nums.pop_back();
        }
        return nums.size();
    }
    int removeElement_1(vector<int> &nums, int val)
    {
        return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
