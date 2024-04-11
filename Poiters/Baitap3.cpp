#include <stdio.h>
//Dùng con trỏ, viết chương trình để tìm giá trị lớn nhất giữa hai số.
int getMax(int *ptr1, int *ptr2);

int main() {
    int a = 100;
    int b = -5;

    int *ptr1, *ptr2;
    ptr1 = &a;
    ptr2 = &b;

    int max_val = getMax(ptr1, ptr2);
    if(max_val == 0)
        printf("Khong co gia tri lon nhat\n");
    else
        printf("Gia tri lon nhat giua hai so %d va %d la: %d\n", *ptr1, *ptr2, max_val);

    return 0;
}

int getMax(int *ptr1, int *ptr2) {
    int result;
    if (*ptr1 > *ptr2)
        result = *ptr1;
    else if (*ptr1 < *ptr2)
        result = *ptr2;
    else
        result = 0;

    return result;
}
