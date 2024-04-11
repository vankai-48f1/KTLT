#include <stdio.h>
#include <stdlib.h>
//Viết chương trình sử dụng vùng bộ nhớ cấp phát động (HEAP SEGMENT) cho
//phép người dùng nhập 2 số thực. Tính tổng, hiệu, tích, thương của chúng

int main() {
    float *ptr1, *ptr2;
    ptr1 = (float*)malloc(sizeof(float));
    ptr2 = (float*)malloc(sizeof(float));
    printf("Nhap 2 so thuc: ");scanf("%f%f", ptr1, ptr2);

    //Tổng
    float sum = *ptr1 + *ptr2;
    printf("Tong cua %f + %f = %f\n", *ptr1, *ptr2, sum);

    //Hiệu
    float sub = *ptr1 - *ptr2;
    printf("Hieu cua %f - %f = %f\n", *ptr1, *ptr2, sub);

    //Tích
    float mult = *ptr1 * *ptr2;
    printf("Tich cua %f * %f = %f\n", *ptr1, *ptr2, mult);

    //Thương
    float div = (float)*ptr1 / (float)*ptr2;
    printf("Thuong cua %f / %f = %f\n", *ptr1, *ptr2, div);

    return 0;
}

