#include <stdio.h>
#include <math.h>
int InvertNum(int n, int digits)
{
    if (n == 0)
        return 0;
    int x = n % 10;
    n /= 10;
    return x * pow(10, digits - 1) + InvertNum(n, digits - 1);
}
int main()
{
    int n, digits;
    do
    {
        printf("Nhap n: ");
        scanf("%d", &n);
    } while (n <= 0 || n > 10000);

    do
    {
        printf("Nhap digits: ");
        scanf("%d", &digits);
    } while (digits <= 0 || digits >= 5);

    int s = InvertNum(n, digits);
    printf("So truoc dao %d\n", n);
    printf("So sau dao %d\n", s);

    return 0;
}