#include <stdio.h>
void nhap(int a[], int n)
{
    if (n == 0)
        return;
    nhap(a, n - 1);
    printf("\nNhap phan tu thu %d: ", n - 1);
    scanf("%d", &a[n - 1]);
}
int tongAm(int a[], int n)
{
    if (n == 0)
        return 0;
    else
        return (a[n - 1] < 0 ? a[n - 1] : 0) + tongAm(a, n - 1);
}

int demAm(int a[], int n)
{
    if (n == 0)
        return 0;
    else
        return (a[n - 1] < 0 ? 1 : 0) + demAm(a, n - 1);
}

double trungBinhAm(int a[], int n)
{
    int tong = tongAm(a, n);
    int soLuong = demAm(a, n);
    if (soLuong == 0)
        return 0;
    else
        return (double)tong / soLuong;
}

int main()
{
    int a[100];
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    nhap(a, n);

    printf("Trung binh cong cua cac phan tu am trong mang: %.2f\n", trungBinhAm(a, n));

    return 0;
}
