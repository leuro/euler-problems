#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * Problem 27 from Project Euler
 *
 * Euler discovered the remarkable quadratic formula:
 *
 * n² + n + 41
 *
 * It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.
 *
 * The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.
 *
 * Considering quadratics of the form:
 *
 * n² + an + b, where |a| < 1000 and |b| < 1000
 *
 * where |n| is the modulus/absolute value of n
 * e.g. |11| = 11 and |−4| = 4
 * Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
 *
 * PLEASE NOTE
 * In order to compile you must have gcc, or similar, installed
 *
 * REGARDING THE PERFORMANCE
 * This is not the final version of the Algorithm, anyone can improve it.
 * If you have a better solution please submit a pull request, or an issue, on Github.
 *
 * @author Claudio Ludovico Panetta (@Ludo237)
 *
 * @version 1.0.0
 **/
#define MAX 1000 // As always

/**
 * is_prime
 * @param signed int number
 * @return unsigned int
 * @description
 *  A new kind of check for prime number, bit faster
 **/
unsigned int is_prime(signed int number);

int main(int argc, char *argv[])
{
    // Benchmark variables
    double start, end;
    // Helper variables
    signed int counter = 0, first_maximum = 0, second_maximum = 0;
    // Algorithm starts
    start = clock();
    printf("Algorithm starts, please wait\n");
    // Iterating our limit
    for(signed int i = ((MAX * (-1)) + 1); i < MAX; i++)
    {
        for(signed int j = ((MAX * (-1)) + 1); j < MAX; j++)
        {
            signed int temp = 0, number = j;
            for(signed int k = 0; is_prime(abs(number)) == 1; k++)
            {
                temp++;
                number = (k * k) + (i * k) + j; // Hello Euler
            }
            if(temp > counter)
            {
                // Normal swap of terms
                counter = temp;
                first_maximum = i;
                second_maximum = j;
            }
        }
    }
    // Algorithm end
    end = clock();
    printf("Total %d\n", (first_maximum * second_maximum));
    printf("Algorithm end.\n");
    printf("Total time: %f\n", (end - start)/CLOCKS_PER_SEC);
    return 0;
}

unsigned int is_prime(signed int number)
{
    if( number % 2 == 0)
    {
        return 0;
    }
    for(signed int i = 3; i < ceil((sqrt(number))) + 1; i+=2)
    {
        if(number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
