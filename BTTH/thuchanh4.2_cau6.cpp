#include <stdio.h>
int ackermann(int m, int n, long &a)
{
	a += 1;
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return ackermann(m - 1, 1, a);
	else
		return ackermann(m - 1, ackermann(m, n - 1, a), a);
}

int main()
{
	int n,m;
	long a = 0.0;
	printf("Nhap n: ");scanf("%d", &n);
	printf("Nhap m: ");scanf("%d", &m);
	int ack = ackermann(n, m, a);
	printf("So lan goi de quy la: %ld", a);
}
