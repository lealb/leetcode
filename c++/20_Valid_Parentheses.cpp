#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (char c : s)
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else
            {
                if (stk.size() > 0 && abs(c - stk.top()) <= 2)
                    stk.pop();
                else
                    return false;
            }
        return stk.empty();
    }
    // other
    bool isValid_1(string str)
    {
        stack<char> stk;
        for (char ch : str)
        {
            if (ch == ')' || ch == '}' || ch == ']')
            {
                if (stk.empty() || (ch == ')' && stk.top() != '(') || (ch == '}' && stk.top() != '{') || (ch == ']' && stk.top() != '['))
                    return false;
                stk.pop();
            }
            else if (ch == '(' || ch == '{' || ch == '[')
                stk.push(ch);
        }
        return stk.empty();
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> testStr = {"()", "()[]{}", "([)]", "{[]}"};
    for (int i = 0; i < testStr.size(); i++)
    {
        cout << solution.isValid(testStr[i]) << " ";
    }
    cout << endl;
    return 0;
}
