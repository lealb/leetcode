#include <iostream>
#include <vector>

using namespace std;
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution
{
public:
    /**
     * rand() % (b-a+1)+ a ;    就表示  a~b 之间的一个随机整数
     */
    int rand7()
    {
        return rand() % 7 + 1;
    }
    /**
     * Approach 1: Rejection Sampling
     * E=2.45
     */
    int rand10_0()
    {
        int idx, row, col;
        do
        {
            row = rand7(), col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
    }
    /**
     * E=2.2123
     */
    int rand10_1()
    {
        int a, b, idx;
        while (true)
        {
            a = rand7();
            b = rand7();
            idx = b + (a - 1) * 7;
            if (idx <= 40)
                return 1 + (idx - 1) % 10;
            a = idx - 40;
            b = rand7();
            // get uniform dist from 1 - 63
            idx = b + (a - 1) * 7;
            if (idx <= 60)
                return 1 + (idx - 1) % 10;
            a = idx - 60;
            b = rand7();
            // get uniform dist from 1 - 21
            idx = b + (a - 1) * 7;
            if (idx <= 20)
                return 1 + (idx - 1) % 10;
        }
    }
    int main(int argc, char const *argv[])
    {
        Solution solution;
        cout << solution.rand10_0() << endl;
        system("pause");
        return 0;
    }
