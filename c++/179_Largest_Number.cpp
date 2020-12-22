#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * @brief 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 */
class Solution
{
public:
    vector<char> splitNums(int num)
    {
        vector<char> ans;
        while (num)
        {
            ans.push_back(num % 10);
            // cout << num % 10 << " ";
            num /= 10;
        }
        return ans;
    }
    string largestNumber(vector<int> &nums)
    {
        int size = nums.size();
        if (1 == size)
        {
            return to_string(nums[0]);
        }
        vector<string> ans;
        for (int i = 0; i < size; ++i)
        {
            // if (10 > nums[i])
            // {
            //     ans.emplace_back(nums[i]);
            // }
            // else
            // {
            //     // nums.erase(find(nums.begin(), nums.end(), nums[i]));
            //     // nums.erase(nums.begin() + i);
            //     while (nums[i])
            //     {
            //         // nums.emplace_back(nums[i] % 10);
            //         ans.emplace_back(nums[i] % 10);
            //         nums[i] /= 10;
            //     }
            // }
            ans.emplace_back(to_string(nums[i]));
        }

        string res = "";
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        for (auto &v : ans)
        {
            // cout << v << " ";
            res += v;
        }
        return res;
    }
    string largestNumber_1(vector<int> &nums)
    {
        vector<string> numbers;
        for (auto &num : nums)
        {
            numbers.push_back(to_string(num));
        }
        sort(numbers.begin(), numbers.end(), [](string &s1, string &s2) { return s1 + s2 > s2 + s1; });
        string s;
        for (string &number : numbers)
        {
            s += number;
        }
        return (s[0] == '0') ? "0" : s;
    }
    string largestNumber_2(vector<int> &nums)
    {
        vector<string> numStr;
        for (auto n : nums)
        {
            numStr.push_back(to_string(n));
        }
        sort(numStr.begin(), numStr.end(), [](string &s1, string &s2) { return s1 + s2 > s2 + s1; });
        string result;
        for (auto s : numStr)
        {
            result.append(s);
        }
        // remove leading zero
        while (result.size() > 1 && result[0] == '0')
        {
            result.erase(result.begin());
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << solution.largestNumber_2(nums) << endl;
    // vector<char> ans = solution.splitNums(123);
    // for (auto &v : ans)
    // {
    //     cout << v << " ";
    // }
    system("pause");
    return 0;
}
