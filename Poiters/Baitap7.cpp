#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void swap(char *x, char *y);
/*
* Viet chung trinh su dung bo nho cap phat dong cho phep nguoi dung nhap 2 ky tu,
* sau do huong trinh se in ra cac ky tu giua 2 ky tu nay theo thu tu tang dan.
*/

int main() {
    char *pc1, *pc2;
    pc1 = (char*)malloc(sizeof(char));
    pc2 = (char*)malloc(sizeof(char));
    printf("Nhap 2 ky tu: ");scanf("%c%c", pc1, pc2);
    // Dua ve ky tu in hoa
    *pc1 = toupper(*pc1);
    *pc2 = toupper(*pc2);

    // Hoan vi neu chu truoc lon hon chu sau
    if(*pc1 > *pc2)
        swap(pc1, pc2);
    // Hien thi ky tu tang dan
    for(int i = *pc1; i <= *pc2; i++) {
        printf("\n%c %4d %4o %4X", i, i, i, i);
    }

    return 0;
}

void swap( char *x, char *y) {
    int m = *x;
    *x = *y;
    *y = m;
}
