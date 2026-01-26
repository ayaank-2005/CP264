/*
--------------------------------------------------
Project: a1q3
File:    mymortgage.c
Author:  Ayaan Khan
Version: 2026-01-15
--------------------------------------------------
*/
#include "mymortgage.h"

#define EPSILON 1e-6f

float mypowf(float b, int n) {
    float result = 1.0;

    for (int i = 1; i <= n; i++) {
    result = result * b;
    }
return result;
}

float monthly_payment(float principal_amount, float annual_interest_rate, int years) {

    int months = years *12;
    float r = annual_interest_rate / 12 / 100;

if (r <= EPSILON){
    return principal_amount/months;
}
    float base = 1 + r;
    float power = mypowf(base, months);

    float numerator = principal_amount * r * power;
    float denominator = power - 1;
return numerator / denominator; 
}

float total_payment(float principal_amount, float annual_interest_rate, int years) {
    int months = years * 12;
    float monthly = monthly_payment(principal_amount, annual_interest_rate, years);

return monthly * months;
}

float total_interest(float principal_amount, float annual_interest_rate, int years) {
    float total = total_payment(principal_amount, annual_interest_rate, years);

return total - principal_amount;
}