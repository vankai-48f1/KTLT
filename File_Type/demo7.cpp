#include <stdio.h>

int main()
{
    char fname[] = "test_fseek.txt";
    char c; // 1 ki tu trong file
    int i;
    FILE *f = fopen(fname, "r"); // mo va doc file
    printf("15 ki tu dau:\n");
    for (i = 0; i < 15; i++)
        putchar(fgetc(f));
    puts("\n");

    fseek(f, -5, SEEK_CUR); // tu vi tri hien tai
    for (i = 0; i < 5; i++)
        putchar(fgetc(f));
    puts("\n");

    fseek(f, -10, SEEK_END); // tu vi tri ket thuc
    for (i = 0; i < 5; i++)
        putchar(fgetc(f));
    puts("\n");

    fseek(f, 10, SEEK_SET); // tu vi tri bat dau
    for (i = 0; i < 5; i++)
        putchar(fgetc(f));

    fclose(f);
    getchar();
    return 0;
}
