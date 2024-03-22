#include<stdio.h>
#include<string.h>
void nhapMang(int a[], int n)
{
	for (int i=0; i<n; i++){
		printf("Nhap ptu so %d = ", i +1);scanf("%d", &a[i]);
	}
}  
void xuatMang(int a[], int n)
{
	printf("\nCac ptu cua mang la: \n");
	for (int i=0; i<n; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
}
int sum(int a[], int n) {
	int s = 0;
	for (int i=0; i<n; i++){
		s += a[i];
	}
	return s;
}
int sumEven(int a[], int n) {
	int s = 0;
	for (int i=0; i<n; i++){
		if (a[i] % 2 == 0) s += a[i];
	}
	return s;
}
int countDuong(int a[], int n){
	int c = 0;
	for (int i=0; i<n; i++){
		if (a[i] > 0) c += 1;
	}
	return c;
}
int findMin(int a[], int n)
{
	int min = a[0];
	for (int i=0; i<n; i++){
		if (a[i] < min) min = a[i];
	}
	return min;
}
int findMax(int a[], int n)
{
	int max = a[0];
	for (int i=0; i<n; i++){
		if (a[i] > max) max = a[i];
	}
	return max;
}
int findEvenLast(int a[], int n)
{
	int last = 0;
	for(int i=0; i <n; i++){
		if (a[i] % 2 == 0 && a[i] != 0)
			last = a[i];
	}
	if (last != 0) 
		return last;
	return -1;
}
int fintItemInArr(int a[], int n, int val)
{
	int item = 0;
	for(int i=0; i <n; i++){
		if (a[i] == val && a[i] != 0)
			item = i;
	}
	if (item != 0) 
		return item;
	return -1;
}
int main(){
	int a[100];
	int n;
	do {
		printf("Nhap so luong phan tu n(n<100): ");scanf("%d", &n);
	} while(n > 100 || n < 0);
	
	// Nhap mang
	nhapMang(a, n);
	// Xuat mang
	xuatMang(a, n);
	// Tinh tong
	int tong = sum(a, n);
	printf("Tong cac gia tri co trong mang: %d\n", tong);
	// Tong chan
	int tong_chan = sumEven(a, n);
	printf("Tong cac gia tri chan co trong mang: %d\n", tong_chan);
	// So luong ptu duong
	int duong = countDuong(a, n);
	printf("So luong phan tu duong la: %d\n", duong);
	// Ptu lon nhat/nho nhat cua mang
	int min = findMin(a, n);
	int max = findMax(a, n);
	printf("Phan tu nho nhat la: %d\n", min);
	printf("Phan tu lon nhat la: %d\n", max);
	// Ptu chan cuoi cung
	int even_last = findEvenLast(a, n);
	if (even_last == -1) 
		printf("Khong co ptu chan trong mang.\n");
	else 
		printf("Phan tu chan cuoi cung trong mang la: %d\n", even_last);
	// Tim phan tu
	int val_tim;
	printf("Nhap gia tri ptu muon tim: ");scanf("%d", &val_tim);
	int result_find = fintItemInArr(a, n, val_tim);
	if (even_last == -1) 
		printf("Khong co gia tri trong mang.\n");
	else 
		printf("Phan tu co gia tri %d cuoi cung trong mang co vi tri la: %d\n", val_tim, result_find);

	return 0;
}