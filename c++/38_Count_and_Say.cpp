#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    void helper(string &old)
    {
        string temp = "";
        vector<char> s;
        s.push_back(old[0]);
        for (int i = 1; i < old.size(); ++i)
        {
            if (old[i] != s[0])
            {
                temp += to_string(s.size()) + s[0];
                s.clear();
            }
            s.push_back(old[i]);
        }
        if (!s.empty())
            temp += to_string(s.size()) + s[0];
        old = temp;
    }

    string countAndSay(int n)
    {
        if (n < 1)
        {
            return "";
        }

        vector<string> arr{"1", "11", "21", "1211", "111221"};
        if (n >= 1 && n <= 5)
            return arr[n - 1];
        string start = arr[4];
        n -= 5;
        while (n)
        {
            helper(start);
            n--;
        }
        return start;
    }
    void nextString(string &s)
    {
        string ans = "";
        char prev = ' ';
        int c = 0;
        for (auto i : s)
        {
            if (i != prev)
            {
                if (c)
                {
                    ans += to_string(c) + prev;
                }
                prev = i;
                c = 1;
            }
            else
            {
                c++;
            }
        }
        ans += to_string(c) + prev;
        s = ans;
    }

    string countAndSay_1(int n)
    {
        if (n <= 0)
        {
            return "";
        }

        string s = "1";
        for (int i = 2; i <= n; i++)
        {
            nextString(s);
        }
        return s;
    }
    string fincntsay(string s, int n)
    {
        if (n == 0)
            return s;
        if (s == "")
            s += '1';
        else
        {
            string str = "";
            int cnt = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (i == 0)
                    cnt = 1;
                else if (s[i] == s[i - 1])
                    cnt++;
                else
                {
                    str += to_string(cnt);
                    str += s[i - 1];
                    cnt = 1;
                }
            }
            str += to_string(cnt);
            str += s[s.size() - 1];
            s = str;
        }
        return fincntsay(s, n - 1);
    }
    string countAndSay_2(int n)
    {
        string s = "";
        return fincntsay(s, n);
    }
    /**
     * Time: 0 ms
     * Space: 6.9 MB
     */
    string countAndSay_3(int n)
    {
        if (n == 1)
            return "1";
        if (n == 2)
            return "11";
        string s = "11";
        for (int i = 3; i <= n; i++)
        {
            s += '$';
            int cnt = 1;
            int len = s.length();
            string tmp = "";
            for (int j = 1; j < len; j++)
            {
                if (s[j] != s[j - 1])
                {
                    tmp += cnt + '0';
                    tmp += s[j - 1];
                    cnt = 1;
                }
                else
                {
                    cnt++;
                }
            }
            s = tmp;
        }
        return s;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.countAndSay_1(5) << endl;
    system("pause");
    return 0;
}
