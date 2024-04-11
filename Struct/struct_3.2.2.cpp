#include <stdio.h>
#include <string.h>

typedef struct BUUKIEN
{
	// khai bao cac thuoc tinh/truong cua buu kien
	int code;
	char sender[30];
	char receiver[30];
	float weight;
	char date[11];
	char messenge[50];
	float price;
};
void nhap1BuuKien(BUUKIEN &a)
{
	printf("\nNhap thong tin buu kien:\n");
	printf("Ma so buu kien: ");
	scanf("%d", &a.code);
	fflush(stdin); // xoa bo nho dem/cache
	printf("Ten nguoi gui: ");
	gets(a.sender);
	printf("Ten nguoi nhan: ");
	gets(a.receiver);
	printf("Trong luong(kg): ");
	scanf("%f", &a.weight);
	fflush(stdin); // xoa bo nho dem/cache
	printf("Ngay gui: ");
	gets(a.date);
	printf("Noi dung buu kien: ");
	gets(a.messenge);
	printf("Don gia: ");
	scanf("%f", &a.price);
}
void xuat1BuuKien(BUUKIEN a)
{
	printf("%d\t%s\t%s\t%.2f\t%s\t%s\t%.1f\t\n", a.code, a.sender, a.receiver, a.weight, a.date, a.messenge, a.price);
}
void xuatDsBuuKien(BUUKIEN a[], int n)
{
	for (int i = 0; i < n; i++)
		xuat1BuuKien(a[i]);
}
void them1BuuKien(BUUKIEN a[], BUUKIEN &moi, int &n)
{
	a[n] = moi;
	n += 1;
}
void sapXepBuuKien(BUUKIEN a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (a[i].code > a[j].code)
			{
				BUUKIEN c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
	}
}
BUUKIEN samples[] = {
	{9000, "Nguyen Tuan Anh", "Tran Tuan My", 4.2, "23/03/2024", "Gui buu kien", 25000},
	{74000, "Vo Tuan An", "Nguyen Thi ha My", 5.9, "23/03/2024", "Gui buu kien", 35000},
	{65000, "Tran Mang Quan", "Vo Tuan An", 7.5, "23/03/2024", "Gui buu kien", 30000},
	{14000, "Tran Tuan My", "Nguyen Thi ha My", 9.2, "23/03/2024", "Gui buu kien", 50000},
};
int main()
{
	BUUKIEN a[50];
	int n;
	// printf("So luong buu kien (toi da 50):");
	// scanf("%d", &n);

	// Nhap danh sach buu kien
	n = 4;
	for (int i = 0; i < n; i++)
		a[i] = samples[i];

	// Xuat danh sach buu kien
	xuatDsBuuKien(a, n);

	// Thêm một bưu kiện vào danh sách
	BUUKIEN moi;
	nhap1BuuKien(moi);
	them1BuuKien(a, moi, n);
	printf("\nDanh sach buu kien sau khi them\n");
	xuatDsBuuKien(a, n);

	// Sắp xếp danh sách các bưu kiện theo mã bưu kiện
	sapXepBuuKien(a, n);
	printf("\nDanh sach buu kien sau khi sap xep\n");
	xuatDsBuuKien(a, n);

	// Tính giá trị của mỗi bưu kiện biết giá trị = trọng lượng x đơn giá gửi.
	for (int i = 0; i < n; i++)
	{
		float gtri = a[i].weight * a[i].price;
		printf("\nGia tri cua buu dien so %d la: %.2f\n", i + 1, gtri);
	}

	// SĐếm số lượng bưu kiện có trọng lượng lớn nhất
	float top_weight = 0.0;
	for (int i = 0; i < n; ++i)
		if (a[i].weight > top_weight)
			top_weight = a[i].weight;
	printf("\nCac buu kien co trong luong lon nhat la: \n");
	for (int i = 0; i < n; ++i)
		if (a[i].weight == top_weight)
			xuat1BuuKien(a[i]);
}
