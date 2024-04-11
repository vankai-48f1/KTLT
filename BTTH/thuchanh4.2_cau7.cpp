#include <stdio.h>
void thapHaNoi(int n , char a, char b, char c ){
	if(n==1){
		printf("t%c----%cn",a,c);
		return;
	}
	thapHaNoi(n-1,a,c,b);
	thapHaNoi(1,a,b,c);
	thapHaNoi(n-1,b,a,c);
	}
int main(){
	char a='A', b='B', c='C';
	int n;
	printf("Nhap so dia n: ");
	scanf("%d",&n);
	thapHaNoi(n,a,b,c);
}