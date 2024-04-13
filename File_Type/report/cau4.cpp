#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define TRUE 1
#define FALSE 0
#define FilePath "DSHH.txt"

typedef struct TRUONG
{
    char mh[5];
    int sl;
    float dg;
    float st;
};

void inputTruong(TRUONG *a)
{
    printf("Nhap ma hang: ");
    scanf("%s", &a->mh);
    printf("Nhap so luong: ");
    scanf("%d", &a->sl);
    printf("Nhap don gia: ");
    scanf("%f", &a->dg);
    // so tien = so luong * don gia
    a->st = ((float)a->sl) * (a->dg);
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
        printf("Nhap n phan tu (n < 100)");
        scanf("%d", &n);
    } while (n < 0 || n > 100);
    for
    inputTruong(ptruong);
    // fflush(stdin);

    // // Luu cac ky tu nguyen am vao file
    // writeFile(FilePath, a);

    // // Xuat File
    // printf("Xuat noi dung file: ");
    // readFile(FilePath);

    return 0;
}
