#include<stdio.h>
#include<string.h>
//Van de: Quan ly thong tin cua 100 sinh vien (doi tuong): mssv, hoten, ngaysinh, lop, dtb
typedef struct SINHVIEN
{
	//khai bao cac thuoc tinh/truong cua sinh vien
	char mssv[9]; //23715241
	char hoten[31];
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
	SINHVIEN m[100]; // kieudulieu tenbien; tenbien.thuoctinh
	int n;
	printf("So luong sinh vien (toi da 100):"); scanf("%d", &n); //dieu kien: n>=0 va n<=100
	
	for(int i = 0; i<n; ++i )
		nhap1SinhVien(m[i]);

	//xuat thong tin cua sinh vien ra man hinh
	for(int i = 0; i<n; ++i )
		xuat1SinhVien(m[i]);
		
	//liet ke sinh vien nganh CNTT
	printf("\nSinh vien CNTT\n");
	for(int i = 0; i<n; ++i )
		if(m[i].lop[2]=='T' && m[i].lop[3]=='H') //???DHTH19E
			xuat1SinhVien(m[i]);

}
