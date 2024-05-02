#include <stdio.h>

typedef struct Fractions
{
    int Numerator;
    int Denominator;
} Fractions;
// typedef struct Fractions Fractions;

// so sanh 2 phan so
int CompareFractions(struct Fractions fr1, struct Fractions fr2)
{
    double num1 = (double)fr1.Numerator / (double)fr1.Denominator;
    double num2 = (double)fr2.Numerator / (double)fr2.Denominator;

    if (num1 > num2)
    {
        return 1;
    }
    else if (num1 < num2)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
// nhap phan so
void ReadFractions(Fractions a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i].Numerator, &a[i].Denominator);
    }
}

void DisplayFractions(Fractions a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("(%d/%d)", a[i].Numerator, a[i].Denominator);
    }
}

// Tim uoc chung lon nhat voi thuat toan eculid
// Cach 1: su dung de quy
// int ucln(int a, int b)
// {
//     if (a % b == 0)
//     {
//         return b;
//     }

//     return ucln(b, a % b);
// }
// Cach 2 su dung vong lap
int ucln(int a, int b)
{
    // gia su a > b
    int uc = 1;
    if(a % b == 0)
        uc = b;
    while (a % b != 0)
    {
        int c = a;
        a = b;
        b = a % b;
        uc = b;
    }

    return uc;
}
// rut gon
void ReduceAllFractions(Fractions a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int uc;
        if(a[i].Numerator > a[i].Denominator)
            uc = ucln(a[i].Numerator, a[i].Denominator);
        else
            uc = ucln(a[i].Denominator, a[i].Numerator);
            
        a[i].Numerator = a[i].Numerator / uc;
        a[i].Denominator = a[i].Denominator / uc;
        if (uc < 0)
        {
            a[i].Numerator *= -1;
            a[i].Denominator *= -1;
        }
        // printf("(%d/%d) ", uc / a[i].Numerator, uc / a[i].Denominator);
        printf("ucln %d \n", uc);
    }
}

// tim so duong dau tien
Fractions FirstPositiveFrac(Fractions a[], int n)
{
    Fractions result;
    for (int i = 0; i < n; i++)
    {
        double num = (double)a[i].Numerator / (double)a[i].Denominator;
        if (num > 0.0)
        {
            result.Numerator = a[i].Numerator;
            result.Denominator = a[i].Denominator;
            return result;
        }
    }
    result.Numerator = -1080;
    result.Denominator = -1080;
    return result;
}

// dem so luong phan so duong
void CountPosNegFrac(Fractions a[], int n)
{
    int positive = 0;
    int negative = 0;
    for (int i = 0; i < n; i++)
    {
        double num = (double)a[i].Numerator / (double)a[i].Denominator;
        if (num > 0.0)
        {
            positive += 1;
        }
        else
        {
            negative += 1;
        }
    }
    printf("Number of Positive Fractions: %d\n", positive);
    printf("Number of Positive Fractions: %d\n", negative);
}
int main()
{
    // Bai 1
    // Fractions fr1 = {-1, -2};
    // Fractions fr2 = {-3, -2};
    // int c = CompareFractions(fr1, fr2);
    // printf("%d", c);

    // Bai 2
    // Fractions fracs[20];
    // int size = 1;
    // ReadFractions(fracs, size);
    // DisplayFractions(fracs, size);

    // Bai 3
    Fractions lsfrac[] = {{2, 4}, {6, 3}};
    // Fractions lsfrac[] = {{-1, 8}, {2, 10}};
    ReduceAllFractions(lsfrac, 2);
    DisplayFractions(lsfrac, 2);

    // // Bai 4
    // Fractions fracs[20] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    // int size = 5;
    // Fractions F = FirstPositiveFrac(fracs, size);
    // printf("%d/%d", F.Numerator, F.Denominator);
    // return 0;
}