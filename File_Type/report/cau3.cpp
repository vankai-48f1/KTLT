#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define TRUE 1
#define FALSE 0
#define FilePath "NguyenAm.txt"

int exist(char *fname)
{
    FILE *f = fopen(fname, "r");
    if (f != NULL)
    {
        fclose(f);
        return TRUE;
    }
    return FALSE;
}

int isVowel(char ch)
{
    ch = toupper(ch);
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

int writeFile(char *fname, char a[])
{
    // Check file
    if (exist(fname) == NULL)
    {
        printf("\nKhong tao duoc file.");
        return FALSE;
    }

    FILE *f = fopen(fname, "w");

    int l = strlen(a);
    for (int i = 0; i < l; i++)
    {
        if (isVowel(a[i]))
            fprintf(f, "%c", a[i]);
    }

    fclose(f);
    return TRUE;
}
int readFile(char *fname)
{
    // Check file
    if (exist(fname) == FALSE)
    {
        printf("The file %s does not exist.\n", fname);
        return FALSE;
    }
    FILE *f = fopen(fname, "r");

    char c;
    while ((c = fgetc(f)) != EOF)
        printf("%c", c);
    printf("\n");
    return TRUE;
}
int main()
{
    char a[MAX];
    printf("Nhập chuỗi (tối đa 100 ký tự): ");
    gets(a);
    fflush(stdin);

    // Luu cac ky tu nguyen am vao file
    writeFile(FilePath, a);

    // Xuat File
    printf("Xuat noi dung file: ");
    readFile(FilePath);

    return 0;
}