#include <stdio.h>
#include <string.h>
typedef struct DATE{
	int ngay,thang,nam;
};
typedef struct QUANLI{
	char mathuebao[20];
	char hoten[20];
 	DATE ngaydangki;
	char sdt[20];
	char loai[3];
	int noimang;
	int ngoaimang;
};
QUANLI sample[]={
	{"1","nguyen van A",1,2,2005,"0123456","tt",10,20},
	{"2","nguyen van A",1,5,2026,"5678921","ts",15,30},
	{"1","nguyen van B",4,5,1990,"0111245","tt",10,20},
	{"5","nguyen van C",6,7,2000,"0153532","tt",11,20},
	{"7","nguyen van D",6,6,2001,"0141242","ts",12,25},
};
void nhap(QUANLI &a)
{
	printf("Ma thue bao: ");scanf("%s",&a.mathuebao); fflush(stdin) ;
	printf("Ho ten chu thue bao: "); gets(a.hoten); fflush(stdin);
	printf("ngay dang ki: "); scanf("%s",&a.ngaydangki.ngay,&a.ngaydangki.thang,&a.ngaydangki.nam); 
	printf("so dien thoai: "); scanf("%s",&a.sdt);
	printf("Loai thue bao: "); scanf("%s",&a.loai);
	printf("Thoi gian noi mang: "); scanf("%d",&a.noimang);
	printf("Thoi gian ngoai mang: "); scanf("%d",&a.ngoaimang);
}
void xuat(QUANLI a)
{
	printf("%s\t%-8s\t%d/%d/%d\t%-8s\t%-8s\t%d\t%d\n",a.mathuebao,a.hoten,a.ngaydangki.ngay,a.ngaydangki.thang,a.ngaydangki.nam,a.sdt,a.loai,a.noimang,a.ngoaimang);
}
void xuatDS(QUANLI a[],int &n)
{
	for (int i=0;i<n;i++)
	xuat(a[i]);
}
void them(QUANLI a[],int &n)
{
	nhap(a[n]);
	n++;
}
void tim(QUANLI a[],int &n)
{
	char x[20];
	printf("Nhap ten can tim: ");
	fflush(stdin);
	gets(x);
	printf("Thue bao can tim la\n ");
	for (int i=0;i<n;i++){
		if (strcmp(a[i].hoten,x) ==0){
			xuat(a[i]);
		}
	}

}
void sapxep(QUANLI a[],int n)
{
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if (strcmp(a[j].mathuebao,a[j-1].mathuebao)<0){
				QUANLI temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
	xuatDS(a,n);
}
void loai(QUANLI a[],int &n)
{
	char m[3];
	printf("Nhap thue bao can tim ");
	scanf("%s",&m);
	for (int i=0;i<n;i++){
		if (strcmp(a[i].loai,m)==0){
			xuat(a[i]);
		}
	}
}
void xuattb(QUANLI a[],int &n)
{
	printf("Thue bao sau 2020\n");
	for (int i=0;i<n;i++){
		if (a[i].ngaydangki.nam > 2020){
			xuat(a[i]);
		}
	}
}
int cuocphi(QUANLI a)
{
	return a.noimang*1500 + a.ngoaimang*3000;
}
void dem(QUANLI a[],int &n)
{
	int dem=0;
	for (int i=0;i<n;i++){
		if (strcmp(a[i].loai, "tt")==0){
			dem++;
		}
	}
	printf("So luong thue bao tra truoc la %d\n",dem);
}
int main(int argc, char *argv[])
{
	QUANLI a[10000];
	int n;
	printf("Nhap so luong thue bao: ");
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		a[i]=sample[i];
	}
	
	xuatDS(a,n);
	
	printf("Nhap thue bao can them\n ");
	them(a,n);
	printf("Danh sach sau khi them\n");
	xuatDS(a,n);

	printf("Danh sach sao khi sap xep\n");
	sapxep(a,n);

 	tim(a,n);

	loai(a,n);

	xuattb(a,n);

	printf("Cuoc phi cac thue bao\n ");
	for (int i=0;i<n;i++){
		printf("%s= %d\n",a[i].mathuebao,cuocphi(a[i]));
	}

	dem(a,n);
	return 0;
}
