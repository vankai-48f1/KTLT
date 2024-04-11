/* XAC DINH CONG THUC TRUY HOI (DE QUY)
	G?i Sum(N) là t?ng các ch? s? c?a N
	Bài toán co s? (di?m d?ng): Sum(N) = N n?u N < 10
	Công th?c truy h?i: Sum(N) = N % 10 + Sum(N / 10) v?i N = 10

*/
#include<stdio.h>
int sum(int n) //HAM DE QUY
{
	if(n<10)
		return n;
	else
		return (n%10) + sum(n/10); // function call
}
int main()
{
	int n = 51345;
	int t = sum(n);
	printf("%d =", t);
}

//GT(5) = 5*GT(4) 
//GT(4) = 4* GT(3) 
//.... 
//GT(1) = 1*GT(0)
//GT(0) = 1
