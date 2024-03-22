#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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

int main()
{
	//cap phat dong: HEAP
	SINHVIEN *p; //tencontro->thuoctinh
	p = (SINHVIEN*)malloc(sizeof(SINHVIEN)); //cap phat bo nho trong vung HEAP
	
	printf("\nNhap thong tin sinh vien:\n");
	printf("Ma so sinh vien:"); scanf("%s", &p->mssv);
	fflush(stdin); // xoa bo nho dem/cache
	printf("Ho ten:"); gets(p->hoten);
	printf("Ngay sinh:"); gets(p->ngaysinh);
	printf("Lop:"); gets(p->lop);
	printf("Diem trung binh:"); scanf("%f", &p->dtb);

	//xuat thong tin cua sinh vien ra man hinh
	printf("%s\t%s\t%s\t%s\t%.1f\n", p->mssv, p->hoten, p->ngaysinh, p->lop, p->dtb);
	
	free(p);
	
}