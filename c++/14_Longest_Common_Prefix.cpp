#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    /**
     * Approach 1: Horizontal scanning
     * Time complexity : O(S), where S is the sum of all characters in all strings.
     * In the worst case all nn strings are the same. The algorithm compares the string S1
     *  with the other strings [S2...Sn] 
     * There are S character comparisons, where S is the sum of all characters in the input array.
     * Space complexity : O(1). We only used constant extra space.
     */
    string longestCommonPrefix_0(vector<string> &strs)
    {
        int strsSize = strs.size();
        if (0 == strsSize)
        {
            return "";
        }
        string prefix(strs[0]);
        for (int i = 0; i < strsSize; i++)
        {
            // 没有考虑到["c","acc","ccc"]
            while (0 != strs[i].find(prefix))
            {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty())
                {
                    return "";
                }
            }
        }
        return prefix;
    }

    /**
         * Approach 2: Vertical scanning
         * Time complexity : O(S), where S is the sum of all characters in all strings.
         * In the worst case there will be nn equal strings with length mm and 
         * the algorithm performs S=m⋅n character comparisons. 
         * Even though the worst case is still the same as Approach 1, 
         * in the best case there are at most n*minLenn comparisons where minLenis 
         * the length of the shortest string in the array.
         * Space complexity : O(1). We only used constant extra space.
         */
    string longestCommonPrefix_1(vector<string> &strs)
    {
        if (0 == strs.size())
        {
            return "";
        }
        for (int i = 0; i < strs[0].length(); i++)
        {
            // 取第一个字符
            for (int j = 1; j < strs.size(); j++)
            {
                if (i == strs[j].length() || strs[j][i] != strs[0][i])
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution = Solution();
    vector<string> strs = {"flower", "flow", "flight"};
    cout << solution.longestCommonPrefix_1(strs) << endl;
    return 0;
}
