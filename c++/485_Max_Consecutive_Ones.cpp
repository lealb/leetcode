#include <iostream>
#include <vector>
using namespace std;
/**
 * 
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
*/
class Solution
{
public:
    /**
     * 	68 ms
     */
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int numsLen = nums.size();
        int count = 0, maxOnes = 0;
        for (int i = 0; i < numsLen; ++i)
        {

            if (1 == nums[i])
            {
                count++;
            }
            if (0 == nums[i] || numsLen - 1 == i)
            {
                maxOnes = count > maxOnes ? count : maxOnes;
                count = 0;
            }
        }
        return maxOnes;
    }
    int findMaxConsecutiveOnes_0(vector<int> &nums)
    {
        int maxCons = 0;
        int currCons = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                currCons++;
            }
            else
            {
                currCons = 0;
            }
            maxCons = maxCons < currCons ? currCons : maxCons;
        }
        return maxCons;
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << solution.findMaxConsecutiveOnes(nums) << endl;
    // system("pause");
    return 0;
}
