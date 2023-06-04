#include <stdio.h>

int main()
{
    int primeNumbers[50] = {2, 3}; // primeNumbers = primes
    int number; // number = p
    int count = 2; // count = primeIndex
    int i = 0;
    float fn;
    int in;

    printf("All prime numbers from 3 to 100 are: \n");

    for (number=5; number<=100; number+=2)
    {
        for (primeNumbers[i]; i<=50; i+=1)
        {
            fn = (float) (number/primeNumbers[i]);
            in = (float) ((int) (number/primeNumbers[i]));
            if ((fn-in)!=0.00);
            {
                primeNumbers[count] = number;
                count++;
            }
        }
    }

    printf("%ls", primeNumbers);
}
