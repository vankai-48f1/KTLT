#include<stdio.h>
#include<string.h>
//Van de: Quan ly thong tin cua 100 sinh vien (doi tuong): mssv, hoten, ngaysinh, lop, dtb
typedef struct SINHVIEN
{
	//khai bao cac thuoc tinh/truong cua sinh vien
	char mssv[9]; //23715241
	char hoten[31];
	char ngaysinh[11]; //12/05/2005 -> kieu du lieu gi?
	char lop[8]; //DHTH19E
	float dtb;
};
void nhap1SinhVien(SINHVIEN &a)
{
	printf("\nNhap thong tin sinh vien:\n");
	printf("Ma so sinh vien:"); scanf("%s", &a.mssv);
	fflush(stdin); // xoa bo nho dem/cache
	printf("Ho ten:"); gets(a.hoten);
	printf("Ngay sinh:"); gets(a.ngaysinh);
	printf("Lop:"); gets(a.lop);
	printf("Diem trung binh:"); scanf("%f", &a.dtb);
}
void xuat1SinhVien(SINHVIEN a)
{
	printf("%s\t%s\t%s\t%s\t%.1f\n", a.mssv, a.hoten, a.ngaysinh, a.lop, a.dtb);
}
int main()
{
	SINHVIEN a, b; // kieudulieu tenbien; tenbien.thuoctinh
	nhap1SinhVien(a);
	nhap1SinhVien(b);
	
	//xuat thong tin cua sinh vien ra man hinh
	xuat1SinhVien(a);
	xuat1SinhVien(b);

}
