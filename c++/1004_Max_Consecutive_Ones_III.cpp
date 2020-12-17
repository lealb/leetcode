#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        int ans = INT_MIN;
        int l = 0, r = 0;
        int count = 0;
        int flag = 0;
        while (r < A.size())
        {
            if (A[r] == 0)
                count++;
            while (count > K && l < r)
            {
                if (A[l] == 0)
                    count--;
                l++;
            }
            if (A[r] == 1)
                flag = 1;
            ans = max(ans, r - l + 1);
            r++;
        }
        if (ans == INT_MIN || flag == 0)
            return 0;

        return ans;
    }
    int longestOnes_1(vector<int> &A, int K)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int space = 0;
        int i = 0, j = 0;
        int res = 0;
        while (j < A.size())
        {
            for (; j < A.size(); j++)
            {
                if (A[j] == 0)
                {
                    if (space == K)
                        break;
                    space++;
                }
            }

            res = max(res, j - i);
            for (; i <= j && i < A.size() && space == K; i++)
            {
                if (A[i] == 0)
                {
                    space--;
                }
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{

    system("pause");
    return 0;
}
