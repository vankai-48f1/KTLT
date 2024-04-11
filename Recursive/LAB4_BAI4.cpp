#include <stdio.h>
void nhap(int a[], int n)
{
    if (n==0)
        return;
    nhap(a, n-1);
    printf ("\nNhap phan tu thu %d: ",n-1);
    scanf ("%d", &a[n-1]);
}
int doiXung(int a[], int left, int right) {
    if (left >= right)
        return 1;

    if (a[left] != a[right])
        return 0;

    return doiXung(a, left + 1, right - 1);
}

int main() {
    int a[100];
    int n;
    printf ("Nhap so luong pty mang la n: "); scanf ("%d",&n);
    nhap(a,n);

    if (doiXung(a, 0, n-1))
        printf("Mang da cho doi xung.\n");
    else
        printf("Mang da cho khong doi xung.\n");

    return 0;
}	
