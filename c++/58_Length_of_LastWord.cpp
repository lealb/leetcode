#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int ans = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == ' ' && ans > 0)
                return ans;
            if (s[i] != ' ')
                ans++;
        }
        return ans;
    }
    int lengthOfLastWord_1(string s)
    {
        int currPos{static_cast<int>(s.length()) - 1};
        while (currPos >= 0 && s[currPos] == ' ')
        {
            currPos--;
        }
        int ret{};
        while (currPos >= 0 && s[currPos] != ' ')
        {
            currPos--;
            ret++;
        }
        return ret;
    }

    int lengthOfLastWord_2(string s)
    {
        stringstream mysr(s);
        string ns;
        string finals;
        while (mysr >> ns)
        {
            finals = ns;
        }

        return finals.length();
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> Xtest = {"        ", "a", " ", "Hello World", "b   a    "};
    vector<int> ytest = {0, 1, 0, 5, 1};
    for (int i = 0; i < Xtest.size(); i++)
    {
        cout << solution.lengthOfLastWord_2(Xtest[i]) << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
