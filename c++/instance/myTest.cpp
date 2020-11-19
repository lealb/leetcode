#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
void init()
{
    int i{0};
    cout << i << endl;
}
/**
 * 将  char *|char []   转换为  string
 * 直接赋值
 */
void charToString(char *c)
{
    string str;
    str = c;
    cout << str << endl;
    cout << str.length() << endl;
}
void stringToChar(string str)
{
    //1. string data
    const char *c = str.data();
    cout << c << endl;

    //2. string c_str
    const char *c2 = str.c_str();
    cout << c2 << endl;
    //
    char c3[10];
    strcpy(c3, str.c_str());
    cout << c3 << endl;

    //3.copy
    char c4[10];
    str.copy(c4, str.length(), 0);
    *(c4 + str.length()) = '\0';
    cout << c4 << endl;
}
void intToChar(int nums)
{
    string s = to_string(nums);
    char const *pchar = s.c_str();
    cout << pchar << endl;
}
int main(int argc, char const *argv[])
{
    char c[] = "Sre";
    charToString(c);
    string str = "hello";
    stringToChar(str);
    return 0;
}
