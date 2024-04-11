#include<stdio.h>
int uscln(int n1, int n2)
{	
	int c = n1 % n2;
	if(c == 0)
		return n2;	
	return uscln(n2, c);
}
int bscnn(int n1, int n2)
{
	if(n1 == n2)
		return n1;
	return n1*n2/uscln(n1,n2);
}

int main(){
	int n1, n2;
	do {
		printf("Nhap n1: ");scanf("%d", &n1);
	}while(n1 < 1);
	do {
		printf("Nhap n2: ");scanf("%d", &n2);
	}while(n2 < 1);

	printf("Uoc chung lon nhat la: %d\n", uscln(n1, n2));
	printf("Boi chung nho nhat la: %d\n", bscnn(n1, n2));
}
