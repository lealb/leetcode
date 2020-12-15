#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isVowel(char key)
    {
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        return find(v.begin(), v.end(), tolower(key)) != v.end();
    }
    string reverseVowels(string s)
    {
        int len = s.length();
        int left = 0, right = len - 1;
        while (left <= right)
        {
            if (isVowel(s[left]) && isVowel(s[right]))
            {
                swap(s[left++], s[right--]);
            }
            if (!isVowel(s[left]))
                left++;
            if (!isVowel(s[right]))
                right--;
        }
        return s;
    }
    string reverseVowels_1(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        while (i < j)
        {
            while (i < j && !isVowel(s[i]))
            {
                ++i;
            }
            while (i < j && !isVowel(s[j]))
            {
                --j;
            }
            //swap(s[i++], s[j--]);
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            ++i;
            --j;
        }
        return s;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "hello";
    cout << solution.reverseVowels_1(s) << endl;
    system("pause");
    return 0;
}
