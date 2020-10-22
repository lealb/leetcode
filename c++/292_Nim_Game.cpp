#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool canWinNim(int n)
    {
        return n % 4;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.canWinNim(10);
    cout << endl;
    system("pause");
    return 0;
}
