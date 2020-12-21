#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * @brief 
 * A.length <= 30000
 * 0 <= S <= A.length
 * A[i] is either 0 or 1.
 * 
 */
class Solution
{
public:
    /**
     * @brief Approach 1: Index of Ones
     * Time:O(N)
     * Space: O(N)
     * @param A 
     * @param S 
     * @return int 
     */
    int numSubarraysWithSum(vector<int> &A, int S)
    {
        int su = 0;
        for (int x : A)
        {
            su += x;
        }

        // indexes[i] = location of i-th one (1 indexed)
        vector<int> indexes(su + 2);
        int t = 0, size = A.size();
        indexes[t++] = -1;
        for (int i = 0; i < size; ++i)
        {
            if (A[i] == 1)
            {
                indexes[t++] = i;
            }
        }
        indexes[t] = size;

        int ans = 0, indexSize = indexes.size();
        if (S == 0)
        {
            for (int i = 0; i < indexSize - 1; ++i)
            {
                // w: number of zeros between consecutive ones
                int w = indexes[i + 1] - indexes[i] - 1;
                ans += w * (w + 1) / 2;
            }
            return ans;
        }
        for (int i = 1; i < indexSize - S; ++i)
        {
            int j = i + S - 1;
            int left = indexes[i] - indexes[i - 1];
            int right = indexes[j + 1] - indexes[j];
            ans += left * right;
        }
        return ans;
    }
    int numSubarraysWithSum_1(vector<int> &A, int S)
    {
        int N = A.size();
        vector<int> pixfixSum(N + 1, 0);
        for (int i = 0; i < N; ++i)
        {
            pixfixSum[i + 1] = pixfixSum[i] + A[i];
        }
        unordered_map<int, int> count;
        int ans = 0;
        for (int x : pixfixSum)
        {
            ans += count.find(x) != count.end() ? count.at(x) : 0;
            count.insert({x + S, (count.find(x + S) != count.end() ? count.at(x + S) : 0) + 1});
        }
        return ans;
    }
    /**
     * @brief Approach 3: Three Pointer
     * 
     * @param A 
     * @param S 
     * @return int 
     */
    int numSubarraysWithSum_2(vector<int> &A, int S)
    {
        int iLo = 0, iHi = 0;
        int sumLo = 0, sumHi = 0;
        int ans = 0;

        for (int j = 0; j < A.size(); ++j)
        {
            // While sumLo is too big, iLo++
            sumLo += A[j];
            while (iLo < j && sumLo > S)
            {
                sumLo -= A[iLo++];
            }

            // While sumHi is too big, or equal and we can move, iHi++
            sumHi += A[j];
            while (iHi < j && (sumHi > S || sumHi == S && A[iHi] == 0))
            {
                sumHi -= A[iHi++];
            }

            if (sumLo == S)
            {
                ans += iHi - iLo + 1;
            }
        }
        return ans;
    }
    int numSubarraysWithSum_4(vector<int> &A, int S)
    {
        return countAtLeastK(A, S) - countAtLeastK(A, S + 1);
    }

    int countAtLeastK(vector<int> &A, int S)
    {
        int i = 0, j = 0, n = A.size(), sum = 0, ans = 0;
        while (j < n)
        {
            sum += A[j];
            while (i <= j && sum >= S)
            {
                sum -= A[i];
                i++;
            }
            ans += i;
            j++;
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> A = {1, 0, 1, 0, 1};
    int S = 2;
    cout << solution.numSubarraysWithSum_1(A, S) << endl;
    system("pause");
    return 0;
}
