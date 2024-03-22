#include <stdio.h>
//Dùng con trỏ, viết hàm hoán đổi hai số (swap).
void swap(int *x, int *y);

int main() {
    int a = 36;
    int b = 45;

    int *ptr1, *ptr2;
    ptr1 = &a;
    ptr2 = &b;
    printf("Gia tri cua a truoc khi hoan doi la: %d\n", *ptr1);
    printf("Gia tri cua b truoc khi hoan doi la: %d\n", *ptr2);

    swap(ptr1, ptr2);
    printf("Gia tri cua a sau khi hoan doi la: %d\n", *ptr1);
    printf("Gia tri cua b sau khi hoan doi la: %d\n", *ptr2);

    return 0;
}

void swap( int *x, int *y) {
    int m = *x;
    *x = *y;
    *y = m;
}
