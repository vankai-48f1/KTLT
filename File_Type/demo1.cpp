/* copy-con.c*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define filepath "/Users/kaivan/Workspace/C:C++/KTLT/BTTH/File_Type/sample1.txt"
// #define filepath "sample1.txt"

// Check exit fiel
int exist(char *filename)
{
    int exited = FALSE;
    FILE *f = fopen(filepath, "r");
    if (f != NULL)
    {
        exited = TRUE;
        fclose(f);
    }
    return exited;
}

// Write a file from character inputted until Ctrl +Z pressed
int writeFile(char *filename)
{
    char c;
    int CTR_Z = 27;
    if (exist(filepath) == TRUE)
    {
        printf("The file %s existed. Override it Y/N? :", filename);
        if (toupper(getchar() == 'N'))
            return FALSE;
    }

    // Mo file va ghi gia tri vao file
    FILE *f;
    f = fopen(filepath, "w");
    fflush(stdin); // xoa bo nho dem
    // nhap gia tri vao phai trong khi chua nhan ctr+z
    do
    {
        c = getchar(); // lay gia tri use nhap
        if (c != CTR_Z) // neu gia tri do khong phai la ESC
            fputc(c, f); // them gia tri vao file
    } while (c != CTR_Z);
    fclose(f); // xoa cac du lieu trong bo dem dv file, dong file va giai phong bo nho dc sd vs file
    return TRUE;
}

// export content
int printFile(char *filename)
{
    char c;
    // kiem tra su ton tai cua file
    if (exist(filename) == FALSE)
    {
        printf("The file %s does not exist.\n", filename);
        return FALSE;
    }
    // mo file va doc file
    FILE *f = fopen(filepath, "r");
    while ((c = fgetc(f)) != EOF)
        putchar(c);
    fclose(f);
    return TRUE;
}
int main()
{
    writeFile(filepath);
    printFile(filepath);

    return 0;
}
