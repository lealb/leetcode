#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        long long f = rowIndex + 1;
        vector<int> v(f);
        v[0] = 1;
        v[rowIndex] = 1;
        for (int j = 1; j <= rowIndex / 2; j++)
        {
            v[rowIndex - j] = v[j] = (v[j - 1] * (f - j)) / j;
        }
        return v;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> res = solution.getRow(10);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
