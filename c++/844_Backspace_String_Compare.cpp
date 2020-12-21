#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        string s1, t1;
        for (char c : S)
        {
            if (s1.size() and c == '#')
                s1.pop_back();
            else
                s1.push_back(c);
            if (s1.back() == '#')
                s1.pop_back();
        }
        for (char c : T)
        {
            if (t1.size() and c == '#')
                t1.pop_back();
            else
                t1.push_back(c);
            if (t1.back() == '#')
                t1.pop_back();
        }
        return s1 == t1;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string S = "ab#c", T = "ad#c";
    cout << solution.backspaceCompare(S, T) << endl;
    system("pause");
    return 0;
}
