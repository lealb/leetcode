#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    /**
     * Approach 1: Left and Right product lists
     * Time complexity : O(N) where NN represents the number of elements in the input array. 
     * We use one iteration to construct the array L, 
     * one to construct the array RR and one last to construct the answeranswer array using LL and RR.
     * Space complexity : O(N) used up by the two intermediate arrays 
     * that we constructed to keep track of product of elements to the left and right
     */
    vector<int> productExceptSelf_0(vector<int> &nums)
    {
        // The length of the input array
        int length = nums.size();
        // The left and right arrays as described in the algorithm
        vector<int> L(length), R(length);
        // Final answer array to be returned
        vector<int> answer(length);

        // L[i] contains the product of all the elements to the left
        // Note: for the element at index '0', there are no elements to the left,
        // so L[0] would be 1
        L[0] = 1;
        for (int i = 1; i < length; i++)
        {
            // L[i - 1] already contains the product of elements to the left of 'i - 1'
            // Simply multiplying it with nums[i - 1] would give the product of all
            // elements to the left of index 'i'
            L[i] = nums[i - 1] * L[i - 1];
        }

        // R[i] contains the product of all the elements to the right
        // Note: for the element at index 'length - 1', there are no elements to the right,
        // so the R[length - 1] would be 1
        R[length - 1] = 1;
        for (int i = length - 2; i >= 0; i--)
        {

            // R[i + 1] already contains the product of elements to the right of 'i + 1'
            // Simply multiplying it with nums[i + 1] would give the product of all
            // elements to the right of index 'i'
            R[i] = nums[i + 1] * R[i + 1];
        }

        // Constructing the answer array
        for (int i = 0; i < length; i++)
        {
            // For the first element, R[i] would be product except self
            // For the last element of the array, product except self would be L[i]
            // Else, multiple product of all elements to the left and to the right
            answer[i] = L[i] * R[i];
        }
        return answer;
    }

    /**
     * Approach 2: O(1) space approach
     */
    vector<int> productExceptSelf_1(vector<int> &nums)
    {

        // The length of the input array
        int length = nums.size();
        // Final answer array to be returned
        vector<int> answer(length);

        // answer[i] contains the product of all the elements to the left
        // Note: for the element at index '0', there are no elements to the left,
        // so the answer[0] would be 1
        answer[0] = 1;
        for (int i = 1; i < length; i++)
        {

            // answer[i - 1] already contains the product of elements to the left of 'i - 1'
            // Simply multiplying it with nums[i - 1] would give the product of all
            // elements to the left of index 'i'
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R contains the product of all the elements to the right
        // Note: for the element at index 'length - 1', there are no elements to the right,
        // so the R would be 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--)
        {

            // For the index 'i', R would contain the
            // product of all elements to the right. We update R accordingly
            answer[i] = answer[i] * R;
            R *= nums[i];
        }
        return answer;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = solution.productExceptSelf_0(nums);
    for (auto r : res)
    {
        cout << r << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
