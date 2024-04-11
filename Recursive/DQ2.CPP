/* XAC DINH CONG THUC TRUY HOI (DE QUY)
	 - goi GT(n) la giai thua cua n
	 - dieu kien dung: 0! =  1 hoac GT(0) = 1
	 - cong thuc truy hoi: GT(n) = n * GT(n-1) voi n>0
*/

#include<stdio.h>
double GT(int n) //HAM DE QUY
{
	if(n==0)
		return 1;
	else
		return n*GT(n-1); // function call
}
int main()
{
	int n = 5;
	double t = GT(n);
	printf("%d! = %.0lf",n, t);
}

//P(30) = 1.11*P(29) 
//P(29) = 1.11* P(28) 
//.... 
//P(1) = 1.11*P(0)
//P(0) = 10000
