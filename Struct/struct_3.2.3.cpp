#include <stdio.h>
#include <string.h>
typedef struct DATE
{
	int ngay, thang, nam;
};
typedef struct THUEBAODT2
{
	// Thông tin mỗi thuê bao gồm
	int code;
	char owner[30];
	DATE ngaydangki; // 19/10/20200
	char sdt[11];
	char type[3]; // TT or TS
	float timein;
	float timeout;
};
typedef struct THUEBAODT
{
	// Thông tin mỗi thuê bao gồm
	int code;
	char owner[30];
	char date[11]; // 19/10/20200
	char sdt[11];
	char type[3]; // TT or TS
	float timein;
	float timeout;
};
void nhap1ThueBaoLoai2(THUEBAODT2 &a)
{
	printf("\nNhap thong thue bao:\n");
	printf("Ma thue bao: ");
	scanf("%d", &a.code);
	fflush(stdin); // xoa bo nho dem/cache
	printf("Ho ten chu thue bao: ");
	gets(a.owner);
	printf("Ngay dang ky: ");
	scanf("%s", &a.ngaydangki.ngay, &a.ngaydangki.thang, &a.ngaydangki.nam);
	fflush(stdin); // xoa bo nho dem/cache
	printf("So dien thoai: ");
	scanf("%s", &a.sdt);
	printf("Loai thue bao(TT/TS): ");
	scanf("%s", &a.type);
	printf("Thoi gian goi noi mang(phut): ");
	scanf("%f", &a.timein);
	printf("Thoi gian goi noi ngoai mang(phut): ");
	scanf("%f", &a.timeout);
}
void nhap1ThueBao(THUEBAODT &a)
{
	printf("\nNhap thong thue bao:\n");
	printf("Ma thue bao: ");
	scanf("%d", &a.code);
	fflush(stdin); // xoa bo nho dem/cache
	printf("Ho ten chu thue bao: ");
	gets(a.owner);
	printf("Ngay dang ky: ");
	scanf("%s", &a.date);
	printf("So dien thoai: ");
	scanf("%s", &a.sdt);
	printf("Loai thue bao(TT/TS): ");
	scanf("%s", &a.type);
	printf("Thoi gian goi noi mang(phut): ");
	scanf("%f", &a.timein);
	printf("Thoi gian goi noi ngoai mang(phut): ");
	scanf("%f", &a.timeout);
}
void xuat1ThueBao(THUEBAODT a)
{
	printf("%d\t%s\t%s\t%s\t%s\t%f\t%f\t\n", a.code, a.owner, a.date, a.sdt, a.type, a.timein, a.timeout);
}
void xuat1ThueBaoLoai2(THUEBAODT2 a)
{
	printf("%d\t%s\t%d/%d/%d\t%s\t%s\t%f\t%f\t\n", a.code, a.owner, a.ngaydangki.ngay, a.ngaydangki.thang, a.ngaydangki.nam, a.sdt, a.type, a.timein, a.timeout);
}
void xuatDsThueBao(THUEBAODT a[], int n)
{
	for (int i = 0; i < n; i++)
		xuat1ThueBao(a[i]);
}
void them1ThueBao(THUEBAODT a[], THUEBAODT &moi, int &n)
{
	a[n] = moi;
	n += 1;
}
void sapXepThueBao(THUEBAODT a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (a[i].code > a[j].code)
			{
				THUEBAODT c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
	}
}
int timThueBao(THUEBAODT a[], int n, char owner[])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].owner, owner) == 0)
		{
			return i;
		}
	}
	return -1;
}
void xuatThueBaoTheoLoai(THUEBAODT a[], int n, char type[])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].type, type) == 0)
		{
			xuat1ThueBao(a[i]);
		}
	}
}
char *getNam(char date[11])
{
	char nam[4];
	int length = strlen(date);
	for (int i = length - 4; i < length; i++)
	{
		printf("%c", date[i]);
	}
}
void xuatThueBaoSau2020(THUEBAODT a[], int n)
{
	// for (int i = 0; i < n; i++)
	// {

	// }
}
THUEBAODT samples[] = {
	{123, "Nguyen Tuan Anh", "23/03/2019", "0988720321", "TS", 5.2, 3.4},
	{543, "Vo Tuan An", "23/03/2017", "0988720321", "TT", 5.2, 3.4},
	{572, "Tran Mang Quan", "23/03/2022", "0988720321", "TT", 5.2, 3.4},
	{398, "Tran Tuan My", "23/03/2024", "0988720321", "TS", 5.2, 3.4},
};
int main()
{
	THUEBAODT a[50];
	int n;
	// printf("So luong buu kien (toi da 50):");
	// scanf("%d", &n);

	// Nhập thông tin của các thuê bao
	n = 4;
	for (int i = 0; i < n; i++)
		a[i] = samples[i];

	// Xuất thông tin của các thuê bao
	xuatDsThueBao(a, n);

	// // Thêm một thuê bao vào danh sách
	// THUEBAODT moi;
	// nhap1ThueBao(moi);
	// them1ThueBao(a, moi, n);
	// printf("\nDanh sach thue bao sau khi them\n");
	// xuatDsThueBao(a, n);

	// // Sắp xếp danh sách các thuê bao theo mã thuê bao
	// sapXepThueBao(a, n);
	// printf("\nDanh sach thue bao sau khi sap xep\n");
	// xuatDsThueBao(a, n);

	// // Tìm thuê bao theo họ tên chủ thuê bao
	// char tb_tim[30];
	// fflush(stdin);
	// printf("\nNhap ho ten chu thue bao can tim: ");
	// gets(tb_tim);

	// int kq_tim = timThueBao(a, n, tb_tim);
	// if (kq_tim != -1)
	// {
	// 	printf("\nThue bao co ho ten %s o vtri so %d co thong tin la: \n", tb_tim, kq_tim);
	// 	xuat1ThueBao(a[kq_tim]);
	// }
	// else
	// 	printf("\n\tKhong tim thay sinh vien co ho ten la %s", tb_tim);

	// // Xuất các thuê bao theo loại
	// char type[3];
	// printf("\nNhap loai thue bao(TS/TT): ");
	// scanf("%s", type);
	// xuatThueBaoTheoLoai(a, n, type);

	// Xuất các thuê bao đăng kí sau năm 2020
	// xuatThueBaoSau2020(a, n);
	THUEBAODT2 b[1];
	nhap1ThueBaoLoai2(b[0]);
	printf("Xuat Thue Bao Loai 2: ");
	xuat1ThueBaoLoai2(b[0]);
}
