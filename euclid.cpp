// Ahmad Yousif, CSS 342, Assignment 3, 5/19/2020
// euclid.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <sys/time.h>

using namespace std;

// <summary>
// Uses gettimeofday function to calculate current time in milliseconds.
// </summary>

// <return>
// Returns a long long value representing the current time in microseconds.
// </return>
long long getCurrentTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long long currentTime = tv.tv_sec * 1000000 + tv.tv_usec;
    return currentTime;
}

// Global variable to record the number of mod operations taken
int modCount = 0;

// <summary>
// Calculates the greatest common denominator (gcd) of the two integer parameters.
// </summary>

// <parameter = "A">
// Integer representing the first value to calculate gcd.
// </parameter>

// <parameter = "B">
// Integer representing the second value to calculate gcd.
// </parameter>

// <return>
// Returns an integer value representing the gcd of the two parameters.
// </return>
int gcd(int A, int B)
{
    // Euclidean Algorithm
    if (A == 0)
    {
        return B;
    }
    else if (B == 0)
    {
        return A;
    }
    else
    {
        int r = A % B;
        modCount++;
        return gcd(B, r);
    }
}

// Program execution begins here
int main()
{
    int num;
    cout << "Enter upper bound: ";
    cin >> num;

    // Local variables to capture the current values in the exectution
    int recordA = 0;
    int recordB = 0;
    int currentModCount = 0;

    for (int i = 8; i <= num; i++)
    {
        long long startTime = getCurrentTime();
        int max = 0;
        for (int b = 8; b <= i; b++)
        {
            for (int a = 1; a <= b; a++)
            {
                modCount = 0;
                gcd(b, a);

                if (max < modCount)
                {
                    currentModCount = modCount;
                    max = currentModCount;
                    recordA = a;
                    recordB = b;
                }
            }
        }

        long long endTime = getCurrentTime();
        long duration = endTime - startTime;

        // Prints output--including index, gcd, number of mod operations, and time taken--to the console
        cout << "At i=" << i << "; gcd (" << recordA << ", " << recordB << ") = " << gcd(recordA, recordB) << " took " << currentModCount << " modulus operations." << " Time taken: " << duration << " µs" << endl;
    }
}