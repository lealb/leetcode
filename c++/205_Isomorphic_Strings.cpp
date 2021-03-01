#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    /**
     * @brief 
     * 1.第一张哈希表 s2t 以 ss 中字符为键，映射至 tt 的字符为值，
     * 2.第二张哈希表 t2s 以 tt 中字符为键，映射至 ss 的字符为值。
     * 3.从左至右遍历两个字符串的字符，不断更新两张哈希表，
     * 如果出现冲突（即当前下标index 对应的字符 s[index] 已经存在映射且不为 t[index] 或
     * 当前下标 index 对应的字符 t[index] 已经存在映射且不为 s[index]）时说明两个字符串无法构成同构，
     * 返回 false
     * 
     * @param s 
     * @param t 
     * @return true 
     * @return false 
     */
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        int len = s.length();
        for (int i = 0; i < len; ++i)
        {
            char x = s[i], y = t[i];
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x))
            {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
    bool isIsomorphic_2(string s, string t)
    {
        int m1[256] = {0};
        int m2[256] = {0};
        for (size_t i = 0; i < s.size(); i++)
        {
            if (m1[s[i]] != m2[t[i]])
                return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.isIsomorphic("add", "egg") << endl;
    system("pause");
    return 0;
}
