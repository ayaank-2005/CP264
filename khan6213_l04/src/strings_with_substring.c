/** @file  strings_with_substring.c
 * -------------------------------------
 * @author Ayaan Khan, 169062130, Khan6213@mylaurier.ca
 *
 * @version 2026-02-04
 *
 * -------------------------------------
 */
#include "functions.h"

void strings_with_substring(strings_array *source, char *substr) {

	if (source == NULL || substr == NULL) {
		return;
	}
	for (int i = 0; i < source->count; i++) {
		char *s = source->strings[i];
		if (strstr(s, substr) != NULL) {
			printf("%s\n", s);
		}
	}
}

