/*
 --------------------------------------------------
Project: a4q1
File:    mysort.h
Author:  Ayaan Khan
Version: 2026-02-06
--------------------------------------------------
*/


#ifndef MYSORT_H
#define MYSORT_H 

// your code document
void selection_sort(void *a[], int left, int right);

// your code document
void quick_sort(void *a[], int left, int right);

// your code document
void cmp_sort(void *a[], int left, int right, int (*cmp)(void*, void*) );

#endif