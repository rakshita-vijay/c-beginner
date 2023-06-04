// without functions, without struct

#include <stdio.h>

int main()
{
    // 5 rows, 12 columns
    // total rainfall per year, average rainfall per year, average rainfall per month

    int years[5] = {2000, 2001, 2002, 2003, 2004};

    char months[] = {"Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec"};

    float arr[5][12] = {
        {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.10, 10.11, 11.12, 12.13},
        {2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.10, 10.11, 11.12, 12.13, 13.14},
        {3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.10, 10.11, 11.12, 12.13, 13.14, 14.15},
        {4.5, 5.6, 6.7, 7.8, 8.9, 9.10, 10.11, 11.12, 12.13, 13.14, 14.15, 15.16},
        {5.6, 6.7, 7.8, 8.9, 9.10, 10.11, 11.12, 12.13, 13.14, 14.15, 15.16, 16.17}
    };

    int outerCount;
    int innerCount;
    float sum = 0.0;
    float totalPerYear[5];
    float averagePerYear;
    float averagePerMonthIn1Year[5];
    float averagePerMonthAcross5Years[12];

    // for total rainfall per year

    printf("year   totalPerYear \n");

    for (outerCount = 0; outerCount < 5; outerCount++)
    {
        for (innerCount = 0; innerCount < 12; innerCount++)
        {
            sum += arr[outerCount][innerCount];
        }
        totalPerYear[outerCount] = sum;
        printf("%i    ", years[outerCount]);
        (totalPerYear[outerCount]<100) ? printf("0%.4f           \n", totalPerYear[outerCount]) : printf("%.4f           \n", totalPerYear[outerCount]);
        sum = 0.0;
    }

    printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

    // for average rainfall per month in 1 year

    printf("year   averagePerMonthIn1Year \n");

    for (outerCount = 0; outerCount < 5; outerCount++)
    {
        averagePerMonthIn1Year[outerCount] = (totalPerYear[outerCount])/12;
        printf("%i    ", years[outerCount]);
        (averagePerMonthIn1Year[outerCount]<10) ? printf("0%.4f \n", averagePerMonthIn1Year[outerCount]) : printf("%.4f \n", averagePerMonthIn1Year[outerCount]);
        sum += averagePerMonthIn1Year[outerCount];
    }

    printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

    // for average rainfall per year

    printf("   year      averagePerYear \n");
    averagePerYear = sum/5;
    printf("%i-%i       %f \n", years[0], years[4], averagePerYear);

    printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

    // for average rainfall per month across 5 years

    printf("averagePerMonthAcross5Years \n");

    for(int i = 0; i<48; i+=4)
    {
        printf("%c%c%c    ", months[i], months[i+1], months[i+2]);
    }

    printf("\n");

    for (outerCount = 0; outerCount < 12; outerCount++)
    {
        sum = 0.0;
        for (innerCount = 0; innerCount < 5; innerCount++)
        {
            sum += arr[innerCount][outerCount];
        }
        averagePerMonthAcross5Years[outerCount] = sum/5;
        (averagePerMonthAcross5Years[outerCount]<10) ? printf("0%.2f  ", averagePerMonthAcross5Years[outerCount]) : printf("%.2f  ", averagePerMonthAcross5Years[outerCount]);
    }
}
