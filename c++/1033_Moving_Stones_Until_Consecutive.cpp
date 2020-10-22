#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        if (b < a)
            swap(a, b);
        if (c < b)
            swap(b, c);
        if (b < a)
            swap(a, b);
        if (b - a == 1 && 1 == c - b)
        {
            return {0, 0};
        }
        return {(b - a <= 2 || 2 >= c - b) ? 1 : 2, c - a - 2};
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> res = solution.numMovesStones(3, 5, 1);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
