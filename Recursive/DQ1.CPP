//Pn = Pn-1 + 0,11Pn-1 = (1,11)Pn-1 : truy hoi (de quy)
//p0 = 10000: dieu kien dung (co so)

#include<stdio.h>
double P(int n) //HAM DE QUY
{
	if(n==0)
		return 10000;
	else
		return 1.11*P(n-1);
}
int main()
{
	double t = P(30);
	printf("Sau 30 nam:%.2lf", t);
}
