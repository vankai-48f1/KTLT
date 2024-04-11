#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/**
Hàm xu ly file, lay so luong cac gia tri 
trong file va tinh tong cac gia tri do
*/
void processFile(char*fname, int*pCount, double *pSum)
{
	FILE *f = fopen(fname, "r");
	*pCount = 0; // dat lai gia tri dem ve 0
	*pSum=0; // dat lai gia tri tong ve 0
	double x; // bien ghi gia tri trong file
	
	while(fscanf(f, "%lf", &x) == 1) 
	{
		// Trong khi gia tri trong x chua gap ki tu EOF 
		(*pCount)++; // tang gia tri dem len 1
		(*pSum)+=x; // tang gia tri tong = tong + gia tri x (duoc doc tu file khi sd ham fscanf(f, "%lf", &x))
	}

	fclose(f); // dong file va giai phong bo nho dem cua file
}
int main()
{
	char infName[] ="array3.txt";
	int count = 0;
	double sum =0;
	processFile(infName, &count, &sum); // goi ham processFile de dem so luong gia tri va tinh tong
	printf("Number of values in the file:%d\n", count); // in ra so luong gia tri trong file
	printf("Average of values in the file:%lf\n", sum/count); // in ra trung binh cong cac gia tri trong file
	getchar();
	return 0;
}
