#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
/**
 * @brief 
 * 3 <= A.length <= 3000
 * 0 <= A[i] <= 100
 * 0 <= target <= 300
 */
class Solution
{
public:
    /**
     * @brief Approach 1: Three Pointer
     * Time Complexity: O(N^2)
     * Space: O(1)
     * @param A 
     * @param target 
     * @return int 
     */
    int threeSumMulti(vector<int> &A, int target)
    {
        int MOD = pow(10, 9) + 7;
        long ans = 0;
        sort(A.begin(), A.end());
        int size = A.size();
        for (int i = 0; i < size; ++i)
        {
            // We'll try to find the number of i < j < k
            // with A[j] + A[k] == T, where T = target - A[i].

            // The below is a "two sum with multiplicity".
            int T = target - A[i];
            int j = i + 1, k = size - 1;

            while (j < k)
            {
                // These steps proceed as in a typical two-sum.
                if (A[j] + A[k] < T)
                    j++;
                else if (A[j] + A[k] > T)
                    k--;
                else if (A[j] != A[k])
                { // We have A[j] + A[k] == T.
                    // Let's count "left": the number of A[j] == A[j+1] == A[j+2] == ...
                    // And similarly for "right".
                    int left = 1, right = 1;
                    while (j + 1 < k && A[j] == A[j + 1])
                    {
                        left++;
                        j++;
                    }
                    while (k - 1 > j && A[k] == A[k - 1])
                    {
                        right++;
                        k--;
                    }

                    ans += left * right;
                    ans %= MOD;
                    j++;
                    k--;
                }
                else
                {
                    // M = k - j + 1
                    // We contributed M * (M-1) / 2 pairs.
                    ans += (k - j + 1) * (k - j) / 2;
                    ans %= MOD;
                    break;
                }
            }
        }
        return static_cast<int>(ans);
    }
    /**
     * @brief Approach 2: Counting with Cases
     * Time: O(N+W^2)
     * @param A 
     * @param target 
     * @return int 
     */
    int threeSumMulti_1(vector<int> &A, int target)
    {
        int MOD = pow(10, 9) + 7;
        vector<long> count(101);
        for (int x : A)
        {
            count[x]++;
        }

        long ans = 0;

        // All different
        for (int x = 0; x <= 100; ++x)
            for (int y = x + 1; y <= 100; ++y)
            {
                int z = target - x - y;
                if (y < z && z <= 100)
                {
                    ans += count[x] * count[y] * count[z];
                    ans %= MOD;
                }
            }

        // x == y != z
        for (int x = 0; x <= 100; ++x)
        {
            int z = target - 2 * x;
            if (x < z && z <= 100)
            {
                ans += count[x] * (count[x] - 1) / 2 * count[z];
                ans %= MOD;
            }
        }
        // x != y == z
        for (int x = 0; x <= 100; ++x)
        {
            if (target % 2 == x % 2)
            {
                int y = (target - x) / 2;
                if (x < y && y <= 100)
                {
                    ans += count[x] * count[y] * (count[y] - 1) / 2;
                    ans %= MOD;
                }
            }
        }
        // x == y == z
        if (target % 3 == 0)
        {
            int x = target / 3;
            if (0 <= x && x <= 100)
            {
                ans += count[x] * (count[x] - 1) * (count[x] - 2) / 6;
                ans %= MOD;
            }
        }
        return static_cast<int>(ans);
    }
    /**
     * @brief Approach 3: Adapt from Three Sum
     * Time Complexity: O(N^2)
     * @param A 
     * @param target 
     * @return int 
     */
    int threeSumMulti_2(vector<int> &A, int target)
    {
        int MOD = 1e9 + 7;

        // Initializing as long saves us the trouble of
        // managing count[x] * count[y] * count[z] overflowing later.
        vector<long> count(101);
        int uniq = 0;
        for (int x : A)
        {
            count[x]++;
            if (count[x] == 1)
            {
                uniq++;
            }
        }

        vector<int> keys(uniq);
        int t = 0;
        for (int i = 0; i <= 100; ++i)
            if (count[i] > 0)
                keys[t++] = i;

        long ans = 0;
        // Now, let's do a 3sum on "keys", for i <= j <= k.
        // We will use count to add the correct contribution to ans.
        int size = keys.size();
        for (int i = 0; i < size; ++i)
        {
            int x = keys[i];
            int T = target - x;
            int j = i, k = size - 1;
            while (j <= k)
            {
                int y = keys[j], z = keys[k];
                if (y + z < T)
                {
                    j++;
                }
                else if (y + z > T)
                {
                    k--;
                }
                else
                { // # x+y+z == T, now calc the size of the contribution
                    if (i < j && j < k)
                    {
                        ans += count[x] * count[y] * count[z];
                    }
                    else if (i == j && j < k)
                    {
                        ans += count[x] * (count[x] - 1) / 2 * count[z];
                    }
                    else if (i < j && j == k)
                    {
                        ans += count[x] * count[y] * (count[y] - 1) / 2;
                    }
                    else
                    { // i == j == k
                        ans += count[x] * (count[x] - 1) * (count[x] - 2) / 6;
                    }
                    ans %= MOD;
                    j++;
                    k--;
                }
            }
        }
        return static_cast<int>(ans);
    }
    int threeSumMulti_3(vector<int> &A, int target)
    {
        int mod = 1e9 + 7;
        vector<long> count(101, 0);
        for (auto x : A)
        {
            count[x] += 1;
        }
        long res = 0;
        for (int i = 0; i <= target; i++)
        {
            for (int j = i; j <= target; j++)
            {
                int k = target - i - j;
                if (k < j || k >= count.size())
                    continue;
                if (count[i] == 0 || count[j] == 0 || count[k] == 0)
                    continue;
                if (i == j && j == k && count[i] >= 3)
                {
                    res = (res + count[i] * (count[i] - 1) * (count[i] - 2) / 6) % mod;
                }
                else if (i == j && i != k && count[i] >= 2)
                {
                    res = (res + count[k] * count[i] * (count[i] - 1) / 2) % mod;
                }

                else if (j == k && i != k && count[j] >= 2)
                {
                    res = (res + count[i] * (count[j] - 1) * count[k] / 2) % mod;
                }

                else if (i != j && j != k && i != k)
                {
                    res = (res + count[i] * count[j] * count[k]) % mod;
                }
            }
        }

        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> A = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int target = 8;
    cout << solution.threeSumMulti(A, target) << endl;
    system("pause");
    return 0;
}
