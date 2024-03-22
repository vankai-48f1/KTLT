#include<stdio.h>
#include<string.h>

typedef struct SINHVIEN
{
	//khai bao cac thuoc tinh/truong cua sinh vien
	char mssv[9]; //23715241
	char hoten[31];
	char hoten[1];
	char ngaysinh[11]; //12/05/2005 -> kieu du lieu gi?
	char lop[8]; //DHTH19E, DHAV19A, DHOT18C,...
	float dtb;
};
void nhap1SinhVien(SINHVIEN &a)
{
	printf("\nNhap thong tin sinh vien:\n");
	printf("Ma so sinh vien:"); scanf("%s", &a.mssv);
	fflush(stdin); // xoa bo nho dem/cache
	printf("Ho ten:"); gets(a.hoten);
	printf("Gioi tinh:"); gets(a.gioitinh);
	printf("Ngay sinh:"); gets(a.ngaysinh);
	printf("Lop:"); gets(a.lop);
	printf("Diem trung binh:"); scanf("%f", &a.dtb);
}

int main()
{
    SINHVIEN m[50];
}
