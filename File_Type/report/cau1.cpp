#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100
#define TRUE 1
#define FALSE 0
#define FilePath "array1.txt"

int exist(char *fname)
{
    FILE *f = fopen(fname, "r");
    if (f != NULL)
    {
        fclose(f);
        return TRUE;
    }
    return FALSE;
}

int readFromFile(char *fname, int *a, int *pn)
{
    // Check file
    if (exist(fname) == FALSE)
    {
        printf("The file %s does not exist.\n", fname);
        return FALSE;
    }
    FILE *f = fopen(fname, "r");
    fscanf(f, "%d", pn); // luu gia tri dong dau tien vao pn chinh la do dai cua mang va con tro cua f dang o dia chi cua gia tri tiep theo

    for (int i = 0; i < *pn; i++)
    {
        fscanf(f, "%d", a + i);
    }
    return TRUE;
}

void printArr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
}

int isPrime(int num)
{
    // kiem tra tu 2 den can bac 2 cua num
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return FALSE;
        }
    }
    return TRUE;
}

int writePrimeToFile(char *fname, int *a, int n)
{
    if (exist(fname) == TRUE)
    {
        printf("The file %s existed, append it (Y/N). ", fname);
        if (toupper(getchar()) == 'N')
            return FALSE;
    }

    FILE *f = fopen(fname, "a");

    for (int i = 0; i < n; i++)
    {
        if (*(a + i) > 1 && isPrime(*(a + i)) == TRUE)
        {
            fprintf(f, " %d", *(a + i));
        }
    }
}

int main()
{
    int *a = (int *)malloc(sizeof(int) * MAX);
    int n = 0;

    // doc va nhap gia tri vao mang
    readFromFile(FilePath, a, &n);

    // xuat mang
    printf("Cac gia tri co trong mang la: ");
    printArr(a, n);
    printf("\n");

    // ghi cac so nguyen to vao mang
    writePrimeToFile(FilePath, a, n);

    return 0;
}