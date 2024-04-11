#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void inputArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("Nhap gia tri ptu thu %d = ", i);
            scanf("%d", a + i);
        } while (*(a + i) < 0);
    }
}

void outputArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
    printf("\n");
}

int recursiveCountEven(int *a, int n)
{
    if (n == 0)
        return 0;
    if (*(a + (n - 1)) % 2 == 0)
        return 1 + recursiveCountEven(a, n - 1);
    return recursiveCountEven(a, n - 1);
}

int recursiveLast(int *a, int n, int x)
{
    if (n == 0)
        return -1;
    if (*(a + (n - 1)) == x)
        return (n - 1);
    else
        return recursiveLast(a, n - 1, x);
}

int main()
{
    int n;
    do
    {
        printf("Nhap n (nho hon 100): ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    int *a = (int *)malloc(n * sizeof(int));

    // Nhap mang
    inputArr(a, n);

    // Xuat mang
    printf("Cac gia tri trong mang: ");
    outputArr(a, n);

    // De quy dem so luong so chan
    printf("So luong so chan trong mang la: %d.\n", recursiveCountEven(a, n));

    // Tim vi tri cuoi cung cua x trong mang
    int x;
    printf("Nhap gia tri can tim x = ");
    scanf("%d", &x);

    int result = recursiveLast(a, n, x);
    if (result == -1)
        printf("Khong co gia tri %d trong mang", x);
    else
        printf("Vi tri cua %d cuoi cung trong mang la: %d", x, result);
    return 0;
}