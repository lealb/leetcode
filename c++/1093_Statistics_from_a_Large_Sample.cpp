#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    /**
     * @brief 真心没看懂题目
     * 
     * @param count 
     * @return vector<double> 
     */
    vector<double> sampleStats(vector<int> &count)
    {
        double mini;
        double maxi;
        int n = count.size();
        for (int i = 0; i < n; i++)
        {
            if (count[i] != 0)
            {
                mini = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (count[i] != 0)
            {
                maxi = i;
                break;
            }
        }
        double mod;
        int cur = 0;
        double tol = 0;
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            tol += i * count[i];
            num += count[i];
            if (count[i] > cur)
            {
                cur = count[i];
                mod = i;
            }
        }
        double med;
        double ave = tol / num;
        int start = 0;
        int end = n - 1;
        while (start < end - 1)
        {
            while (count[start] == 0)
            {
                start++;
            }
            while (count[end] == 0)
            {
                end--;
            }
            if (count[start] < count[end])
            {
                count[end] -= count[start];
                count[start] = 0;
                start++;
            }
            else
            {
                count[start] -= count[end];
                count[end] = 0;
                if (count[start] == 0)
                {
                    start++;
                }
                end--;
            }
        }

        med = (static_cast<double>(count[start]) + static_cast<double>(count[end])) / 2.0;
        if (count[start] > count[end])
        {
            med = start;
        }
        if (count[end] > count[start])
        {
            med = end;
        }
        if (count[start] == count[end])
        {
            med = static_cast<double>(start + end) / 2.0;
        }
        return {mini, maxi, ave, med, mod};
    }
    vector<double> sampleStats_1(vector<int> &count)
    {
        vector<double> ans(5);
        int i = 0, j = 255;
        while (i < 256)
        {
            if (count[i] != 0)
            {
                ans[0] = i;
                break;
            }
            i++;
        }
        while (j >= 0)
        {
            if (count[j] != 0)
            {
                ans[1] = j;
                break;
            }
            j--;
        }
        double x = 0, y = 0, m = 0, z = 0;
        for (int i = 0; i < 256; i++)
        {
            if (count[i] != 0)
            {
                x += (count[i] * i);
                y += count[i];
            }
            if (count[i] > z)
            {
                z = count[i];
                m = i;
            }
        }
        ans[2] = x / y;
        ans[4] = m;
        long int a = 0, b = y;
        for (int i = 0; i < 256; i++)
        {
            a += count[i];
            if (a >= (b + 1) / 2)
            {
                x = i;
                if (a >= (b + 1) / 2 + 1)
                {
                    y = i;
                }
                else
                    y = i + 1;
                break;
            }
        }
        if (b % 2 != 0)
        {
            ans[3] = x;
        }
        else
        {
            ans[3] = (x + y) / 2;
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {0, 1, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<double> ans = solution.sampleStats(nums);
    for (auto &v : ans)
    {
        cout << v << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
