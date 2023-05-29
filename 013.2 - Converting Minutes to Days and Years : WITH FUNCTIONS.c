// with functions

#include <stdio.h>

float Days(float mins)
{
    return (mins/(60.0*24.0));
}

float Years(float mins)
{
    return (Days(mins)/365.0);
}

float RestOfMins(float mins)
{
    return (Days(mins) - ((int) Days(mins)))*1440;
}

float RestOfDays(float mins)
{
    return (Years(mins) - ((int) Years(mins)))*365;
}

int main ()
{
    float mins;
    float days;
    float restOfMins;
    float years;
    float restOfDays;

    printf("Enter the number of minutes: ");
    scanf("%f", &mins);                                                      // mins = 525600.0 + 1440.0;
    printf("\n");

    printf("Number of minutes entered is: %f \n", mins);

    // days = Days(mins); //1440
    // restOfMins = RestOfMins(mins);

    printf ("Number of minutes entered is: %i days and %.2f minutes \n", ((int) Days(mins)), RestOfMins(mins));

    // years =  Years(mins); //525600
    // restOfDays = RestOfDays(mins);

    printf ("Number of minutes entered is: %i years and %.5f days \n", ((int) Years(mins)), RestOfDays(mins));
}
