// with functions

#include <stdio.h>

float PerimeterOfRectangle(float LengthOfSide, float WidthOfSide) {
  return 2.0 * (LengthOfSide + WidthOfSide);
}

float AreaOfRectangle(float LengthOfSide, float WidthOfSide) {
  return LengthOfSide * WidthOfSide;
}

int main() {
  float LengthOfSide, WidthOfSide;
  float perimeter, area;

  printf("Enter LengthOfSide: ");
  scanf("%f", &LengthOfSide);
  printf("\n");

  printf("Enter WidthOfSide: ");
  scanf("%f", &WidthOfSide);
  printf("\n");

  perimeter = PerimeterOfRectangle(LengthOfSide, WidthOfSide);
  area = AreaOfRectangle(LengthOfSide, WidthOfSide);

  printf("Perimeter Of Rectangle is: %f \n", perimeter);
  printf("Area Of Rectangle is: %f \n", area);
}
