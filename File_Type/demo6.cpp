#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
int main(){
	char fname[] = "test_rewind.txt"; /*Bien fname chua ten file can doc*/
	char c; /*a character from file */
	int i;
	FILE *f = fopen(fname, "r"); /*Khai bao va mo file test_rewind o che do doc*/
	printf("10 first characters:\n");
	for(int i=0; i<10; i++) putchar(fgetc(f)); /*In ra 10 ki tu dau tien cua file*/
	rewind(f); /*Dua con tro tep ve dau file*/
	printf("\n\nAfter rewind:\n");               	
	while((c=fgetc(f))!=EOF) putchar(c);   	/*In ra noi dung khi dat lai con tro tep*/
	fclose(f);          	/*Dong tep*/
	getchar();
	return 0;
}              

