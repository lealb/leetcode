#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
/**
 * 1 <= num1.length, num2.length <= 200
 * num1 and num2 consist of digits only.
 * Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 */
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int len1 = num1.length(), len2 = num2.length();
        char res[len1 + len2];
        int resIndex, carry = 0, le = 219;
        memset(res, '0', len1 + len2);
        for (int i = len1 - 1; i >= 0; i--)
        {
            resIndex = len2 + i;
            for (int j = len2 - 1; j >= 0; j--)
            {
                int tmp = carry + (num1[i] - '0') * (num2[j] - '0');
                carry = (res[resIndex] - '0' + tmp) / 10;
                res[resIndex] = (res[resIndex] - '0' + tmp) % 10 + '0';
                resIndex--;
            }
            while (carry > 0)
            {
                int tmp = carry;
                carry = (res[resIndex] - '0' + tmp) / 10;
                res[resIndex] = (res[resIndex] - '0' + tmp) % 10 + '0';
                resIndex--;
            }
            if (le > resIndex)
                le = resIndex;
        }
        return string(&res[resIndex + 1], &res[len1 + len2]);
    }
    string multiply_1(string num1, string num2)
    {
        // handle edge-case where the product is 0
        if (num1 == "0" || num2 == "0")
            return "0";
        // num1.size() + num2.size() == max no. of digits
        int len1 = num1.length(), len2 = num2.length();
        vector<int> num(len1 + len2, 0);
        // build the number by multiplying one digit at the time
        for (int i = len1 - 1; i >= 0; --i)
        {
            for (int j = len2 - 1; j >= 0; --j)
            {
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                num[i + j] += num[i + j + 1] / 10;
                num[i + j + 1] %= 10;
            }
        }
        // skip leading 0's
        int i = 0, len = num.size();
        while (i < len && num[i] == 0)
            ++i;

        // transofrm the vector to a string
        string res = "";
        while (i < len)
            res.push_back(num[i++] + '0');

        return res;
    }
    string multiply_2(string num1, string num2)
    {
        string res;
        int next_add = 0;
        int k1 = num1.size(), k2 = num2.size();
        for (int i = 0; i < k1 + k2 - 1; i++)
        {
            int sum = next_add;
            for (int j = max(0, i - k2 + 1); j <= min(i, k1 - 1); j++)
            {
                sum += (num1[k1 - 1 - j] - '0') * (num2[k2 - 1 - i + j] - '0');
            }
            next_add = sum / 10;
            res += ('0' + sum % 10);
        }
        if (next_add != 0)
        {
            res += ('0' + next_add);
        }
        while (res.back() == '0' && res.size() > 1)
        {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string multiply_3(string num1, string num2)
    {
        string sum(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; 0 <= i; --i)
        {
            int carry = 0;
            for (int j = num2.size() - 1; 0 <= j; --j)
            {
                int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            sum[i] += carry;
        }

        size_t startpos = sum.find_first_not_of("0");
        if (string::npos != startpos)
        {
            return sum.substr(startpos);
        }
        return "0";
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.multiply_1("123", "456") << endl;
    system("pause");
    return 0;
}
