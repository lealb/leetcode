#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    int maxDepth(string s)
    {
        int size = s.length();
        int result = 0, max = 0;
        for (int i = 0; i < size; i++)
        {
            if (s[i] == '(')
            {
                result++;
            }
            else if (s[i] == ')')
            {
                result--;
            }
            if (result > max)
            {
                max = result;
            }
        }
        return max;
    }
    int maxDepth_1(string s)
    {
        int ans = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                int n = st.size();
                ans = max(ans, n);
                st.pop();
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.maxDepth_1("(1)+((2))+(((3)))") << endl;
    system("pause");
    return 0;
}
