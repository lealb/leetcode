#include <iostream>
#include <bitset>

using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "";
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry == 1)
        {
            carry += i >= 0 ? a[i] - '0' : 0;
            carry += j >= 0 ? b[j] - '0' : 0;
            result = char(carry % 2 + '0') + result;
            carry /= 2;
            i--;
            j--;
        }
        return result;
    }

    string addBinary_1(string a, string b)
    {
        bitset<128> A(a);
        bitset<128> B(b);
        while (B != 0)
        {
            bitset<128> carry = (A & B) << 1;
            A = A ^ B;
            B = carry;
        }
        string result(A.to_string());
        result.erase(0, result.find_first_not_of('0'));
        if (result.size() == 0)
        {
            return "0";
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.addBinary_1("11", "1") << endl;
    system("pause");
    return 0;
}
