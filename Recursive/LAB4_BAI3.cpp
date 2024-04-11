#include <stdio.h>
void nhap(int a[], int n)
{
    if (n == 0)
        return;
    nhap(a, n - 1);
    printf("\nNhap phan tu thu %d: ", n - 1);
    scanf("%d", &a[n - 1]);
}
void lietKeSoChan(int a[], int n, int dem)
{
    if (dem >= n)
        return;
    if (a[dem] % 2 == 0)
        printf("%d ", a[dem]);
    lietKeSoChan(a, n, dem + 1);
}

int main()
{
    int a[100];
    int n;
    printf("Nhap so luong pty mang la n: ");
    scanf("%d", &n);
    nhap(a, n);
    printf("Cac so chan trong mang la: ");
    lietKeSoChan(a, n, 0);
    return 0;
}
