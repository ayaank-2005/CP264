/*
--------------------------------------------------
Project: a1q3
File:    mymortgage.h
Author:  Ayaan Khan
Version: 2026-01-15
--------------------------------------------------
*/
#ifndef MYMORTGAGE_H
#define MYMORTGAGE_H

float mypowf(float b, int n);

float monthly_payment(float principal_amount, float annual_interest_rate, int years);

float total_payment(float principal_amount, float annual_interest_rate, int years);

float total_interest(float principal_amount, float annual_interest_rate, int years);

#endif
