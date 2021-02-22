#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        //sorted
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
    
    /**
     * @brief time: O(nlogn), space: O(1)
     * 
     * @param nums 
     * @param k 
     * @return int 
     */
    int findKthLargest_0(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++)
        {
            int max = pq.top();
            if (nums[i] > max)
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << solution.findKthLargest(nums, k) << endl;
    system("pause");
    return 0;
}
