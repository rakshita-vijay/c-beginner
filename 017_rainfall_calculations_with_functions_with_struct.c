// with functions, without struct

#include <stdio.h>
#include <string.h>

float totalRainfallPerYearAndAverageRainfallPerMonthIn1Year(int years[5], char months[], float arr[5][12]);
float averageRainfallPerMonthIn1Year(float totalPerYear);
float printTRPYAARPMI1Y(int years, float totalPerYear, float averagePerMonth);
float printAverageRainfallPerYear(int years[5], float sumForAveragePerMonth);
float averageRainfallPerMonthAcross5Years(char months[], float averagePerMonthAcross5YearsArr[], float arr[5][12]);

float totalRainfallPerYearAndAverageRainfallPerMonthIn1Year(int years[5], char months[], float arr[5][12])
{
    int outerCount;
    int innerCount;
    float sumForTotalPerYear = 0.0;
    float totalPerYear[5];
    float averagePerMonth[5];
    float sumForAveragePerMonth = 0.0;
    float sumForAveragePerMonthAcross5Years = 0.0;
    float averagePerMonthAcross5YearsArr[12];

    printf("year   totalPerYear   averagePerMonthIn1Year \n");

    for (outerCount = 0; outerCount < 5; outerCount++)
    {
        for (innerCount = 0; innerCount < 12; innerCount++)
        {
            sumForTotalPerYear += arr[outerCount][innerCount];
            sumForAveragePerMonthAcross5Years += arr[innerCount][outerCount];
        }
        totalPerYear[outerCount] = sumForTotalPerYear;
        averagePerMonth[outerCount] = averageRainfallPerMonthIn1Year(totalPerYear[outerCount]);

        printTRPYAARPMI1Y(years[outerCount], totalPerYear[outerCount], averagePerMonth[outerCount]);

        sumForAveragePerMonth += (averagePerMonth[outerCount])/5;
        averagePerMonthAcross5YearsArr[outerCount] = sumForAveragePerMonthAcross5Years/5;
        sumForTotalPerYear = 0.0;
    }
    printAverageRainfallPerYear(years, sumForAveragePerMonth);
    averageRainfallPerMonthAcross5Years(months, averagePerMonthAcross5YearsArr, arr);
}

float averageRainfallPerMonthIn1Year(float totalPerYear)
{
    return totalPerYear/12;
}

float printTRPYAARPMI1Y(int years, float totalPerYear, float averagePerMonth)
{
    printf("%i     ", years);
    (totalPerYear<100) ? printf("0%.4f           ", totalPerYear) : printf("%.4f           ", totalPerYear);
    (averagePerMonth<10) ? printf("0%.4f \n", averagePerMonth) : printf("%.4f \n", averagePerMonth);
}

float printAverageRainfallPerYear(int years[5], float sumForAveragePerMonth)
{
    printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

    printf("   year      averagePerYear \n");
    printf("%i-%i       %.4f \n", years[0], years[4], sumForAveragePerMonth);
}

float averageRainfallPerMonthAcross5Years(char months[], float averagePerMonthAcross5YearsArr[], float arr[5][12])
{
    int outerCount;
    float sum;
    int innerCount;

    printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

    printf("averagePerMonthAcross5Years \n");

    for(int i = 0; i<48; i+=4)
    {
        printf(" %c%c%c   ", months[i], months[i+1], months[i+2]);
    }

    // printf("Jan   Feb   Mar   Apr   May   Jun   Jul   Aug    Sep    Oct    Nov    Dec");
    printf("\n");

    for (outerCount = 0; outerCount < 12; outerCount++)
    {
        sum = 0.0;
        for (innerCount = 0; innerCount < 5; innerCount++)
        {
            sum += arr[innerCount][outerCount];
        }
        averagePerMonthAcross5YearsArr[outerCount] = sum/5;
        (averagePerMonthAcross5YearsArr[outerCount]<10) ? printf("0%.2f  ", averagePerMonthAcross5YearsArr[outerCount]) : printf("%.2f  ", averagePerMonthAcross5YearsArr[outerCount]);
    }

    printf("\n");
}

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

    totalRainfallPerYearAndAverageRainfallPerMonthIn1Year(years, months, arr);

    printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");
}
