#include <stdio.h>
//Dùng con trỏ, viết chương trình để thực hiện các phép tính số học.

int main() {
    int a = 9;
    int b = 5;

    int *ptr1, *ptr2;
    ptr1 = &a;
    ptr2 = &b;

    //Phép tính cộng
    int sum = *ptr1 + *ptr2;
    printf("Gia tri phep tinh cong su dung con tro la: %d\n", sum);

    //Phép tính trừ
    int sub = *ptr1 - *ptr2;
    printf("Gia tri phep tinh tru su dung con tro la: %d\n", sub);

    //Phép tính nhân
    int mult = *ptr1 * *ptr2;
    printf("Gia tri phep tinh nhan su dung con tro la: %d\n", mult);

    //Phép tính chia
    float div = (float)*ptr1 / (float)*ptr2;
    printf("Gia tri phep tinh chia su dung con tro la: %.2f\n", div);


    return 0;
}
