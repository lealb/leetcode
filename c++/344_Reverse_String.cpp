#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int size = s.size();
        int left = 0, right = size - 1;
        while (left <= right)
        {
            swap(s[left++], s[right--]);
        }
    }
    void reverseString_1(vector<char> &s)
    {
        int size = s.size();
        for (int i = 0; i < size / 2; i++)
        {
            char temp = s[size - 1 - i];
            s[size - 1 - i] = s[i];
            s[i] = temp;
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(s);
    for (auto s0 : s)
    {
        cout << s0 << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
