// with functions, with struct

#include <stdio.h>

struct rainfall12M {
  float inch1;
  float inch2;
  float inch3;
  float inch4;
  float inch5;
  float inch6;
  float inch7;
  float inch8;
  float inch9;
  float inch10;
  float inch11;
  float inch12;
};

float calcTotalRainfallPerYear(struct rainfall12M year2k);
void printTotalRainfallPerYear(int years[5], struct rainfall12M arrayRainfall[]);

float calcAverageRainfallPerMonthIn1Year(struct rainfall12M year2k);
void printAverageRainfallPerMonthIn1Year(int years[5], struct rainfall12M arrayRainfall[]);

float calcAverageRainfallPerYear(struct rainfall12M arrayRainfall[]);
void printAverageRainfallPerYear(int years[5], struct rainfall12M arrayRainfall[]);

float calcAverageRainfallPerMonthAcross5Years(int monthNumber, struct rainfall12M arrayRainfall[]);
void printAverageRainfallPerMonthAcross5Years(char months[], struct rainfall12M arrayRainfall[]);

/*
struct rainfall calc() {} // returns a struct with format of arrayRainfall
*/

float calcTotalRainfallPerYear(struct rainfall12M year2k) {
  return (year2k.inch1 + year2k.inch2 + year2k.inch3 + year2k.inch4 + year2k.inch5 + year2k.inch6 + year2k.inch7 +
          year2k.inch8 + year2k.inch9 + year2k.inch10 + year2k.inch11 + year2k.inch12);
}

void printTotalRainfallPerYear(int years[5], struct rainfall12M arrayRainfall[]) {
  float totalPerYear[5];

  printf("year   totalPerYear\n");

  for (int yearNumber = 0; yearNumber < 5; yearNumber++) {
    totalPerYear[yearNumber] = calcTotalRainfallPerYear(arrayRainfall[yearNumber]);

    printf("%i     ", years[yearNumber]);

    // (totalPerYear[yearNumber]<100) ? printf("0%.4f \n", totalPerYear[yearNumber]) : printf("%.4f \n",
    // totalPerYear[yearNumber]);

    printf((totalPerYear[yearNumber] < 100) ? "0%.4f \n" : "%.4f \n", totalPerYear[yearNumber]);
  }

  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");
}

float calcAverageRainfallPerMonthIn1Year(struct rainfall12M year2k) {
  return ((calcTotalRainfallPerYear(year2k)) / 12);
}

void printAverageRainfallPerMonthIn1Year(int years[5], struct rainfall12M arrayRainfall[]) {
  float averagePerMonthIn1Year[5];

  printf("year   averagePerMonthIn1Year \n");

  for (int yearNumber = 0; yearNumber < 5; yearNumber++) {
    averagePerMonthIn1Year[yearNumber] = calcAverageRainfallPerMonthIn1Year(arrayRainfall[yearNumber]);

    printf("%i         ", years[yearNumber]);

    // (averagePerMonthIn1Year[yearNumber]<10) ? printf("0%.4f \n", averagePerMonthIn1Year[yearNumber]) : printf("%.4f
    // \n", averagePerMonthIn1Year[yearNumber]);

    printf((averagePerMonthIn1Year[yearNumber] < 10) ? "0%.4f \n" : "%.4f \n", averagePerMonthIn1Year[yearNumber]);
  }

  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");
}

float calcAverageRainfallPerYear(struct rainfall12M arrayRainfall[]) {
  float sum = 0.0;

  for (int yearNumber = 0; yearNumber < 5; yearNumber++) {
    sum += calcAverageRainfallPerMonthIn1Year(arrayRainfall[yearNumber]);
  }

  return (sum / 5);
}

void printAverageRainfallPerYear(int years[5], struct rainfall12M arrayRainfall[]) {
  printf("   year      averagePerYear \n");
  printf("%i-%i       %.4f \n", years[0], years[4], calcAverageRainfallPerYear(arrayRainfall));
  printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");
}

float calcAverageRainfallPerMonthAcross5Years(int monthNumber, struct rainfall12M arrayRainfall[]) {
  float sum = 0.0;

  for (int index = 0; index < 4; index++) {
    if (monthNumber == 0) {
      sum += (arrayRainfall[index].inch1);
    }

    else if (monthNumber == 1) {
      sum += (arrayRainfall[index].inch2);
    }

    else if (monthNumber == 2) {
      sum += (arrayRainfall[index].inch3);
    }

    else if (monthNumber == 3) {
      sum += (arrayRainfall[index].inch4);
    }

    else if (monthNumber == 4) {
      sum += (arrayRainfall[index].inch5);
    }

    else if (monthNumber == 5) {
      sum += (arrayRainfall[index].inch6);
    }

    else if (monthNumber == 6) {
      sum += (arrayRainfall[index].inch7);
    }

    else if (monthNumber == 7) {
      sum += (arrayRainfall[index].inch8);
    }

    else if (monthNumber == 8) {
      sum += (arrayRainfall[index].inch9);
    }

    else if (monthNumber == 9) {
      sum += (arrayRainfall[index].inch10);
    }

    else if (monthNumber == 10) {
      sum += (arrayRainfall[index].inch11);
    }

    else {
      sum += (arrayRainfall[index].inch12);
    }

    return sum;
  }

  /*
  if (monthNumber==0)
  {
      return((arrayRainfall[0].inch1 + arrayRainfall[1].inch1 + arrayRainfall[2].inch1 + arrayRainfall[3].inch1 +
  arrayRainfall[4].inch1)/5);
  }
  else if (monthNumber==1)
  {
      return((arrayRainfall[0].inch2 + arrayRainfall[1].inch2 + arrayRainfall[2].inch2 + arrayRainfall[3].inch2 +
  arrayRainfall[4].inch2)/5);
  }
  else if (monthNumber==2)
  {
      return((arrayRainfall[0].inch3 + arrayRainfall[1].inch3 + arrayRainfall[2].inch3 + arrayRainfall[3].inch3 +
  arrayRainfall[4].inch3)/5);
  }
  else if (monthNumber==3)
  {
      return((arrayRainfall[0].inch4 + arrayRainfall[1].inch4 + arrayRainfall[2].inch4 + arrayRainfall[3].inch4 +
  arrayRainfall[4].inch4)/5);
  }
  else if (monthNumber==4)
  {
      return((arrayRainfall[0].inch5 + arrayRainfall[1].inch5 + arrayRainfall[2].inch5 + arrayRainfall[3].inch5 +
  arrayRainfall[4].inch5)/5);
  }
  else if (monthNumber==5)
  {
      return((arrayRainfall[0].inch6 + arrayRainfall[1].inch6 + arrayRainfall[2].inch6 + arrayRainfall[3].inch6 +
  arrayRainfall[4].inch6)/5);
  }
  else if (monthNumber==6)
  {
      return((arrayRainfall[0].inch7 + arrayRainfall[1].inch7 + arrayRainfall[2].inch7 + arrayRainfall[3].inch7 +
  arrayRainfall[4].inch7)/5);
  }
  else if (monthNumber==7)
  {
      return((arrayRainfall[0].inch8 + arrayRainfall[1].inch8 + arrayRainfall[2].inch8 + arrayRainfall[3].inch8 +
  arrayRainfall[4].inch8)/5);
  }
  else if (monthNumber==8)
  {
      return((arrayRainfall[0].inch9 + arrayRainfall[1].inch9 + arrayRainfall[2].inch9 + arrayRainfall[3].inch9 +
  arrayRainfall[4].inch9)/5);
  }
  else if (monthNumber==9)
  {
      return((arrayRainfall[0].inch10 + arrayRainfall[1].inch10 + arrayRainfall[2].inch10 + arrayRainfall[3].inch10 +
  arrayRainfall[4].inch10)/5);
  }
  else if (monthNumber==10)
  {
      return((arrayRainfall[0].inch11 + arrayRainfall[1].inch11 + arrayRainfall[2].inch11 + arrayRainfall[3].inch11 +
  arrayRainfall[4].inch11)/5);
  }
  else
  {
      return((arrayRainfall[0].inch12 + arrayRainfall[1].inch12 + arrayRainfall[2].inch12 + arrayRainfall[3].inch12 +
  arrayRainfall[4].inch12)/5);
  }
  */
}

void printAverageRainfallPerMonthAcross5Years(char months[], struct rainfall12M arrayRainfall[]) {
  float averagePerMonthAcross5Years[12];

  printf("averagePerMonthAcross5Years \n");

  for (int i = 0; i < 48; i += 4) {
    printf(" %c%c%c   ", months[i], months[i + 1], months[i + 2]);
  }

  printf("\n");

  for (int monthNumber = 0; monthNumber < 12; monthNumber++) {
    averagePerMonthAcross5Years[monthNumber] = calcAverageRainfallPerMonthAcross5Years(monthNumber, arrayRainfall);

    // (averagePerMonthAcross5Years[monthNumber]<10) ? printf("0%.2f  ", averagePerMonthAcross5Years[monthNumber]) :
    // printf("%.2f  ", averagePerMonthAcross5Years[monthNumber]);

    printf((averagePerMonthAcross5Years[monthNumber] < 10) ? "0%.2f  " : "%.2f  ",
           averagePerMonthAcross5Years[monthNumber]);
  }

  printf("\n \n~*~*~*~*~*~*~*~*~*~*~*~*~ \n \n");
}

int main() {
  int years[5] = {2000, 2001, 2002, 2003, 2004};
  char months[] = {"Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec"};

  struct rainfall12M year2k0 = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.10, 10.11, 11.12, 12.13};     // type: struct
  struct rainfall12M year2k1 = {2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.10, 10.11, 11.12, 12.13, 13.14};   // type: struct
  struct rainfall12M year2k2 = {3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.10, 10.11, 11.12, 12.13, 13.14, 14.15}; // type: struct
  struct rainfall12M year2k3 = {4.5, 5.6, 6.7, 7.8, 8.9, 9.10, 10.11, 11.12, 12.13, 13.14, 14.15, 15.16}; // type:
                                                                                                          // struct
  struct rainfall12M year2k4 = {5.6,   6.7,   7.8,   8.9,   9.10,  10.11,
                                11.12, 12.13, 13.14, 14.15, 15.16, 16.17}; // type: struct

  // to create an array of structures:
  struct rainfall12M arrayRainfall[] = {year2k0, year2k1, year2k2, year2k3, year2k4}; // type: array of structs

  printTotalRainfallPerYear(years, arrayRainfall);
  printAverageRainfallPerMonthIn1Year(years, arrayRainfall);
  printAverageRainfallPerYear(years, arrayRainfall);
  printAverageRainfallPerMonthAcross5Years(months, arrayRainfall);
}
