#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void inputArr(int *a, int n)
{
    int i = 0;
    do
    {
        printf("Nhap phan tu thu %d = ", i);
        scanf("%d", a + i);

        if (*(a + i) > 0)
            i++;
    } while (i < n);
}
void outputArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", *(a + i));
    }
    printf("\n");
}

int findMax(int *a, int n)
{
    int result = *(a);
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) == result)
            continue;
        if (*(a + i) % 2 == 0 and *(a + i) > result)
            result = *(a + i);
    }

    if (result % 2 != 0)
        return -1;
    return result;
}

int sumSquare(int *a, int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int value = *(a + i);
        result += value * value;
    }
    return result;
}

void sortArr(int *a, int *n, int index)
{
    for (int i = index; i < *n; i++)
    {
        int swap = *(a + i);
        *(a + i) = *(a + i + 1);
        *(a + i + 1) = *(a + i);
    }
    *n -= 1;
}

void removeOdd(int *a, int *n)
{
    for (int i = 0; i < *n; i++)
    {
        if (*(a + i) % 2 != 0)
        {
            sortArr(a, n, i);
            i--;
        }
    }
}

int main()
{
    int n;
    do
    {
        printf("Nhap so luong phan tu (nho hon %d) n = ", MAX);
        scanf("%d", &n);
    } while (n > 100 || n < 1);

    // cap phat bo nho dong
    int *arr = (int *)malloc(n * sizeof(int));

    // Nhap mang so nguyen duong
    inputArr(arr, n);
    // Mang gia tri
    printf("Cac phan tu co trong mang: ");
    outputArr(arr, n);

    // Tim gia tri chan lon nhat
    int max = findMax(arr, n);
    if (max == -1)
        printf("Mang khong co gia tri chan. \n");
    else
        printf("Gia tri chan lon nhat la: %d \n", max);

    // Tong binh phuong
    printf("Tong binh phuong cac gia tri trong mang la: %d \n", sumSquare(arr, n));

    // Xoa casc gia tri le
    removeOdd(arr, &n);
    printf("Cac phan tu con lai sau khi xoa: ");
    outputArr(arr, n);

    return 0;
}