#include <stdio.h>
#include <ctype.h>
#include <string.h>

void UpperWords(char *s)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            *(s) = toupper(*(s));
        if (*(s + i) == ' ' && *(s + i + 1) != ' ')
            *(s + i + 1) = toupper(*(s + i + 1));
        else if 
    }
}
int main()
{
    // int n;
    // do
    // {
    //     printf("Nhap n: ");
    //     scanf("%d", &n);
    // } while (n <= 0 || n > 10000);

    // int *a = (int *)malloc(n * sizeof(int));

    // printf("nhap ho va ten: ");
    // scanf("%s", a);
    char S[] = "dao duy long";
    UpperWords(S);
    printf("%s", S);
    return 0;
}