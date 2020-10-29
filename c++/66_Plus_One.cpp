#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 */
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int res = 0, i = 0, size = digits.size();
        while (i < size)
        {
            res = res * 10 + (digits[i++] - '0');
        }
        cout << res << endl;
        return {};
    }
    vector<int> plusOne_1(vector<int> &digits)
    {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        int n = digits.size();
        for (int i = 0; i < n; i++)
        {
            int a = digits[i];
            digits[i] = (digits[i] + carry) % 10;
            carry = (a + carry) / 10;
        }
        if (carry == 1)
        {
            digits.push_back(1);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }

    vector<int> plusOne_2(vector<int> &digits)
    {
        int carry = 1;
        int size = digits.size();
        for (int i = size - 1; i >= 0; i--)
        {
            int a = digits[i];
            digits[i] = (digits[i] + carry) % 10;
            carry = (a + carry) / 10;
        }
        if (carry == 1)
        {
            digits.emplace(digits.begin(), 1);
        }
        return digits;
    }
    vector<int> plusOne_3(vector<int> &digits)
    {
        bool carry_one = true;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (carry_one)
            {
                if (digits[i] < 9)
                {
                    digits[i]++;
                    return digits;
                }
                else
                {
                    // d is 9, we convert this to 0 and carry forward one
                    digits[i] = 0;
                    carry_one = true;
                }
            }
            else
            {
                return digits;
            }
        }
        if (carry_one)
        {
            digits.emplace(digits.begin(), 1);
        }
        return digits;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> digits = {1, 9, 9, 9};
    vector<int> res = solution.plusOne_2(digits);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
