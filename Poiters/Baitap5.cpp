#include <stdio.h>
#define MAXN 100
//a) Nhập mảng số nguyên. b) Xuất ra mảng số nguyên vừa nhập.
//c) Xuất các số chẵn có trong mảng. d) Tìm giá trị lớn nhất trong mảng.

void inputArr(int *a, int *pn);
void printArr(int *a, int n);
void printEven(int *a, int n);
void printMax(int *a, int n);

int main() {
    int a[MAXN];
    int n;
    int maxVal;

    // a) Nhập mảng số nguyên.
    inputArr(a, &n);

    //b) Xuất ra mảng số nguyên vừa nhập
    printArr(a, n);

    //c) Xuất các số chẵn có trong mảng
    printEven(a, n);

    // d) Tìm giá trị lớn nhất trong mảng.
    printMax(a, n);
    return 0;
}

void inputArr(int *a, int *pn) {
    *pn = 0;
    printf("Nhap toi da %d phan tu, 0 de dung nhap: ", MAXN);
    int x;
    do {
        scanf("%d", &x);
        if(x != 0)
            a[(*pn)++] = x; // Su dung hau to (postfix) ++ đe tra ve bien coppy cua pn dau tien la 0

        if(x == 0 && *pn == 0)
            printf("Vui long nhap it nhat 1 phan tu vao mang: ");
    } while((x!=0 && *pn < MAXN) || *pn == 0);
}

void printArr(int *a, int n) {
    printf("Cac phan tu co trong mang la: ");
    for(int i=0; i < n; i++){
        printf("%d ", *(a + i));
    }
    printf("\n");
}

void printEven (int *a, int n) {
    printf("Cac so chan trong mang la: ");
    for(int i=0; i < n; i++){
        if(*(a + i) % 2 == 0)
            printf("%d ", *(a + i));
    }
    printf("\n");
}

void printMax(int *a, int n) {
    printf("Gia tri lon nhat co trong mang la: ");
    if(n==1) {
        printf("%d", *a);
        return;
    }

    int max_val = *a;
    for(int i = 1; i < n; i++){
        if( max_val < *(a + i))
            max_val = *(a + i);
    }
    printf("%d\n", max_val);
}
