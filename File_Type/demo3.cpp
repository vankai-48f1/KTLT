#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
// ham kiem tra file co ton tai hay khong
int exist(char *filename){
    int existed= 0;
    FILE* f=fopen(filename,"r");
    if(f!=NULL){
        existed=1;
        fclose(f);
    }
    return existed;
}
// ham nhap gia tri vao file
int writeFile(char *filename){
    if(exist(filename)==1){
        printf("File %s da ton tai, Ghi de no Y/N:",filename);
        if(toupper(getchar())=='N') return 0;
    }
    char line[201];
    int length=0;
    FILE* f=fopen(filename,"w");// mo file va ghi gia tri vao file.
    fflush(stdin);
    
    // nhap gia tri vao file cho toi khi dong line do chi nhan enter
    do{
        gets(line);// lay mot line - neu user chi nhan enter thi -> length=0
        length= strlen(line);
        if(length>0){
            // Neu do dai > 0 cos nghia la co gia tri va khong phai enter thi nhap gia tri vao file
            fprintf(f,"%s\n",line);
        }
    }while(length>0);
    fclose(f);
    return 1;
}
// Xuat gia tri co trong file
int printFile(char *filename){
    char c[201];
    if(exist (filename)==0){
        printf("file khong ton tai\n");
        return 0;
    }
    FILE* f=fopen(filename,"r");
    while((fscanf(f,"%[^\n]%*c",c)>0)) puts(c);
    fclose(f);
    return 1;
}
int main(){
    char filename[81];
    printf("chuong trinh doc va viet vao file:\n");
    printf("ten file:");
    gets(filename);
    printf("viet vao file:\n");
    if(writeFile(filename)==1){
        printf("data trong file %s:\n", filename);
        if(printFile(filename)==0)printf("file loi!\n");
    }
    else printf("in file that bai!,\n",filename);
    getchar();
    return 0;
}

