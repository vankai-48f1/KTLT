/* DE QUY TREN MANG 1 CHIEU

*/

#include<stdio.h>
/*tong cac phan tu trong mang
	cong thuc truy hoi
	- goi sum(a, n) la tong cac phan tu trong mang
	- dieu kien dung: khi n = 0 thi sum = 0
	- tong quat: sum(a, n) = sum(a, n-1) + a[n] (cuoi cung)
*/
int sum(int a[], int n)
{
	if(n == 0)
		return 0;
	else
		return sum(a, n-1) + a[n-1];
}
int sum1(int a[], int n)
{
	if(n == 1)
		return a[0];
	else
		return sum(a, n-1) + a[n-1];
}
/* tong cac gia tri chan trong mang
	cong thuc truy hoi
	- goi sumC(a, n) la tong cac phan tu CHAN trong mang
	- dieu kien dung: sumC = 0 khi n = 0 hoac: sumC(a, 0) = 0
	- tong quat: sumC(a, n) = sumC(a, n-1) + a[n-1] neu a[n-1] la so chan
				sumC(a, n) = sumC(a, n-1) neu a[n-1] la so le
*/

int sumC(int a[], int n)
{
	if(n == 0)	return 0;
	else
	{
		if(a[n-1]%2==0)
			return a[n-1] + sumC(a, n-1);
		else
			return sumC(a, n-1);
	}
}
//dem so luong so le trong mang
int demLe(int a[], int n)
{
	if(n == 0)
		return 0;
	else
	{
		if(a[n-1]%2==1)
			return 1 + demLe(a, n-1);
		else return demLe(a, n-1);
	}
}
int main()
{
	int a[] = {5, 2, 6, 8, 5, 4, 8}, n = 7;
	printf("Tong = %d", sum1(a, n));
}
