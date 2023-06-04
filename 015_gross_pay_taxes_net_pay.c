// without functions

#include <stdio.h>

int main()
{
    float numberOfHoursWorked;
    int hourlyPayUnderFortyHours = 12;
    int hourlyPayAboveFortyHours = 18;
    float taxFirstThreeHun = 0.15;
    float taxNextOneFifty = 0.2;
    float taxRest = 0.25;
    float grossPay;
    float taxes;
    float netPay;

    printf("Enter the number of hours a person has worked: ");
    scanf("%f", &numberOfHoursWorked);
    printf("\n");

    // numberOfHoursWorked = 30.0; // 40*12 + 5*18 = 570

    printf("Number of Hours Worked: %.2f \n", numberOfHoursWorked);

    if (numberOfHoursWorked <= 40.0)
    {
        grossPay = (numberOfHoursWorked*hourlyPayUnderFortyHours);
        printf("Gross Pay: %.2f \n", grossPay);
    }

    else if (numberOfHoursWorked > 40.0)
    {
        grossPay = ((40.0*hourlyPayUnderFortyHours) + ((numberOfHoursWorked-40.0)*hourlyPayAboveFortyHours));
        printf("Gross Pay: %.2f \n", grossPay);
    }

    if (grossPay <= 300)
    {
        taxes = (grossPay * taxFirstThreeHun);
        printf("Taxes: %.2f \n", taxes);
    }

    else if (grossPay>300 && grossPay<=450)
    {
        taxes = ((300*taxFirstThreeHun) + ((grossPay-300)*taxNextOneFifty));
        printf("Taxes: %.2f \n", taxes);
    }

    else if (grossPay > 450)
    {
        // taxes = ((300*taxFirstThreeHun) + (150*taxNextOneFifty) + ((grossPay-450)*taxRest));
        taxes = 75 + ((grossPay-450)*taxRest);
        printf("Taxes: %.2f \n", taxes);
    }

    netPay = (grossPay - taxes);
    printf("NetPay: %.2f \n", netPay);
}
