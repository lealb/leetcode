#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    /**
     * Approach #1: Brute Force with Initial Character Map 
     * T:O(M∗N∗min(M,N))
     */
    int findLength_0(vector<int> &A, vector<int> &B)
    {
        int ans = 0, aSize = A.size(), bSize = B.size();
        unordered_map<int, vector<int>> Bstarts;
        for (int j = 0; j < bSize; j++)
        {
            // Bstarts.computeIfAbsent(B[j], x->new ArrayList()).add(j);
        }

        for (int i = 0; i < aSize; i++)
            if (Bstarts.find(A[i]) != Bstarts.end())
            {
                for (int j : Bstarts.at(A[i]))
                {
                    int k = 0;
                    while (i + k < aSize && j + k < bSize && A[i + k] == B[j + k])
                    {
                        k++;
                    }
                    ans = max(ans, k);
                }
            }
        return ans;
    }

    /**
     * Approach #3: Dynamic Programming 
     * T:O(M*N)
     * S:O(M*N)
     */
    int findLength_1(vector<int> &A, vector<int> &B)
    {
        int ans = 0;
        int aSize = A.size(), bSize = B.size();
        vector<vector<int>> memo(aSize + 1, vector<int>(bSize + 1));
        for (int i = aSize - 1; i >= 0; --i)
        {
            for (int j = bSize - 1; j >= 0; --j)
            {
                if (A[i] == B[j])
                {
                    memo[i][j] = memo[i + 1][j + 1] + 1;
                    if (ans < memo[i][j])
                    {
                        ans = memo[i][j];
                    }
                }
            }
        }
        return ans;
    }
    long base = 573;
    long MOD = 1000000007;

    bool isPossible(int MidVal, vector<long> &hashVal_A, vector<long> &hashVal_B, vector<long> &power_A, vector<long> &power_B)
    {

        unordered_set<long> us;

        for (int i = MidVal; i < hashVal_A.size(); i++)
        {
            int end = i;
            int start = i - MidVal;

            int currAns = (hashVal_A[end] - (hashVal_A[start] * power_A[end - start]) % MOD + MOD) % MOD;

            us.insert(currAns);
        }

        for (int i = MidVal; i < hashVal_B.size(); i++)
        {
            int end = i;
            int start = i - MidVal;

            int currAns = (hashVal_B[end] - (hashVal_B[start] * power_B[end - start]) % MOD + MOD) % MOD;
            if (us.find(currAns) != us.end())
                return true;
        }

        return false;
    }
    /**
     * O((M+N)∗log(min(M,N)))
     */
    int findLength_2(vector<int> &A, vector<int> &B)
    {

        vector<long> hashVal_A(A.size() + 1, 0);
        vector<long> hashVal_B(B.size() + 1, 0);

        vector<long> power_A(A.size() + 1, 1);
        vector<long> power_B(B.size() + 1, 1);

        for (int i = 0; i < A.size(); i++)
        {
            hashVal_A[i + 1] = (hashVal_A[i] * base + A[i]) % MOD;
            power_A[i + 1] = (power_A[i] * base) % MOD;
        }

        for (int i = 0; i < B.size(); i++)
        {
            hashVal_B[i + 1] = (hashVal_B[i] * base + B[i]) % MOD;
            power_B[i + 1] = (power_B[i] * base) % MOD;
        }

        int low = 0, high = min(A.size(), B.size()) + 1;

        while (low < high)
        {
            int mid = (high + low + 1) / 2;

            if (isPossible(mid, hashVal_A, hashVal_B, power_A, power_B))
                low = mid;
            else
                high = mid - 1;
        }

        return low;
    }
    const int p = 113;
    void fill(unordered_set<unsigned int> &hasB, vector<int> &b, int md, int n)
    {
        unsigned int hashb = 0, del = 1;
        for (int i = 0; i < md; ++i)
        {
            hashb = hashb * p + b[i];
            if (i)
                del *= p;
        }
        hasB.insert(hashb);
        for (int i = 1; i + md - 1 < n; ++i)
        {
            hashb -= del * b[i - 1];
            unsigned del = 1;
            hashb = hashb * p + b[i + md - 1];
            hasB.insert(hashb);
        }
    }
    int findLength_4(vector<int> &a, vector<int> &b)
    {

        int n = min(a.size(), b.size());
        int l = 1, r = n, f = 0;
        while (l <= r)
        {
            int md = (l + r) >> 1;
            unsigned int hasha = 0, del = 1;
            unordered_set<unsigned int> hasB;
            fill(hasB, b, md, n);
            for (int i = 0; i < md; ++i)
            {
                hasha = hasha * p + a[i];
                if (i)
                    del *= p;
            }
            bool found = hasB.find(hasha) != hasB.end();
            for (int i = 1; i + md - 1 < n && !found; ++i)
            {
                hasha -= del * a[i - 1];
                hasha = hasha * p + a[i + md - 1];
                if (hasB.find(hasha) != hasB.end())
                    found = 1;
            }
            if (found)
            {
                l = md + 1;
                f = md;
            }
            else
            {
                r = md - 1;
            }
        }
        return f;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
