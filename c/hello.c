#include <stdio.h>
void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
/**
 * 数学归纳法与递归
 */
void prove(int n)
{
    int k;
    printf("现在证明P(%d)成立\n", n);
    k = 0;
    printf("根据步骤1得出P(%d)成立\n", k);
    while (k < n)
    {
        printf("根据步骤2可以说“若P(%d)成立,则P(%d)也成立”\n", k, k + 1);
        printf("因此可以说“P(%d)是成立的”\n", k + 1);
        k += 1;
    }
}
int main()
{
    int a = 1, b = 2;
    swap(1, 2);
    printf("%d,%d\n", a, b);
    prove(0);
    printf("*******************\n");
    prove(1);
    printf("*******************\n");
    prove(2);
    return 0;
}
