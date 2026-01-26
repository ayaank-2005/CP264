/**
 * -------------------------------------
 * @file  by_index.c
 * -------------------------------------
 * @author Ayaan Khan, 169062130, khan6213@mylaurier.ca
 *
 * @version 2026-01-21
 *
 * -------------------------------------
 */
#include "by_index.h"

void fill_values_by_index(int values[], int size) {

	for (int i = 0; i < size; i++) {
		values[i] = i + 1;
	}
}

void fill_squares_by_index(int values[], long int squares[], int size) {

	for (int i = 0; i < size; i++) {
		int value = i + 1;
		values[i] = value;
		squares[i] = value * value;

	}

}

void print_by_index(int values[], long int squares[], int size) {

	printf("Value     Square\n");
	printf("-----     ------\n");

	for (int i = 0; i < size; i++) {
		int value = values[i];
		int square = squares[i];

		printf("%5d   %6d", value, square);

		printf("\n");

	}

}
