#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/**
 * n == height.length
 * 0 <= n <= 3 * 10^4
 * 0 <= height[i] <= 10^5
 */
class Solution
{
public:
    /**
     * Approach 1: Brute force
     * Time complexity: O(n^2)
     *  For each element of array, we iterate the left and right parts.
     * Space complexity: O(1) extra space
     */
    int trap_0(vector<int> &height)
    {
        int ans = 0;
        int size = height.size();
        if (0 == size)
        {
            return 0;
        }
        for (int i = 0; i < size; i++)
        {
            int left_max=0,right_max=0;
        }
        
    }
    /**
     * Approach 2: Dynamic Programming
     * Time complexity: O(n)
     * We store the maximum heights upto a point using 2 iterations of O(n) each.
     * We finally update ans using the stored values in O(n).
     * Space complexity: O(n) extra space.
     * 
     */
    int trap_1(vector<int> &height)
    {
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++)
        {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--)
        {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; i++)
        {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
    /**
     * Approach 3: Using stacks
     * Time complexity: O(n).
     * Single iteration of O(n) in which each bar can be touched at most 
     * twice(due to insertion and deletion from stack) and insertion and deletion from 
     * stack takes O(1) time.
     * Space complexity: O(n). 
     * Stack can take upto O(n) space in case of stairs-like or flat structure.
     */
    int trap_2(vector<int> &height)
    {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size())
        {
            while (!st.empty() && height[current] > height[st.top()])
            {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
    /**
     * Approach 4: Using 2 pointers
     * Time complexity: O(n). Single iteration of O(n).
     * Space complexity: O(1) extra space. 
     * Only constant space required for left, right, left_max and right_max.
     */
    int trap_3(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else
            {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << solution.trap_1(nums) << endl;
    system("pause");
    return 0;
}
