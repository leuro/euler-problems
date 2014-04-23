#include <time.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * Problem 7 from Project Euler
 *
 * By listing the first six prime numbers: 2,3,5,7,11 and 13, we can see that the 6th prime is 13
 * What is the 10001st prime number?
 *
 * PLEASE NOTE
 * In order to compile this file you must have gcc, or similar, installed
 *
 * REGARDING THE PERFORMANCE
 * This is not the final version of the algorithm, any suggestion or improvment will be very accepted.
 * If you have a better solution please submit a pull request or an issue on Github.
 *
 * @author Claudio Ludovico Panetta (@Ludo237)
 * @version 1.0.0
 **/

int main(int argc, char** argv)
{
    double clockStart, clockEnd; // First time that I'm using this to bench the algorithm

    unsigned int primenumber = 10001; // Position of our prime number
    unsigned int pivot = 3; // Where we start to test our prime numbers
    unsigned int j = 2; // Internal counter, we need to declare here

    printf("Algorithm is online, Please wait....\n");
    
    clockStart = clock(); // Starting the benchmark

    // Iterating trough numbers
    for(unsigned int i = 2; i <= primenumber;)
    {
        for(j = 2; j <= pivot -1; j++)
        {
            if(pivot % j == 0)
                break;
        }
        if(j == pivot)
        {
            // We found a prime
            i++;
        }
        pivot++;
    }

    clockEnd = clock(); // Finishing the benchmark
    printf("Algorithm end.\n");
    printf("Time: %f", (clockEnd - clockStart)/CLOCKS_PER_SEC);
    return 0;
}
