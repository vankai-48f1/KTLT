#include<stdio.h>
int tongCacChuSoNguyen(int n)
{
	if(n == 0)
		return 0;
	return (n % 10) + tongCacChuSoNguyen(n / 10);
}
int main(){
	int n;
	printf("Nhap so nguyen n: ");scanf("%d", &n);
	printf("Tong cac chu so nguyen la: %d", tongCacChuSoNguyen(n));
}
