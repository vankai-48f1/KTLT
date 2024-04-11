#include <stdio.h>
int luyThua(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    else
        return base * luyThua(base, exponent - 1);
}

int main()
{
    int a, b, n;
    printf("Nhap gia tri cua a: ");
    scanf("%d", &a);
    printf("Nhap gia tri cua b: ");
    scanf("%d", &b);
    printf("Nhap gia tri cua n: ");
    scanf("%d", &n);
    int result = luyThua(a + b, n);
    printf("(%d + %d)^%d = %d\n", a, b, n, result);
    return 0;
}
