#include <iostream>
#include <map>
#include <unordered_map>
#include <sstream>
using namespace std;
void mapTest()
{
    //1.map init
    //1) insert
    map<string, int> romanSimple;
    romanSimple.insert({"I", 1});
    romanSimple.insert({"V", 5});
    romanSimple.insert({"X", 10});
    romanSimple.insert({"L", 50});
    romanSimple.insert({"C", 100});
    romanSimple.insert({"D", 500});
    romanSimple.insert({"M", 1000});
    /*
    *I can be placed before V (5) and X (10) to make 4 and 9. 
     X can be placed before L (50) and C (100) to make 40 and 90. 
     C can be placed before D (500) and M (1000) to make 400 and 900.
    */
    map<string, int> romanFh;
    romanFh.insert({"IV", 4});
    romanFh.insert({"IX", 9});
    romanFh.insert({"XL", 40});
    romanFh.insert({"XC", 90});
    romanFh.insert({"CD", 400});
    romanFh.insert({"CM", 900});

    cout << romanFh.at("IV") << endl;
}
// Runtime: 40 ms,Memory Usage: 10 MB, l
int romanToInt(string s)
{
    map<char, int> romanSimple;
    romanSimple.insert({'I', 1});
    romanSimple.insert({'V', 5});
    romanSimple.insert({'X', 10});
    romanSimple.insert({'L', 50});
    romanSimple.insert({'C', 100});
    romanSimple.insert({'D', 500});
    romanSimple.insert({'M', 1000});
    map<string, int> romanFh;
    romanFh.insert({"IV", 4});
    romanFh.insert({"IX", 9});
    romanFh.insert({"XL", 40});
    romanFh.insert({"XC", 90});
    romanFh.insert({"CD", 400});
    romanFh.insert({"CM", 900});
    if (s.empty())
    {
        return 0;
    }
    int nums = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // string tmpStr1(1, s[i]);
        // string tmpStr2(1, s[i+1]);
        // map<string, int>::iterator it = romanFh.find(tmpStr1 + tmpStr2);
        // if (it != romanFh.end())
        // {
        //     cout << it->second << endl;
        // }

        if ('I' == s[i] && 'V' == s[i + 1])
        {
            nums += 4;
            i++;
        }
        else if ('I' == s[i] && 'X' == s[i + 1])
        {
            nums += 9;
            i++;
        }
        else if ('X' == s[i] && 'L' == s[i + 1])
        {
            nums += 40;
            i++;
        }
        else if ('X' == s[i] && 'C' == s[i + 1])
        {
            nums += 90;
            i++;
        }
        else if ('C' == s[i] && 'D' == s[i + 1])
        {
            nums += 400;
            i++;
        }
        else if ('C' == s[i] && 'M' == s[i + 1])
        {
            nums += 900;
            i++;
        }
        else
        {
            // stringstream strR;
            // strR << s[i];
            // strR.str();
            nums += romanSimple.at(s[i]);
        }
    }
    return nums;
}
int romanToInt_0(string s)
{
    unordered_map<char, int> m{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int result{0};
    for (int i = 0; i < s.size(); i++)
        result = (m[s[i]] < m[s[i + 1]]) ? result - m[s[i]] : result + m[s[i]];

    return result;
}
int romanToInt_1(string s)
{
    unordered_map<char, pair<int, int>> m1;
    m1['I'] = make_pair(1, 1);
    m1['V'] = make_pair(5, 2);
    m1['X'] = make_pair(10, 3);
    m1['L'] = make_pair(50, 4);
    m1['C'] = make_pair(100, 5);
    m1['D'] = make_pair(500, 6);
    m1['M'] = make_pair(1000, 7);
    int answer = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (i + 1 < s.size() && m1[s[i]].second < m1[s[i + 1]].second)
        {
            answer -= m1[s[i]].first;
            continue;
        }
        answer += m1[s[i]].first;
    }
    return answer;
}
int romanToInt_2(string s)
{
    int output = 0;
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case 'V':
            output += 5;
            break;
        case 'X': //all X casese
            if (s[i + 1] == 'L')
            {
                output += 40;
                i++;
            }
            else if (s[i + 1] == 'C')
            {
                output += 90;
                i++;
            }
            else
            {
                output += 10;
            }
            break;
        case 'L':
            output += 50;
            break;
        case 'C': //all C cases
            if (s[i + 1] == 'D')
            {
                output += 400;
                i++;
            }
            else if (s[i + 1] == 'M')
            {
                output += 900;
                i++;
            }
            else
            {
                output += 100;
            }
            break;
        case 'D':
            output += 500;
            break;
        case 'M':
            output += 1000;
            break;
        case 'I':
            if (s[i + 1] == 'V')
            {
                output += 4;
                i++;
            }
            else if (s[i + 1] == 'X')
            {
                output += 9;
                i++;
            }
            // else if (s[i + 1] == 'I')
            // {
            //     if (s[i + 2] == 'I')
            //     {
            //         output += 3;
            //         i += 2;
            //     }
            //     else
            //     {
            //         output += 2;
            //         i++;
            //     }
            // }
            else
            {
                output += 1;
            }
            break;
        }
    }
    return output;
}
int romanToInt_3(string s)
{
    if (s.empty())
        return 0;

    int res;
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == 'I')
            res += 1;
        else if (s[i] == 'V')
        {
            if (res % 5 == 1)
                res += 3;
            else
                res += 5;
        }
        else if (s[i] == 'X')
        {
            if (res % 10 == 1)
                res += 8;
            else
                res += 10;
        }
        else if (s[i] == 'L')
        {
            if (res % 50 == 10)
                res += 30;
            else
                res += 50;
        }
        else if (s[i] == 'C')
        {
            if (res % 100 == 10)
                res += 80;
            else
                res += 100;
        }
        else if (s[i] == 'D')
        {
            if (res % 500 == 100)
                res += 300;
            else
                res += 500;
        }
        else if (s[i] == 'M')
        {
            if (res % 1000 == 100)
                res += 800;
            else
                res += 1000;
        }
        i++;
    }
    return res;
}
int romanToInt_4(string s)
{
    unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};
    int r = m[s.substr(0, 1)];
    for (int i = 1; i < s.size(); ++i)
    {
        string two = s.substr(i - 1, 2);
        string one = s.substr(i, 1);
        r += m[two] ? m[two] : m[one];
    }
    return r;
}
int main(int argc, char const *argv[])
{
    // mapTest();
    cout << romanToInt_2("III") << endl;
    return 0;
}
