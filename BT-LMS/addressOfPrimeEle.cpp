#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Số nguyên tố là số có ước số là 1 và chính nó
 * vd 103 = (1, 103)
 * Tip: Kiểm tra xem số đó có chia hết cho các số bé hơn căn bậc 2 của nó hay không.
 */
int isPrime(int square, int num)
{
    int result = 1;
    for (int i = 0; i < square; i++)
    {
        if (num % i == 0)
            result = 0;
    }
    return result;
}
// int *AddressOfPrimeEle(int A[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (isPrime(ceil(sqrt(A[i])), A[i]) == 1)
//             return &A[i];
//     }
//     return NULL;
// }
int *AddressOfPrimeEle(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {

        int isPrime = 1;

        if (A[i] <= 1)
        {
            isPrime = 0; // Không phải số nguyên tố
        }
        else
        {
            double square = sqrt(A[i]);
            int sq = (int)ceil(square);
            if (A[i] == 2)
            {
                return &A[i];
            }
            for (int j = 2; j <= sq; j++)
            {
                if (A[i] % j == 0)
                {
                    isPrime = 0; // Không phải số nguyên tố
                }
            }
        }
        if (isPrime == 1)
            return &A[i];
    }
    return NULL;
}
int main()
{
    // int n;
    // do
    // {
    //     printf("Nhap n: ");
    //     scanf("%d", &n);
    // } while (n <= 0 || n > 10000);

    // int *a = (int *)malloc(n * sizeof(int));

    // printf("nhap ho va ten: ");
    // scanf("%s", a);
    int n = 5;
    int A[] = {1,8,4,10,6};
    int *p = AddressOfPrimeEle(A, n);
    if (p != NULL)
        printf("%d", *p);
    else
        printf("NULL");
    return 0;
}