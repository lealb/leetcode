#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maximumSwap_0(int num)
    {
        string str_num = to_string(num);
        string res = helper(str_num);
        return stoi(res);
    }
    string helper(string str_num)
    { // operate in terms of string
        if (str_num.size() < 2)
            return str_num;
        auto max_dig = max_element(str_num.rbegin(), str_num.rend() - 1); // search from left to right
        if (*max_dig > str_num[0])
        { //swap
            swap(*max_dig, str_num[0]);
            return str_num;
        }
        string res = helper(str_num.substr(1));
        return str_num.substr(0, 1) + res;
    }

    int maximumSwap_1(int num)
    {
        vector<int> digits;
        while (num)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
        vector<int> maxIndexVec(digits.size());
        int max = numeric_limits<int>::min();
        int maxIndex = 0;
        // Here we are finding index of max digit so far, please note, we are calculating this location from LSB side.
        //
        for (int i = 0; i < digits.size(); ++i)
        {
            if (digits[i] > max)
            {
                max = digits[i];
                maxIndex = i;
            }
            maxIndexVec[i] = maxIndex;
        }
        for (int i = digits.size() - 1; i > 0; --i)
        {
            if (i != maxIndexVec[i] && digits[i] != digits[maxIndexVec[i]])
            {
                swap(digits[i], digits[maxIndexVec[i]]);
                break;
            }
        }
        int result = 0;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            result = result * 10 + digits[i];
        }
        return result;
    }
    int maximumSwap_2(int num)
    {
        vector<int> digits;
        while (num)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        int res = 0;
        for (int i = 0; i < digits.size(); ++i)
        {
            for (int j = i; j < digits.size(); ++j)
            {
                swap(digits[i], digits[j]);
                int tmp = 0;
                for (int k = 0; k < digits.size(); ++k)
                {
                    tmp = tmp * 10 + digits[k];
                }
                swap(digits[i], digits[j]);
                res = max(res, tmp);
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.maximumSwap_1(23571) << endl;
    system("pause");
    return 0;
}
