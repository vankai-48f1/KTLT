#include <stdio.h>
#include <string.h>

typedef struct SINHVIEN
{
	// khai bao cac thuoc tinh/truong cua sinh vien
	char mssv[9]; // 23715241
	char hoten[31];
	char gioitinh[2];
	char ngaysinh[11]; // 12/05/2005 -> kieu du lieu gi?
	char lop[8];	   // DHTH19E, DHAV19A, DHOT18C,...
	float dtb;
};
void nhap1SinhVien(SINHVIEN &a)
{
	printf("\nNhap thong tin sinh vien:\n");
	printf("Ma so sinh vien:");
	scanf("%s", &a.mssv);
	fflush(stdin); // xoa bo nho dem/cache
	printf("Ho ten:");
	gets(a.hoten);
	printf("Gioi tinh:");
	gets(a.gioitinh);
	printf("Ngay sinh:");
	gets(a.ngaysinh);
	printf("Lop:");
	gets(a.lop);
	printf("Diem trung binh:");
	scanf("%f", &a.dtb);
}
void xuat1SinhVien(SINHVIEN a)
{
	printf("%s\t%s\t%s\t%s\t%s\t%.1f\t\n", a.mssv, a.hoten, a.gioitinh, a.ngaysinh, a.lop, a.dtb);
}
void xuatDsSinhVien(SINHVIEN a[], int n)
{
	for (int i = 0; i < n; i++)
		xuat1SinhVien(a[i]);
}
void them1SvVaoCuoi(SINHVIEN a[], SINHVIEN &svmoi, int *n)
{
	a[*n] = svmoi;
	*n += 1;
}
void xoasv(SINHVIEN a[], int &n, int vtri)
{
	for (vtri; vtri < n; vtri++)
	{
		a[vtri] = a[vtri + 1];
	}
	n--;
}
int timsv(SINHVIEN a[], int n, char mssv[])
{
	for (int i = 0; i < n; i++)
	{
		int map = 0;
		for (int j = 0; j < 9; j++)
		{
			if (a[i].mssv[j] != mssv[j])
				continue;
			else
				map++;
		}
		if (map == 9)
			return i;
	}
	return -1;
}
void sapXepSv(SINHVIEN a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (a[i].dtb > a[j].dtb)
			{
				SINHVIEN c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
	}
}
SINHVIEN samples[] = {
	{"23637151", "Nguyen Tuan Anh", "y", "11/05/2005", "DHTH19E", 9.7},
	{"23637152", "Tran Tuan My", "y", "12/01/2005", "DHTH19A", 4.9},
	{"23637153", "Vo Tuan An", "y", "13/01/2005", "DHTH19F", 9.8},
	{"23637154", "Tran Tuan Nguyen", "y", "14/01/2005", "DHTH19A", 9.9},
	{"23637155", "Nguyen Thi Ha My", "x", "15/01/2005", "DHTT19A", 9.9},
	{"23637156", "Tran Mang Quan", "y", "16/01/2005", "DHTH19A", 8.7}};
int main()
{
	SINHVIEN m[50];
	int n;
	printf("So luong sinh vien (toi da 100):");
	scanf("%d", &n); // dieu kien: n>=0 va n<=100

	// Nhap danh sach sinh vien
	// for (int i = 0; i < n; i++)
	// 	nhap1SinhVien(m[i]);
	// HAM nhap DSSV (nhap mang)
	for (int i = 0; i < n; i++)
		m[i] = samples[i];
	// Xuat danh sach sinh vien
	xuatDsSinhVien(m, n);

	// Liet ke sinh vien co diem trung binh > 5
	printf("\nSinh vien co diem trung binh > 5\n");
	int c_tb = 0;
	for (int i = 0; i < n; ++i)
		if (m[i].dtb > 5.0) //???DHTH19E
		{
			xuat1SinhVien(m[i]);
			c_tb++;
		}
	if (c_tb == 0)
		printf("\nKhong co sinh vien co diem trung binh duoi 5\n");

	// liet ke sinh vien nganh CNTT
	printf("\nSinh vien CNTT\n");
	for (int i = 0; i < n; ++i)
		if (m[i].lop[2] == 'T' && m[i].lop[3] == 'H') //???DHTH19E
			xuat1SinhVien(m[i]);

	// So luong sinh vien nu
	int count_nu = 0;
	for (int i = 0; i < n; ++i)
		if (m[i].gioitinh[0] == 'x') //???DHTH19E
			count_nu += 1;
	printf("\nSinh vien nu co %d ban.\n", count_nu);

	// Sinh vien co diem trung binh cao nhat
	float top_diem = 0.0;
	for (int i = 0; i < n; ++i)
		if (m[i].dtb > top_diem) //???DHTH19E
			top_diem = m[i].dtb;
	printf("\nCac sinh vien co diem trung binh cao nhat la\n");
	for (int i = 0; i < n; ++i)
		if (m[i].dtb == top_diem) //???DHTH19E
			xuat1SinhVien(m[i]);

	// Them sinh vien vao cuoi danh sach
	SINHVIEN svmoi;
	nhap1SinhVien(svmoi);
	them1SvVaoCuoi(m, svmoi, &n);

	// Xuat danh sach sinh vien
	for (int i = 0; i < n; i++)
		xuat1SinhVien(m[i]);
	printf("\n So luong sv sau khi them %d", n);

	// Tim SV & xoa
	char mssv_tim[9];
	fflush(stdin);
	printf("\nNhap ma sinh vien can tim: ");
	gets(mssv_tim);

	int kq_tim = timsv(m, n, mssv_tim);
	if (kq_tim != -1)
	{
		printf("\n\tSinh vien co mssv %s o vtri so %d", mssv_tim, kq_tim);
		xoasv(m, n, kq_tim);
		printf("\n\tDanh sach sv sau khi xoa\n");
		xuatDsSinhVien(m, n);
	}
	else
		printf("\n\tKhong tim thay sinh vien co mssv la %s", mssv_tim);

	// Sap xep sv
	sapXepSv(m, n);
	printf("\n\tDanh sach sv sau khi sap xep tang theo diem trung binh\n");
	xuatDsSinhVien(m, n);
}
