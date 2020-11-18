#include <iostream>
#include <vector>
using namespace std;
/**
 * -1000 ≤ nums[i] ≤ 1000
 * nums[i] ≠ 0
 * 1 ≤ nums.length ≤ 5000
 */
class Solution
{
public:
    bool circularArrayLoop(vector<int> &nums)
    {
        int N = nums.size();
        for (int i = 0; i < N; i++)
        {
            vector<bool> visited(N, false);
            if (foundCycle(i, nums, visited))
                return true;
        }

        return false;
    }

    bool foundCycle(int start, vector<int> &nums, vector<bool> &visited)
    {
        int i = start, N = nums.size();
        bool forward = nums[start] > 0 ? true : false;
        int len = 1;
        while (!visited[i])
        {
            visited[i] = true;
            int step = nums[i];
            if (forward ^ (step > 0 ? true : false))
                return false;

            i = (i + step + N) % N;
            if (i == start && len > 1)
                return true;
            len++;
        }

        return false;
    }
     bool circularArrayLoop_1(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (isCycle(nums, i, -1, nums[i])) {
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(vector<int>& nums, int start, int par, int dir) {
        if (hasNoCycle(nums, start)) {
            return false;
        }

        if (par == start) {
            nums[start] = 1002;
            return false;
        }
        
        if (nums[start] == 0) {
            return true;
        }
        
        
        if (nums[start] * dir < 0) {
            return false;
        }
        
        int val = nums[start];
        int child = getChild(nums, start);
        nums[start] = 0;        
        
        if (isCycle(nums, child, start, val)) {
            return true;
        }
        
        nums[start] = 1002;
        return false;
    }
    
    int getChild(vector<int>& nums, int i) {
        return (nums[i] + i + nums.size()) % nums.size();
    }
    
    bool hasNoCycle(vector<int>& nums, int i) {
        return nums[i] == 1002;
    }
};
int main()
{
    Solution solution;

    system("pause");
    return 0;
}
