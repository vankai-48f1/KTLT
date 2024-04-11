#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
#define FileName "students.txt"

typedef struct SinhVien
{
    char name[31];
    char address[50];
    float score;
};

void input1SV(SinhVien *a)
{
    printf("Nhap ten sinh vien: ");
    gets(a->name);

    printf("Nhap dia chi sinh vien: ");
    gets(a->address);

    fflush(stdin);
    printf("Nhap diem cua sinh vien: ");
    scanf("%f", &a->score); // nhap gia tri cho dia chi cua score
}

void output1SV(SinhVien *a)
{
    printf("%s\t%s\t%.2f", a->name, a->address, a->score);
}
int exist(char *fname)
{
    FILE *f = fopen(fname, "r"); // mo va doc file
    int existed = FALSE;
    if (f != NULL) // neu file khac NULL co nghia la file ton tai
    {
        existed = TRUE;
        fclose(f);
    }
    return existed;
}
int readFile(char *fname, SinhVien *sv, int *num_sv)
{
    if (exist(fname) == FALSE)
    {
        printf("File %s khong ton tai, vui long tao file", fname);
        return FALSE;
    }
    FILE *f = fopen(fname, "r");
    char c;
    /**
    Cụ thể, hàm fscanf có thể được sử dụng để đọc dữ liệu từ một tệp văn bản theo một định dạng cụ thể. Trong trường hợp này,
    định dạng của dữ liệu trong tệp được mô tả bằng chuỗi "%[^:]:[^;];%f".
        "%[^:]" là một định dạng đọc chuỗi ký tự, trong đó "^:" chỉ ra rằng nó sẽ đọc tất cả các ký tự cho đến khi gặp ký tự ":".
        ":" sau đó đại diện cho ký tự ngăn cách giữa hai trường dữ liệu.
        "%[^;]" là một định dạng đọc chuỗi ký tự khác, trong đó "^;" chỉ ra rằng nó sẽ đọc tất cả các ký tự cho đến khi gặp ký tự ";".
        ";" sau đó đại diện cho ký tự ngăn cách giữa trường thứ hai và trường thứ ba.
        "%f" là định dạng để đọc một số thực.
    */
    while (fscanf(f, "%[^:]:%[^;];%f", (sv + *num_sv)->name, (sv + *num_sv)->address, &(sv + *num_sv)->score) != EOF && *num_sv < MAX)
    {
        *num_sv += 1;
    }

    fclose(f);
    return TRUE;
}

int countSvGoodCore(SinhVien *sv, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((sv + i)->score >= 8.0)
            count += 1;
    }
    return count;
}

void printSvGoVap(SinhVien *sv, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (strstr((sv + i)->address, "Go Vap"))
        {
            output1SV((sv + i));
            printf("\n");
            count += 1;
        }
    }

    if (count == 0)
        printf("Khong co sinh vien co dia chi quan 'Go Vap'.\n");
}

int main()
{
    SinhVien *psv = (SinhVien *)malloc(MAX * sizeof(SinhVien));
    if (psv == NULL)
    {
        printf("Khong du bo nho.");
        return 1;
    }
    // // Nhap sv
    // input1SV(psv);
    // // Xuat sv
    // printf("Thong Tin Sinh Vien Name|Adress|Score:\n");
    // output1SV(psv);

    // Doc thong tin file
    int num_sv = 0;
    readFile(FileName, psv, &num_sv);

    // Xuat sv
    printf("Thong Tin Sinh Vien Name|Adress|Score:\n");
    for (int i = 0; i < num_sv; i++)
    {
        output1SV(psv + i);
    }

    // Dem so luong sv co diem >= 8
    int count = countSvGoodCore(psv, num_sv);

    if (count == 0)
        printf("Khong co sinh vien co diem >= 8.\n");
    else
        printf("Co %d co sinh vien co diem >= 8.\n", count);

    // Liet ke sv o quan Go Vap
    printSvGoVap(psv, num_sv);
    // Giải phóng bộ nhớ
    free(psv);
    return 0;
}