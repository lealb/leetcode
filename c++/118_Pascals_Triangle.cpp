#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<int> curr(1, 1);
        vector<int> next(2, 1);
        if (numRows == 0)
            return vector<vector<int>>();
        if (numRows == 1)
            return vector<vector<int>>({curr});
        if (numRows == 2)
            return vector<vector<int>>({{curr}, {next}});

        vector<vector<int>> res;
        res.push_back(curr);
        res.push_back(next);
        numRows -= 2;
        while (numRows)
        {
            numRows--;
            curr = next;
            next.resize(0);
            next.push_back(1);
            int sz = curr.size() - 1;
            for (int i = 0; i < sz; i++)
            {
                next.push_back(curr[i] + curr[i + 1]);
            }
            next.push_back(1);
            res.push_back(next);
        }
        return res;
    }
    vector<vector<int>> generate_1(int numRows)
    {
        vector<vector<int>> triangle;
        if (!numRows)
            return triangle;

        triangle.push_back({1});
        for (int i = 1; i < numRows; i++)
        {
            vector<int> vi(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                vi[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(vi);
        }
        return triangle;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> res = solution.generate_1(10);
    for (int i = 0; i < res.size(); i++)
    {
        for (auto v : res[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
