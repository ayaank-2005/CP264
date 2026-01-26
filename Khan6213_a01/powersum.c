/*
--------------------------------------------------
Project: a1q2
File:    powersum.c
Author:  Ayaan Khan
Version: 2026-01-15
--------------------------------------------------
*/

#include "powersum.h"

int power_overflow(int b, int n)
{
    if (n == 0) {
        return 0;
    }

    // If b is 0 and n > 0, then b^n = 0 (no overflow)
    if (b == 0) {
        return 0;
    }

    int result = 1;

    for (int i = 1; i <= n; i++) {
        int temp = result * b;

        // reverse-check (your method)
        if (temp / b != result) {
            return 1;
        }

        // update result using temp (don’t multiply twice)
        result = temp;
    }

    return 0;
}

int mypow(int b, int n)
{

    if(n == 0)
    return 1;

    int result = 1;

    for(int i=1; i<=n; i++){
        result = result * b;
    }
return result;

}

int powersum(int b, int n)
{
int sum = 0;
int power = 1; // This represents b^0

for(int i=1; i<=n; i++){
    power = power * b;
    sum = sum + power;

}
return sum;
}