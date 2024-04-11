#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void SortName(char s[], int n, int start)
{
    for (int j = start; j < n; j++)
    {
        char swap = s[j];
        s[j] = s[j + 1];
        s[j + 1] = swap;
    }
}
// void RemSpaces(char s[])
// {
//     int len = strlen(s);

//     for (int i = 0; i < len; i++)
//     {
//         if (s[0] == ' ')
//         {
//             printf("co khoang trang vi tri thu %d\n", i);
//             SortName(s, len, 0);
//             len -= 1;
//         }
//         if ((s[i] == ' ' && s[i + 1] == ' '))
//         {
//             printf("co khoang trang vi tri thu %d\n", i);
//             SortName(s, len, i + 1);
//             len -= 1;
//             // i--;
//         }
//     }
// }
void RemSpaces(char s[])
{
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (s[0] == ' ')
        {
            for (int j = 0; j < len; j++)
            {
                char swap = s[j];
                s[j] = s[j + 1];
                s[j + 1] = swap;
            }
            len -= 1;
            i--;
        }
        if ((s[i] == ' ' && s[i + 1] == ' '))
        {
            for (int j = i + 1; j < len; j++)
            {
                char swap = s[j];
                s[j] = s[j + 1];
                s[j + 1] = swap;
            }
            len -= 1;
            i--;
        }
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
    char S[] = "  Do Quang  Minh";
    RemSpaces(S);
    printf("%s\n", S);
    return 0;
}