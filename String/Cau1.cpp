#include <stdio.h>
#include <string.h>
void nhapChuoi(char *s1, char *s2);
void xuatChuoi(char *s1, char *s2);
int doDai1Chuoi(char *str);
int soSanh2Chuoi(char *s1, char *s2);
char* noi2Chuoi(char *s1, char *s2);
char* kiemTraChuoi(char *s1, char *s2);

int main()
{
    char s1[50], s2[50];
    // a. Nhap vao 2 chuoi du lieu s1 va s2
    nhapChuoi(s1, s2);
    
    // b. Xuat ra màn hình hai chuoi vua nhap
    xuatChuoi(s1, s2);
    
    // c. Xuat ra do dai cua cac chuoi vua nhap
    printf("Do dai cua chuoi thu nhat la: %d \n", doDai1Chuoi(s1));
    printf("Do dai cua chuoi thu hai la: %d \n", doDai1Chuoi(s2));
    
    // d. So sanh hai chuoi s1 va s2
    int sosanh = soSanh2Chuoi(s1, s2);
    if(sosanh == 0)
    	printf("s1 bang s2 \n");
    else if (sosanh > 0)
    	printf("s1 lon hon s2 \n");
    else
    	printf("s1 be hon s2 \n");
    
    // e. noi chuoi s2 vai chuoi s1
    printf("Chuoi sau khi noi s2 vao s1 la: %s \n", noi2Chuoi(s1, s2));
    
    // f Kiem tra chuoi s1 co chua s2 hay khong
    char * ktraS2trongS1 = kiemTraChuoi(s1, s2);
    if(ktraS2trongS1 != NULL)
    	printf("s2 co trong s1 \n");
    else
    	printf("s2 khong co trong s1 \n");
    
    // f Kiem tra chuoi s2 co chua s1 hay khong
    char * ktraS1trongS2 = kiemTraChuoi(s2, s1);
    if(ktraS1trongS2 != NULL)
    	printf("s1 co trong s2 \n");
    else
    	printf("s1 khong co trong s2 \n");
    
    return 0;
}

void nhapChuoi(char *s1, char *s2)
{
    printf("Nhap chuoi s1: ");gets(s1);
    printf("Nhap chuoi s2: ");gets(s2);
}
void xuatChuoi(char *s1, char *s2)
{
    printf("Xuat chuoi s1: %s \n", s1);
    printf("Xuat chuoi s2: %s \n", s2);
}
int doDai1Chuoi(char *str)
{
	return strlen(str);
}
int soSanh2Chuoi(char *s1, char *s2)
{
	return strcmp(s1, s2);
}
char* noi2Chuoi(char *s1, char *s2)
{
	return strcat(s1, s2);
}
char* kiemTraChuoi(char *s1, char *s2)
{
	return strstr(s1, s2);
}
