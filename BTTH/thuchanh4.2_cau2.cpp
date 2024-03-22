#include<stdio.h>

double deQuyDanSo(double ds, int nam) {
	if (nam == 2029) 
		return ds;
	ds = ds + (ds * 0.025);
	return deQuyDanSo(ds, nam + 1 );
}
int main(){
	double danso = 8000000000;	
	double result = deQuyDanSo(danso, 2019);
	printf("Dan so nam 2028 la %.0lf\n", result);
	return 0;
}
