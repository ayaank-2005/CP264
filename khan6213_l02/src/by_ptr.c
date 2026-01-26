/**
 * -------------------------------------
 * @file  by_ptr.c
 * -------------------------------------
 * @author Ayaan Khan, 169062130, khan6213@mylaurier.ca
 *
 * @version 2026-01-21
 *
 * -------------------------------------
 */
#include "by_ptr.h"

void fill_values_by_ptr(int *values, int size) {

	for (int i = 0; i < size; i++) {
		*(values + i) = i + 1;
	}
}

void fill_squares_by_ptr(int *values, long int *squares, int size) {

	for (int i = 0; i < size; i++) {
		int value = i + 1;

		*values = value, values++;
		*squares = value * value, squares++;

	}

}

void print_by_ptr(int *values, long int *squares, int size) {

	printf("Value     Square\n");
	printf("-----     ------\n");

	for (int i = 0; i < size; i++) {

		printf("%5d   %6ld", *values, *squares);
		values++;
		squares++;

		printf("\n");

	}

}

