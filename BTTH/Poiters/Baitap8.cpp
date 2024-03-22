#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 100
void inputArr(float *a, int *n);
void printArr(float *a, int n);
double average(float *a, int n);
double sumOfSquares(float *a, int n);
double variance(double ss, double m, int n);
double standardDeviation(double dd);
void insertElement(float *a, float x, int p, int *n);
void del(float *a, int *pt, int p);
int search(float *a, int *pt, float x);
void sortAscending(float *a, int *pt);
void sortDescending(float *a, int *pt);

int main() {
    float a[MAXN], x;
    int n, p;
    int *pt = &n;
    // a) Nhap mang so thuc
    inputArr(a, pt);
    // b) Xuat cac phan tu mang
    printArr(a, n);
    // c) Tính giá trị trung bình của mảng
    double m = average(a, n);
    printf("Gia tri trung binh cua mang la: %lf\n", m);
    // d) Tính tổng bình phương
    double ss = 0.0;
    ss = sumOfSquares(a, n);
    printf("Tong binh phuong la: %lf\n", ss);
    // e) Tính phương sai
    double dd = variance(ss, m, n);
    printf("Phuong sai la: %lf\n", dd);
    // e) Tính độ lệch chuẩn
    double d = standardDeviation(dd);
    printf("Do lech chuan la: %lf\n", d);
    // g) Thêm giá trị X vào vị trí P (X, P nhập từ bàn phím);
    printf("\nNhap gia tri can chen x: "); scanf("%f", &x);
    do {
        printf("\nNhap vi tri can chen p: "); scanf("%d", &p);
    } while(p > (MAXN-1) || p < 0);
    insertElement(a, x, p, pt);
    printArr(a, n);
    // h) Xóa phần tử tại ví trí P (P nhập từ bàn phím)
    do {
        printf("\nNhap vi tri can xoa p: "); scanf("%d", &p);
    } while(p > (*pt -1) || p < 0);
    del(a, pt, p);
    printArr(a, n);
    // i) Tìm kiếm giá trị X trong mảng (X nhập từ bàn phím)
    printf("\nNhap so can tim x: ");scanf("%f", &x);
    int kq = search(a, pt, x);
    if(kq==-1) printf("Khong tim thay %f trong mang\n", x);
    else printf("Tim thay %f trong mang o vi tri %d\n", x, kq);

    // j) Sắp xếp mảng tăng dần
    sortAscending(a, pt);
    printf("Sap xep mang tang dan\n");
    printArr(a, n);
    // j) Sắp xếp mảng giam dần
    sortDescending(a, pt);
    printf("Sap xep mang giam dan\n");
    printArr(a, n);
}

void inputArr(float *a, int *pn) {
    *pn = 0;
    printf("Nhap mang so thuc, toi da %d phan tu, 0 de dung nhap: ", MAXN);
    float x;
    do {
        scanf("%f", &x);
        if(x != 0.00)
            a[(*pn)++] = x; // Su dung hau to (postfix) ++ đe tra ve bien coppy cua pn dau tien la 0

        if(x == 0 && *pn == 0)
            printf("Vui long nhap it nhat 1 phan tu vao mang: ");
    } while((x!=0.00 && *pn < MAXN) || *pn == 0);
}

void printArr(float *a, int n) {
    printf("Cac phan tu co trong mang la: ");
    for(int i=0; i<n; i++){
        printf("%f ", *(a + i));
    }
    printf("\n");
}

double average(float *a, int n) {
    double m = 0.0;
    for(int i=0; i<n; i++){
        m += *(a + i);
    }
    return (m /n);
}

double sumOfSquares(float *a, int n) {
    double ss = 0.0;
    for(int i=0; i<n; i++){
        ss += pow(*(a + i), 2);
    }
    return ss;
}

double variance(double ss, double m, int n) {
    double d = (ss/n) - pow(m, 2);
    return pow(d, 2);
}

double standardDeviation(double dd) {
    return sqrt(dd);
}

void insertElement(float *a, float x, int p, int *pt) {
    if ( p >= *pt ) {
        a[*pt] = x;
    } else {
        for(int i=*pt; i > p; i--) a[i]=a[i-1];
        a[p]=x;
    }
    (*pt)++;
}

void del(float *a, int *pt, int p) {
    if(*pt==0)printf("\nEmpty!");
	else{
        for(int i=p; i<*pt; i++)a[i]=a[i+1];
        (*pt)--;
	}
}

int search(float *a, int *pt, float x) { // a={1,5,3,7}; n=4; x=9
    int i = 0;
    while(i<*pt && a[i]!=x)i++;
    if(i==*pt)return -1; else return i;
}
void sortAscending(float *a, int *pt) {
    for(int i=0; i<*pt; i++) {
        for(int j=i+1; j<*pt; j++){ //9 2 3 8 5 9
            if(a[i]>a[j]){
                a[i] = a[i]+a[j];
                a[j] = a[i]-a[j];
                a[i] = a[i]-a[j];
            }
        }
    }
}
void sortDescending(float *a, int *pt) {
    for(int i=0; i<*pt; i++) {
        for(int j=i+1; j<*pt; j++){
            if(a[i]<a[j]){
                a[i] = a[i]+a[j];
                a[j] = a[i]-a[j];
                a[i] = a[i]-a[j];
            }
        }
    }
}
