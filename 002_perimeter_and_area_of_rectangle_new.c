// without functions

#include <stdio.h>

int main()
{
    double LengthOfSide, WidthOfSide, PerimeterOfRectangle, AreaOfRectangle;

    printf("Enter LengthOfSide: ");
    scanf("%f", &LengthOfSide);
    printf("\n");

    printf("Enter WidthOfSide: ");
    scanf("%f", &WidthOfSide);
    printf("\n");

    PerimeterOfRectangle = 2.0*(LengthOfSide+WidthOfSide);
    AreaOfRectangle = LengthOfSide*WidthOfSide;

    printf("PerimeterOfRectangle is: %f \n", PerimeterOfRectangle);
    printf("AreaOfRectangle is: %f \n", AreaOfRectangle);
}
