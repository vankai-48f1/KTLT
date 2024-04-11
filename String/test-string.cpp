#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

int main()
{
    char name[31] = "Hello everyone";
    char *s;
    s = (char *)malloc(31);

    printf("%s\n", name);

    return 0;
}