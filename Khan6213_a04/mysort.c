/*
 --------------------------------------------------
Project: a4q1
File:    mysort.c
Author:  Ayaan Khan
Version: 2026-02-06
--------------------------------------------------
*/
#include "mysort.h"

// swap pointers
void swap(void **x, void **y) {
     void *temp = *y;
     *y = *x;
     *x = temp;
}

// a compare floating values pointed by void pointers. 
int cmp(void *x, void *y) {
   float a = *(float*)x;
   float b = *(float*)y; 
     if (a > b) return 1;
     else if (a < b) return -1;
     else return 0;
}   

void selection_sort(void *a[], int left, int right)
{
for(int i = left; i < right ; i++){
    int min_index = i;  
        for(int j = i + 1; j < right + 1; j++){
            if (cmp(a[j],a[min_index])<0)
                min_index = j;
    }
    
if (min_index != i ){
    swap(&a[i], &a[min_index]);
}
}
}


void quick_sort(void *a[], int left, int right)
{ 
if( left < right ) {

    void *pivot = a[left];
    int i = left+1;
    int j = right;
        while(i <= j) {
            while( i <= right && cmp( a[i], pivot) <= 0) i++;
                while( j >= left && cmp(a[j] , pivot) > 0) j--;
                    if( i < j ) {
                        swap (&a[i], &a[j]); 
                        i = i+1;
                        j = j-1;
                    }
        }
                swap(&a[left], &a[j]);
                quick_sort(a, left, j-1);
                quick_sort(a, j+1, right);
}
}


void cmp_sort(void *a[], int left, int right, int (*cmp)(void*, void*) )
{ 
if (left >= right){

}
 void *pivot = a[left];
    int i = left+1;
    int j = right;
    while(i <= j) {
        while( i <= right && cmp( a[i], pivot) <= 0) i++;
                while( j >= left && cmp(a[j] , pivot) > 0) j--;
                    if( i < j ) {
                        swap (&a[i], &a[j]); 
                        i = i+1;
                        j = j-1;
                    }
        }
                swap(&a[left], &a[j]);
                cmp_sort(a, left, j-1, cmp);
                cmp_sort(a, j+1, right, cmp);
}
