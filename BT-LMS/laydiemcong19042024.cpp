#include <stdio.h>
struct Date
{
    int month;
    int day;
    int year;
};

struct Date ScanDate()
{
    struct Date a;
    scanf("%d", &a.month);
    scanf("%d", &a.day);
    scanf("%d", &a.year);
    printf("Enter a date (mm dd yyyy):");
    return a;
}

void DisplayDate(struct Date a)
{
    printf("Date is: %d\\t%d\\t%d", a.month, a.day, a.year);
}

struct Month
{
    char month[20];
};

struct Month months[12] = {

    {"January"}, {"February"}, {"March"}, {"April"}, {"May"}, {"June"}, {"July"}, {"August"}, {"September"}, {"October"}, {"November"}, {"December"}};

void DisplayMonthName(struct Date a)
{

    printf("Date is: %s,\\t%d\\t%d", months[a.month - 1].month, a.day, a.year);
}

void Tomorrow(struct Date a)
{
    int tomorrow = 0;
    int month = a.month;
    int year_second = a.year % 10;
    int year_first = (a.year / 10) % 10;
    switch (a.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (a.day == 31)
        {
            tomorrow = 1;
            if (a.month == 12)
            {
                month = 1;
                year_second += 1;
            }
            else
                month = a.month + 1;
        }
        else
            tomorrow = a.day + 1;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (a.day == 30)
        {
            tomorrow = 1;
            month = a.month + 1;
        }
        else
            tomorrow = a.day + 1;
        break;
    case 2:
        if (a.day == 28)
        {
            tomorrow = 1;
            month = a.month + 1;
        }
        else
            tomorrow = a.day + 1;
        break;
    }
    printf("Tomorrow's date is %d/%d/%d%d.", month, tomorrow, year_first, year_second);
}

int numberOfDays(struct Date d)
{
    int day = 1;
    switch (d.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        day = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        day = 30;
        break;
    case 2:
        if ((d.year % 400 == 0) || (d.year % 4 == 0 && d.year % 100 != 0))
        {
            day = 29;
        }
        else
        {
            day = 28;
        }
        break;
    }

    return day;
}
int main()
{
    // struct Date today = ScanDate();
    // printf("%d\\%d\\%d", today.month, today.day, today.year);

    // Bai 4
    // struct Date today = {3, 1, 2014};
    // Tomorrow(today);

    // Bai 4
    struct Date d = {1, 1, 2004};
    int days = numberOfDays(d);
    printf("%d", days);
    return 0;
}