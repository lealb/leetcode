#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        vector<int> res;
        int carry = 0;
        int p1 = num1.length() - 1;
        int p2 = num2.length() - 1;
        while (p1 >= 0 || p2 >= 0)
        {
            int x1 = p1 >= 0 ? num1[p1] - '0' : 0;
            int x2 = p2 >= 0 ? num2[p2] - '0' : 0;
            int value = (x1 + x2 + carry) % 10;
            carry = (x1 + x2 + carry) / 10;
            res.push_back(value);
            p1--;
            p2--;
        }

        if (carry != 0)
        {
            res.push_back(carry);
        }
        string result = "";
        for (int i = res.size() - 1; i >= 0; --i)
        {
            result += to_string(res[i]);
        }
        return result;
    }
    string addStrings_1(string num1, string num2)
    {
        int sum = 0;
        string res;
        int l1 = num1.size() - 1; //-1
        int l2 = num2.size() - 1;
        int carry = 0;
        while (l1 > -1 || l2 > -1)
        {
            int d1 = l1 > -1 ? num1[l1--] - '0' : 0; //'0'
            int d2 = l2 > -1 ? num2[l2--] - '0' : 0;
            sum = d1 + d2 + carry;
            res += to_string(sum % 10);
            carry = sum / 10;
        }
        if (carry)
            res += "1";
        reverse(res.begin(), res.end());
        return res;
    }
    string addStrings_2(string num1, string num2)
    {

        stringstream ss;
        int s1 = num1.length() - 1;
        int s2 = num2.length() - 1;

        int carry = 0;
        for (; s1 >= 0 && s2 >= 0; --s1, --s2)
        {
            int res = (ctoi(num1[s1]) + ctoi(num2[s2])) + carry;
            carry = 0;

            if (res >= 10)
            {
                ss << itoc(res % 10);
                carry = 1;
            }
            else
            {
                ss << itoc(res);
            }
        }

        while (s1 >= 0)
        {
            int res = ctoi(num1[s1--]) + carry;
            carry = 0;

            if (res >= 10)
            {
                ss << itoc(res % 10);
                carry = 1;
            }
            else
            {
                ss << itoc(res);
            }
        }

        while (s2 >= 0)
        {
            int res = ctoi(num2[s2--]) + carry;
            carry = 0;

            if (res >= 10)
            {
                ss << itoc(res % 10);
                carry = 1;
            }
            else
            {
                ss << itoc(res);
            }
        }

        if (carry)
        {
            ss << itoc(carry);
        }

        string res = ss.str();
        reverse(res.begin(), res.end());
        return res;
    }

    int ctoi(char c)
    {
        return c - '0';
    }

    char itoc(int i)
    {
        return '0' + i;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.addStrings("123", "3456") << endl;
    system("pause");
    return 0;
}
