#include <stdio.h>
#include <math.h>

int *AddressOfEvenArr(int A[], int n)
{
    int arr[n];
    int inc = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0)
        {
            arr[inc] = A[i];
            inc++;
        }
    }
    int *p = arr;
    return p;
}
int main()
{
    int n;
    do
    {
        printf("Nhap n: ");
        scanf("%d", &n);
    } while (n <= 0 || n > 10000);

    int *a = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("nhap ptu thu %d", i);
        scanf("%d", a + i);
    }

    // AddressOfEvenArr
    int *parr = AddressOfEvenArr(a, n);
    printf("%d", *parr);
    return 0;
}