#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// ham doc file
int readFromFile(char *filename, int *a, int *pn) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    fscanf(f, "%d", pn);
    for (int i = 0; i < *pn; i++) {
        fscanf(f, "%d", &a[i]);
    }
    fclose(f);
    return 1;
}

// ham sap xep
void sortArray(int *a, int n) {
    int i, j, t;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (a[i] > a[j]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

// ham in ra mang hinh den
void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// ham nhap data vao mang
int writeToFile(char *filename, int *a, int n) {
    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    fprintf(f, "%d ", n);
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d ", a[i]);
    }
    fclose(f);
    return 1;
}

int main() {
    char inn[30] = "array1.txt";
    char out[30] = "array2.txt";
    int a[200];
    int n = 0;

    if (!readFromFile(inn, a, &n)) {
        return 1; // loi doc file
    }

    sortArray(a, n);
    printf("Sorted array: ");
    printArray(a, n);

    if (!writeToFile(out, a, n)) {
        return 1; // loi khi nhap file
    }

    return 0;
}

