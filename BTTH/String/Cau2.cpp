#include <stdio.h>
#include <string.h>
void nhapChuoi(char *s1, char *s2);

int main()
{
    char s1[50], s2[50];
    // a. Nhap vao 2 chuoi du lieu s1 va s2
    nhapChuoi(s1, s2);
    return 0;
}

voi nhapChuoi(char *s1, char *s2)
{
    sprintf("Nhap chuoi s1: /n");gets(s1);
    sprintf("Nhap chuoi s2: /n");gets(s2);
}
