#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /**
     * Greedy
     * Time:O(n)
     * Space:O(1)
     */
    vector<int> partitionLabels(string S)
    {
        vector<int> lettersCount(26, 0);
        for (int i = 0; i < S.length(); ++i)
        {
            lettersCount[S[i] - 'a'] = i;
        }
        int j = 0, anchor = 0;
        vector<int> ans;
        for (int i = 0; i < S.length(); ++i)
        {
            j = max(j, lettersCount[S[i] - 'a']);
            if (i == j)
            {
                ans.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return ans;
    }
    vector<int> partitionLabels_1(string S)
    {
        vector<int> endIndex(26, 0);
        for (int i = 0; i < S.length(); i++)
        {
            endIndex[S[i] - 'a'] = i;
        }
        vector<int> result;
        int start = 0;
        int end = -1;
        for (int i = 0; i < S.length(); i++)
        {
            end = max(end, endIndex[S[i] - 'a']);
            if (end == i)
            {
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "ababcbacadefegdehijhklij";
    vector<int> res = solution.partitionLabels(s);
    for (auto &v : res)
    {
        cout << v << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
