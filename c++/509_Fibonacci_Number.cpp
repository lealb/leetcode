#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
/**
 * https://leetcode.com/problems/fibonacci-number/solution/
 */
class Solution
{
public:
    /**
     * Approach 1: Recursion
     * Time complexity : O(2^N)
     *  This is the slowest way to solve the Fibonacci Sequence because 
     *  it takes exponential time. The amount of operations needed, 
     *  for each level of recursion, grows exponentially as the depth approaches N.
     * Space complexity : O(N)
     * We need space proportionate to N to account for the max size of the stack, 
     * in memory. This stack keeps track of the function calls to fib(N).
     * This has the potential to be bad in cases that there isn't enough physical memory 
     * to handle the increasingly growing stack, leading to a StackOverflowError. 
     * The Java docs have a good explanation of this,
     * describing it as an error that occurs because an application recurses too deeply.
     */
    int fib_1(int N)
    {
        if (1 >= N)
        {
            return N;
        }
        return fib_1(N - 1) + fib_1(N - 2);
    }
    /**
     * Approach 2: Bottom-Up Approach using Memoization
     * Time complexity : O(N). 
     * Each number, starting at 2 up to and including N, is visited, 
     * computed and then stored for O(1)O(1) access later on.
     * Space complexity : O(N). The size of the data structure is proportionate to N.
     */
    int fib_2(int N)
    {
        if (N <= 1)
        {
            return N;
        }
        vector<int> cache(N + 1);
        cache[1] = 1;

        for (int i = 2; i <= N; i++)
        {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
        return cache[N];
    }
    int memoize(int N)
    {
        vector<int> cache(N + 1);
        cache[1] = 1;

        for (int i = 2; i <= N; i++)
        {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
        return cache[N];
    }

    /**
     * Approach 3: Iterative Top-Down Approach
     * Time complexity : O(N).
     *  Each value from 2 to N will be visited at least once. 
     * The time it takes to do this is directly proportionate to 
     * N where N is the Fibonacci Number we are looking to compute.
     * Space complexity : O(1)O(1). This requires 1 unit of 
     * Space for the integer N and 3 units of Space to store the computed values 
     * (curr, prev1 and prev2) for every loop iteration.
     * The amount of Space doesn't change so this is constant Space complexity.
     */
    int fib_3(int N)
    {
        if (N == 0)
        {
            return 0;
        }
        int prev = 0;
        int curr = 1;
        for (int i = 2; i <= N; ++i)
        {
            int temp = curr + prev;
            prev = curr;
            curr = temp;
        }
        return curr;
    }

    /**
     * Approach 4: Matrix Exponentiation
     */
    int fib_4(int N)
    {
        if (N <= 1)
        {
            return N;
        }
        vector<vector<int>> A = {{1, 1}, {1, 0}};
        matrixPower(A, N - 1);

        return A[0][0];
    }

    void matrixPower(vector<vector<int>> &A, int N)
    {
        if (N <= 1)
        {
            return;
        }
        matrixPower(A, N / 2);
        multiply(A, A);

        vector<vector<int>> B = {{1, 1}, {1, 0}};
        if (N % 2 != 0)
        {
            multiply(A, B);
        }
    }

    void multiply(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int x = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        int y = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        int z = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        int w = A[1][0] * B[0][1] + A[1][1] * B[1][1];

        A[0][0] = x;
        A[0][1] = y;
        A[1][0] = z;
        A[1][1] = w;
    }

    /**
     * Approach 5: Math
     */
    int fib_5(int N)
    {
        double goldenRatio = (1 + sqrt(5)) / 2;
        return (int)round(pow(goldenRatio, N) / sqrt(5));
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.fib_5(10) << endl;
    system("pause");
    return 0;
}
