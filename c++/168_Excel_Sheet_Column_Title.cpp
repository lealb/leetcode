#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    string convertToTitle(int n)
    {
        string res = "";
        while (n)
        {
            res = char(--n % 26 + 'A') + res;
            n /= 26;
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.convertToTitle(701) << endl;
    system("pause");
    return 0;
}
