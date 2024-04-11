#include<stdio.h>
int deQuyFibonacy(int n)
{
	if(n == 0 || n == 1)
		return 1;
	return deQuyFibonacy(n-1)  + deQuyFibonacy(n-2);
}
int main(){
	int n;
	do {
		printf("Nhap n: ");scanf("%d", &n);
	}while(n < 1);

	printf(" %d so dau tien cua day Fibonacy la: ", n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", deQuyFibonacy(i)); 
	}
}
