#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int binaryGap(int n)
    {
        vector<int> binary;
        int index = -1;
        while (n > 0)
        {
            index++;
            int v = n % 2;
            cout << index << " " << v << endl;
            if (v)
            {
                binary.push_back(index);
            }
            n /= 2;
        }
        // 翻转
        int ans = 0;
        for (int i = 0; i < index - 1; i++)
        {
            ans = ans > binary[i + 1] - binary[i] ? ans : binary[i + 1] - binary[i];
        }
        return ans;
    }
    
    /**
     * Time Complexity: O(logN). 
     * Note that logN is the number of digits in the binary representation of N.
     * Space Complexity: O(logN), the space used by A.
     */ 
    int binaryGap_1(int n)
    {
        vector<int> binary(32);
        int t = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (((n >> i) & 1) != 0)
            {
                binary[t++] = i;
            }
        }

        int ans = 0;
        for (int i = 0; i < t - 1; ++i)
        {
            ans = ans > binary[i + 1] - binary[i] ? ans : binary[i + 1] - binary[i];
        }
        return ans;
    }

    /**
     * Time Complexity: O(logN).
     *  Note that  NlogN is the number of digits in the binary representation of N.
     * Space Complexity: O(1).
     */
    int binaryGap_2(int n)
    {
        int last = -1, ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (((n >> i) & 1) > 0)
            {
                if (last >= 0)
                {
                    ans = max(ans, i - last);
                }
                last = i;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.binaryGap(22);
    cout << endl;
    system("pause");
    return 0;
}
