#include <iostream>
#include <vector>

using namespace std;
/**
 * 1 <= n <= 9
 * 1 <= k <= n!
*/
class Solution
{
public:
    string getPermutation_0(int n, int k)
    {
        string result = "";
        vector<int> nums(n);

        for (int i = 1; i <= n; i++)
        {
            nums[i - 1] = i;
        }

        k--;
        while (k)
        {
            int permute = 1;
            for (int i = 1; i < n; i++)
            {
                permute *= i;
            }

            int pos = k / permute;
            k = k % permute;

            result += to_string(nums[pos]);
            nums.erase(nums.begin() + pos);
            n -= 1;
        }

        for (auto &i : nums)
        {
            result += to_string(i);
        }

        return result;
    }
    string getPermutation_1(int n, int k)
    {

        string a = "";
        for (int i = 1; i <= n; i++)
        {
            a += to_string(i);
        }
        vector<int> fact(n + 1);
        fact[0] = 1;
        // get N!
        for (int i = 1; i <= n; i++)
        {
            fact[i] = fact[i - 1] * i;
        }
        // a is first Permutation Sequence
        k--;
        string ans = "";
        for (int i = n - 1; i >= 0; i--)
        {
            int index = k / fact[i];
            k %= fact[i];
            ans += a[index];
            a.erase(a.begin() + index);
        }
        return ans;
    }

    vector<string> permutation(vector<int> &arr, int len, int index = 0)
    {
        vector<string> ans;
        if (index == len)
        {
            string str = "";
            for (int i = 0; i < len; ++i)
            {
                str += to_string(arr[i]);
            }
            // cout << str << endl;
            ans.push_back(str);
        }
        else
        {
            for (int i = index; i < len; ++i)
            {
                swap(arr[index], arr[i]);
                permutation(arr, len, index + 1);
                swap(arr[index], arr[i]);
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    // cout << solution.getPermutation_1(3, 2) << endl;
    vector<int> nums = {1, 2, 3};
    vector<string> ans = solution.permutation(nums, 3);
    cout << ans.size() << endl;
    for (auto v : ans)
    {
        cout << v << endl;
    }
    cout << endl;
    system("pause");
    return 0;
}
