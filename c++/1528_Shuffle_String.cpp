#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        vector<pair<int, char>> a;
        for (int i = 0; i < s.length(); ++i)
        {
            a.push_back({indices[i], s[i]});
        }
        sort(a.begin(), a.end());
        string b = "";
        for (int i = 0; i < a.size(); ++i)
        {
            b += a[i].second;
        }
        return b;
    }
    string restoreString_1(string s, vector<int> &indices)
    {
        string res = s;
        for (int i = 0; i < s.size(); i++)
        {
            res[indices[i]] = s[i];
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "codeleet";
    vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
    cout << solution.restoreString_1(s, indices) << endl;
    system("pause");
    return 0;
}
