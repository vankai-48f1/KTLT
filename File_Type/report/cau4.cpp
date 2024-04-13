#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define TRUE 1
#define FALSE 0
#define FilePath "DSHH.txt"

struct TRUONG
{
    char mh[5];
    int sl;
    float dg;
    float st;
};

void inputTruong(TRUONG *a)
{
    printf("\tNhap ma hang: ");
    scanf("%s", a->mh);
    printf("\tNhap so luong: ");
    scanf("%d", &a->sl);
    printf("\tNhap don gia: ");
    scanf("%f", &a->dg);
    // so tien = so luong * don gia
    a->st = ((float)a->sl) * (a->dg);
}
void outputTruong(TRUONG *a)
{
    printf("%s\t%d\t%f\t%f\t", a->mh, a->sl, a->dg, a->st);
}

int exist(char *fname)
{
    FILE *f = fopen(fname, "r");

    if (f == NULL)
    {
        printf("File does not exist.");
        return FALSE;
    }
    fclose(f);
    return TRUE;
}
int writeFile(char *fname, TRUONG *a, int n)
{
    fflush(stdin);
    // Check file
    if (exist(fname) == TRUE)
    {
        printf("The file %s existed, append it (Y/N). ", fname);
        if (toupper(getchar()) == 'N')
            return FALSE;
    }

    // open file and write content into file
    FILE *f = fopen(fname, "w");

    // loop struct TRUONG and write to file
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%s, %d, %.2f, %.2f\n", (a + i)->mh, (a + i)->sl, (a + i)->dg, (a + i)->st);
    }

    fclose(f);
    return TRUE;
}

int readFile(char *fname)
{
    // Check file
    if (exist(fname) == FALSE)
    {
        printf("The file %s does not exist.\n", fname);
        return FALSE;
    }
    FILE *f = fopen(fname, "r");

    TRUONG *a;
    while (fscanf(f, "%[^,], %d, %f, %f", a->mh, &a->sl, &a->dg, &a->st) != EOF)
    {
        outputTruong(a);
    }

    fclose(f);
    return TRUE;
}

int main()
{
    TRUONG *ptruong = (TRUONG *)malloc(sizeof(TRUONG) * MAX);
    if (ptruong == NULL)
    {
        printf("Khong du bo nho.");
        return 1;
    }

    int n;
    do
    {
        printf("Nhap n phan tu (n < 100): ");
        scanf("%d", &n);
    } while (n < 0 || n > 100);

    fflush(stdin);

    for (int i = 0; i < n; i++)
    {
        printf("Nhap Truong so %d: \n", i + 1);
        inputTruong((ptruong + i));
    }

    // // Luu cac ky tu nguyen am vao file
    writeFile(FilePath, ptruong, n);

    // Xuat File
    printf("Xuat noi dung file: \n");
    readFile(FilePath);

    return 0;
}
