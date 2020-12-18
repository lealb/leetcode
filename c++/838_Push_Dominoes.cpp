#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief 分类讨论 L R的影响，Two Pointer运用极致
 * 
 */
class Solution
{
public:
    string pushDominoes(string s)
    {
        int start = 0;
        int l = 0;
        string ans = s;
        for (int i = 0; i < s.size(); i++)
        {
            if (l == 0 && s[i] == '.')
            {
                start = i;
                l++;
            }
            else if (l > 0 && s[i] == '.')
            {
                l++;
            }
            else if (s[i] != '.' && l > 0)
            {
                if (start == 0)
                {
                    if (s[start + l] == 'L')
                        for (int i = start; i < start + l; i++)
                            s[i] = 'L';
                }
                else
                {
                    if (s[start - 1] == s[start + l])
                    {
                        for (int i = start; i < start + l; i++)
                            s[i] = s[start - 1];
                    }
                    else
                    {
                        if (l & 1 && s[start - 1] == 'R' && s[start + l] == 'L')
                        {
                            for (int i = start; i < start + l / 2; i++)
                                s[i] = 'R';
                            for (int i = start + l; i > start + l / 2; i--)
                                s[i] = 'L';
                        }
                        else if ((l & 1) ^ 1 && s[start - 1] == 'R' && s[start + l] == 'L')
                        {
                            for (int i = start; i <= start + l / 2; i++)
                                s[i] = 'R';
                            for (int i = start + l; i >= start + l / 2; i--)
                                s[i] = 'L';
                        }
                    }
                }
                l = 0;
                start = -1;
            }
        }
        // last part
        if (l > 0)
        {
            if (start != 0 && s[start - 1] == 'R')
            {
                for (int i = start; i < start + l; i++)
                {
                    s[i] = 'R';
                }
            }
        }
        return s;
    }

    string pushDominoes_1(string dom)
    {
        int n = dom.size();
        for (int j = 0, i = 0; i < n; i++)
        {
            if (dom[i] != '.' || i == n - 1)
            {
                process(dom, j, i);
                j = i;
            }
        }

        return dom;
    }
    void process(string &d, int i, int j)
    {
        if (d[i] == 'R' && d[j] == 'L')
        {
            while (i < j)
            {
                d[i++] = 'R';
                d[j--] = 'L';
            }
        }
        else if (d[i] == 'R')
        {
            while (i <= j)
                d[i++] = 'R';
        }
        else if (d[j] == 'L')
        {
            while (j >= i)
                d[j--] = 'L';
        }
    }
    string pushDominoes_2(string dominoes)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int start = 0, end = 0, len = dominoes.length();
        while (end < len)
        {
            //. 初始状态
            if (dominoes[end] == '.')
            {
                end++;
            }
            else
            {
                if (dominoes[end] == 'L')
                {
                    // Left
                    if (dominoes[start] == '.' || dominoes[start] == 'L')
                    {
                        for (int i = start; i < end; ++i)
                        {
                            dominoes[i] = 'L';
                        }
                    }
                    else
                    {
                        int i = start + 1, j = end - 1;
                        while (i < j)
                        {
                            dominoes[i++] = 'R';
                            dominoes[j--] = 'L';
                            // i++, j--;
                        }
                    }
                }
                // R
                else
                {
                    if (dominoes[start] == 'R')
                    {
                        for (int i = start; i < end; ++i)
                        {
                            dominoes[i] = 'R';
                        }
                    }
                }
                start = end;
                end++;
            }
        }
        // move start to len
        if (dominoes[start] == 'R')
        {
            for (int i = start; i < len; ++i)
            {
                dominoes[i] = 'R';
            }
        }
        return dominoes;
    }
};
int main(int argc, char const *argv[])
{
    Solution solution;
    string s = ".L.R...LR..L..";
    cout << solution.pushDominoes_2(s) << endl;
    system("pause");
    return 0;
}
