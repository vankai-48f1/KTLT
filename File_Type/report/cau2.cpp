#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define TRUE 1
#define FALSE 0
#define duongdan "test.inp"

// sinh ma tran ngau nhien su dung ham rand() va srand() trong thu vien stdlib.h
void SinhMT(int a[MAX][MAX], int d, int c)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
        {
            a[i][j] = rand();
        }
    }
}

// Ghi ma tran vao file
int LuuFile(int a[MAX][MAX], int d, int c)
{
    FILE *f = fopen(duongdan, "wt");
    if (f == NULL)
    {
        printf("\nKhong tao duoc file.");
        return FALSE;
    }
    fprintf(f, "%d %d \n", d, c);
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
        {
            fprintf(f, "%d\t", a[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    return TRUE;
}

// Du du lieu tu file ra bien mang luu ma tran
int DocFile(int a[MAX][MAX], int &d, int &c)
{
    /*
    Mo file nhu tren
    Doc so dong, so cot
    Doc gia tri cac phan tu cua ma tran
    Dong file
    */
    FILE *f = fopen(duongdan, "r");
    if (f == NULL)
    {
        printf("\nFile khong ton tai.");
        return FALSE;
    }
    fscanf(f, "%d", &d);
    fscanf(f, "%d", &c);
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int num;
            fscanf(f, "%d", &num);
            a[i][j] = num;
        }
    }

    fclose(f);
    return TRUE;
}

// Xuat ma tran
void XuatMT(int a[MAX][MAX], int d, int c)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[MAX][MAX], d = 5, c = 6;
    int b[MAX][MAX], x, y;
    SinhMT(a, d, c);
    LuuFile(a, d, c); // Ghi du lieu tu mang a xuong file
    DocFile(b, x, y); // Doc du lieu tu file ra mang b
    XuatMT(b, x, y);

    return 0;
}