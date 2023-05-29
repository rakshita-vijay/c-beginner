// with functions

#include <stdio.h>

float calcGrossPay(float numberOfHoursWorked)
{
    float hourlyPayUnderFortyHours = 12.0;
    float hourlyPayAboveFortyHours = 18.0;

    if (numberOfHoursWorked <= 40.0)
    {
        return (numberOfHoursWorked*hourlyPayUnderFortyHours);
    }

    else if (numberOfHoursWorked > 40.0)
    {
        return (40.0*hourlyPayUnderFortyHours)+((numberOfHoursWorked-40.0)*hourlyPayAboveFortyHours);
    }
}

float calcTaxes(float numberOfHoursWorked)
{
    float grossPay = calcGrossPay(numberOfHoursWorked);
    float taxFirstThreeHun = 0.15;
    float taxNextOneFifty = 0.2;
    float taxRest = 0.25;

    if (grossPay <= 300)
    {
        return grossPay*taxFirstThreeHun;
    }

    else if (grossPay>300 && grossPay<=450)
    {
        return (300*taxFirstThreeHun)+((grossPay-300)*taxNextOneFifty);
    }

    else if (grossPay > 450)
    {
        // taxes = ((300*taxFirstThreeHun) + (150*taxNextOneFifty) + ((grossPay-450)*taxRest));
        return 75+((grossPay-450)*taxRest);
    }
}

float calcNetPay(float numberOfHoursWorked)
{
    return calcGrossPay(numberOfHoursWorked)-calcTaxes(numberOfHoursWorked);
}

int main()
{
    float numberOfHoursWorked;

    printf("Enter the number of hours a person has worked: ");
    scanf("%f", &numberOfHoursWorked);
    printf("\n");

    // numberOfHoursWorked = 30.0; // 40*12 + 5*18 = 570

    printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");

    printf("Number of Hours Worked: %.2f \n", numberOfHoursWorked);

    printf("Gross Pay: %.2f \n", calcGrossPay(numberOfHoursWorked));
    printf("Taxes: %.2f \n", calcTaxes(numberOfHoursWorked));
    printf("NetPay: %.2f \n", calcNetPay(numberOfHoursWorked));
}
