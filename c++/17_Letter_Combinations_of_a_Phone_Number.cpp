#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:

    /**
     * Approach 1: Backtracking
     */
    vector<string> letterCombinations_1(string digits)
    {
        if (digits.size() == 0)
        {
            return {};
        }
        unordered_map<char, string> phoneMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        vector<string> output;
        backtrack("", output, 0, digits, phoneMap);
        return output;
    }

    void backtrack(string cur, vector<string> &output, int index, string digits, unordered_map<char, string> &phoneMap)
    {
        if (cur.size() == digits.size())
        {
            output.push_back(cur);
            return;
        }
        for (auto c : phoneMap[digits[index]])
        {
            backtrack(cur + c, output, index + 1, digits, phoneMap);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution = Solution();
    string digits = "234";
    vector<string> leeters = solution.letterCombinations_1(digits);
    for (auto leeter : leeters)
    {
        cout << leeter << " ";
    }

    return 0;
}
