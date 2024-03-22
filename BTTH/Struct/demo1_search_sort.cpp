#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct SINHVIEN
{//khai bao cac thuoc tinh/truong cua doi tuong sinh vien
	char mssv[9];
	char hoten[30]; //string: la mang 1 chieu kieu char
	char ngaysinh[11]; //29/02/2005
	char lop[10];//DHTH19A; DHAV18ATT
	float dtb;
};

SINHVIEN samples[]={
{"23637151", "Nguyen Tuan Anh", "11/05/2005", "DHTH18BTT", 9.7},
{"23637152", "Tran Tuan My", "10/01/2005", "DHTH18ATT", 6.9},
{"23637153", "Vo Tuan An", "10/01/2005", "DHTH18ATT", 9.8},
{"23637154", "Tran Tuan Nguyen", "10/01/2005", "DHTH18ATT", 9.9},
{"23637155", "Tran Mang Quan", "10/01/2005", "DHTH18ATT", 8.7}
};
//==HAM nhap thong tin cua 1 SINH VIEN
void nhap1SinhVien(SINHVIEN &a)
{
	printf("\nTHONG TIN CUA SINH VIEN\n");
	printf("Ma sinh vien:"); scanf("%s", &a.mssv) ;
	fflush(stdin); //xoa bo nho dem/cache
	printf("Ho ten:"); gets(a.hoten);
	printf("Ngay sinh:"); gets(a.ngaysinh);
	printf("Lop:"); gets(a.lop);
	printf("Diem trung binh:"); scanf("%f", &a.dtb);
}
//==HAM xuat thong tin cua 1 SINH VIEN ra man hinh
void xuat1SinhVien(SINHVIEN a)
{
		printf("%s\t%s\t%s\t%s\t%.1f\n",a.mssv, a.hoten, a.ngaysinh, a.lop, a.dtb);
}
void xuatDSSV(SINHVIEN a[], int n)
{
	for(int i = 0; i<n; i++)
		xuat1SinhVien(a[i]);
}
//====Them 1 sinh vien vao cuoi danh sach
void themCuoi(SINHVIEN x, SINHVIEN a[], int &n)
{
	a[n] = x;
	n++;
}
//tim kiem theo mssv: ham tra ve vi tri tim thay, return -1 neu khong tim thay
int timKiem(char matim[], SINHVIEN a[], int n)//????
{
	for(int i = 0; i<n; i++)
		if(stricmp(matim, a[i].mssv)==0)
			return i;
	return -1; //khong tim thay		
}

//Xoa phan tu tai vi tri 
void xoaVitri(int vt, SINHVIEN a[], int &n)
{
	for(int i = vt; i<n-1; i++)
		a[i] = a[i+1];
	n--;
}
//xoa sinh vien khi biet mssv
void xoaMSSV(char x[], SINHVIEN a[], int &n)
{
	int vt = timKiem(x, a, n);
	if(vt!=-1)
	{
		for(int i = vt; i<n-1; i++)
			a[i] = a[i+1];
		n--;
	}
}

void swap(SINHVIEN &x, SINHVIEN &y)
{
	SINHVIEN t;
	t = x;
	x = y;
	y = t;
}
void sapXepTang(SINHVIEN a[], int n)
{
	for(int i = 0; i<n-1; i++) // 1 3 2 5 4
		for(int j = i+1;j<n; j++)
			if(a[j].dtb < a[i].dtb)
				swap(a[j], a[i]);
}
int main()
{
	SINHVIEN a[50]; //tenbien.thuoctinh
	int n;
	printf("So luong sinh vien (toi da 50):"); 
	scanf("%d", &n); //dieu kien: n>=0 va n<=50
	//HAM nhap DSSV (nhap mang)
	for(int i = 0; i<n; i++)
//		nhap1SinhVien(a[i]);
		a[i] = samples[i];
	//HAM: Xuat DSSV ra man hinh(xuat mang)
	xuatDSSV(a, n);
	
//	char matim[9];
//	printf("Nhap mssv muon tim:"); 
//	scanf("%s", &matim);
//	xoaMSSV(matim, a, n);
//	printf("\nSau khi xoa sinh vien:%s\n", matim);
//	xuatDSSV(a, n);
	
	sapXepTang(a, n);
	printf("\nDanh sach sau khi sap xep theo DTB:\n");
	xuatDSSV(a, n);
}




