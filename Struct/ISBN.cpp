#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct sach {
    char ISBN[20];
    char ten[40];
    char nxb[40];
    char tacgia[40];
    time_t ngaytim;
} sach;

void nhap(sach *a) {
    fflush(stdin);
    printf("Tua\t>"); gets(a->ten);
    printf("ISBN\t>"); gets(a->ISBN);
    printf("Tac gia\t>"); gets(a->tacgia);
    printf("NXB\t>"); gets(a->nxb);
    time(&a->ngaytim);
    fflush(stdin);
}

void xuat(sach a) {
    printf("%s\n", a.ten);
    printf("%s\n", a.ISBN);
    printf("%s\n", a.tacgia);
    printf("%s\n", a.nxb);

    struct tm *local_time;
    // Chuyển đổi thời gian thành cấu trúc struct tm
    local_time = localtime(&a.ngaytim);
    // Truy cập các thành phần của cấu trúc struct tm để lấy ngày, tháng, năm
    int day = local_time->tm_mday;
    int month = local_time->tm_mon + 1; // Tháng bắt đầu từ 0, nên cộng thêm 1
    int year = local_time->tm_year + 1900; // Năm bắt đầu từ 1900
    // In ra ngày/tháng/năm
    printf("[uppdate: %02d/%02d/%d]", day, month, year);
}

void tim(sach a[], int n, char is[]) {
    for(int i = 0; i < n; i++) {
        if(strcmp(a[i].ISBN, is) == 0) {
            xuat(a[i]);
        }
    }
}

int main() {
    sach a[50];
    int n = 0;
    char yn;
    do {
        printf("Nhap thong tin sach:\n");
        nhap(&a[n]);
        n++;
        printf("Tiep (y/n)?: "); scanf(" %c", &yn);
    } while(tolower(yn) == 'y');

    char is[20];
    fflush(stdin);
    printf("ISBN? "); scanf("%19s", is);
    printf("thong tin can tim:\n");
    tim(a, n, is);
    return 0;
}
