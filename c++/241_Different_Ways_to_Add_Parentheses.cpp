#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    map<string, vector<int>> memo;
    vector<int> diffWaysToCompute(string input)
    {
        if (memo.find(input) != memo.end())
            return memo[input];
        vector<int> left, right, res;
        for (int i = 0; i < input.size(); ++i)
        {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*')
            {
                string inl = input.substr(0, i);
                string inr = input.substr(i + 1);
                left = diffWaysToCompute(inl);
                right = diffWaysToCompute(inr);
            }
            for (int a : left)
            {
                for (int b : right)
                {
                    if (input[i] == '+')
                        res.push_back(a + b);
                    else if (input[i] == '-')
                        res.push_back(a - b);
                    else if (input[i] == '*')
                        res.push_back(a * b);
                }
            }
        }
        if (!res.size())
            res.push_back(stoi(input));
        return memo[input] = res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string input = "2*3-4*5";
    vector<int> ans = solution.diffWaysToCompute(input);
    for (auto &v : ans)
    {
        cout << v << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
