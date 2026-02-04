/** @file  strings_length.c
 * -------------------------------------
 * @author Ayaan Khan, 169062130, Khan6213@mylaurier.ca
 *
 * @version 2026-02-04
 *
 * -------------------------------------
 */
#include "functions.h"
#include <string.h>

void strings_length(strings_array *source, FILE *fp_short, FILE *fp_long,
		int length) {

	if (source == NULL || fp_short == NULL || fp_long == NULL) {
		return;
	}
	for (int i = 0; i < source->count; i++) {
		char *s = source->strings[i];
		int L = strlen(s);

		if (L < length) {
			fprintf(fp_short, "%s\n", s);

		} else {
			fprintf(fp_long, "%s\n", s);

		}
	}
}
