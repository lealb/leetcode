#include <iostream>
#include <math.h>
using namespace std;

void p_3()
{
    unsigned u = 10, u2 = 42;
    cout << u2 - u << endl;
    // 自动加模运算
    cout << u - u2 << endl;
    int i = 10, i2 = 42;
    cout << i2 - i << endl;
    cout << i - i2 << endl;
    cout << i - u << endl;
    cout << u - i << endl;
    // 4,294,967,296
    cout << pow(2, 32) << endl;
}
void p_8()
{
    cout << "2\x4d\012";
    cout << "2M\n";
    cout << "2\tM\n";
}
void p_10()
{
    // default value
    int a;
    string s;
    cout << a << endl; // 0
    cout << s << endl; // ""
}
void p_16()
{
    int i = 1, &r1 = i;
    int d = 10.1, &r2 = d;
    cout << "i= " << i << " &i= " << r1 << endl;
    cout << "d= " << d << " &d= " << r2 << endl;
    // 引用赋值实际上是把值赋给了引用绑定的对象
    r2 = 3.114159;
    cout << "i= " << i << " &i= " << r1 << endl;
    cout << "d= " << d << " &d= " << r2 << endl;
    r2 = r1;
    cout << "i= " << i << " &i= " << r1 << endl;
    cout << "d= " << d << " &d= " << r2 << endl;
    i = r2;
    cout << "i= " << i << " &i= " << r1 << endl;
    cout << "d= " << d << " &d= " << r2 << endl;
    r1 = d;
    cout << "i= " << i << " &i= " << r1 << endl;
    cout << "d= " << d << " &d= " << r2 << endl;
}
void test()
{
    short a = 1;
    int b = 1;
    long l = 1;
    long long ll = 1;
    float c = 1;
    double d = 1;
    char e = 'a';
    bool f = 1;

    //cout<<typedef(a)<<endl;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(l) << endl;
    cout << sizeof(ll) << endl;
    cout << sizeof(c) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(e) << endl;
    cout << sizeof(f) << endl;
}
int main()
{
    // p_16();
    return 0;
}