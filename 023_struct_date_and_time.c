#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
};

struct time
{
    int hour;
    int minute;
    int second;
};

struct dateAndTime
{
    struct date sdate;
    struct time stime;
};

void getDate()
{
    struct dateAndTime DandT;

    printf("Enter a date in the format dd/mm/yyyy: \n");

    printf("dd: ");
    scanf("%i", &DandT.sdate.day);
    printf("\n");

    printf("mm: ");
    scanf("%i", &DandT.sdate.month);
    printf("\n");

    printf("yyyy: ");
    scanf("%i", &DandT.sdate.year);
    printf("\n");

    printf("The date entered is: ");

    if ((DandT.sdate.day>=0) && (DandT.sdate.day<10))
    {
        printf("0%i", DandT.sdate.day);
    }
    else
    {
        printf("%i", DandT.sdate.day);
    }

    if ((DandT.sdate.month>=0) && (DandT.sdate.month<10))
    {
        printf("/0%i/", DandT.sdate.month);
    }
    else
    {
        printf("/%i/", DandT.sdate.month);
    }

    if ((DandT.sdate.year>=0) && (DandT.sdate.year<10))
    {
        printf("000%i \n", DandT.sdate.year);
    }
    else if ((DandT.sdate.year>=10) && (DandT.sdate.year<100))
    {
        printf("00%i \n", DandT.sdate.year);
    }
    else if ((DandT.sdate.year>=100) && (DandT.sdate.year<1000))
    {
        printf("0%i \n", DandT.sdate.year);
    }
    else
    {
        printf("%i \n", DandT.sdate.year);
    }
}

void getTime()
{
    struct dateAndTime DandT;

    printf("Enter a time in the format hh/mm/ss: \n");

    printf("hh: ");
    scanf("%i", &DandT.stime.hour);
    printf("\n");

    printf("mm: ");
    scanf("%i", &DandT.stime.minute);
    printf("\n");

    printf("ss: ");
    scanf("%i", &DandT.stime.second);
    printf("\n");

    printf("The time entered is: ");

    if ((DandT.stime.hour>=0) && (DandT.stime.hour<10))
    {
        printf("0%i", DandT.stime.hour);
    }
    else
    {
        printf("%i", DandT.stime.hour);
    }

    if ((DandT.stime.minute>=0) && (DandT.stime.minute<10))
    {
        printf(":0%i/=:", DandT.stime.minute);
    }
    else
    {
        printf(":%i:", DandT.stime.minute);
    }

    if ((DandT.stime.second>=0) && (DandT.stime.second<10))
    {
        printf("0%i \n", DandT.stime.second);
    }
    else
    {
        printf("%i \n", DandT.stime.second);
    }
}

void getDateAndTime()
{
    getDate();
    printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");
    getTime();
}

int main()
{
    int option;

    printf("What do you want to enter? \n");
    printf("1> Date \n2> Time \n3> Both Date and Time \nEnter your choice: ");

    for(;;)
    {
        scanf("%i", &option);

        if (option==1)
        {
            printf(" \n");
            getDate();
            break;
        }
        else if (option==2)
        {
            printf(" \n");
            getTime();
            break;
        }
        else if (option==3)
        {
            printf(" \n");
            getDateAndTime();
            break;
        }
        else
        {
            printf("Invalid choice. Choose again: ");
            continue;
        }
    }
}
