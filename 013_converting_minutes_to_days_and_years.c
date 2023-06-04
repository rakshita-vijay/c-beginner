// without functions

#include <stdio.h>

int main ()
{
    float mins;
    float days;
    float lowestMultOf1440;
    float restOfMins;
    float years;
    float restOfDays;

    printf("Enter the number of minutes: ");
    scanf("%f", &mins);
    printf("\n");

    // mins = 525600.0 + 1440.0;

    printf("Number of minutes entered is: %f \n", mins);

    days = (mins/(60.0*24.0)); //1440
    restOfMins = ceil((days - ((int) days))*1440);

    printf ("Number of minutes entered is: %i days and %f minutes \n", ((int) days), restOfMins);

    years =  (mins/(60.0*24.0*365.0)); //525600
    restOfDays = ceil((years - ((int) years))*365);

    printf ("Number of minutes entered is: %i years and %f days \n", ((int) years), restOfDays);
}
