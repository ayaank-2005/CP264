/** @file  name_set.c
 * -------------------------------------
 * @author Ayaan Khan, 169062130, khan6213@mylaurier,.ca
 *
 * @version 2025-09-01
 *
 * -------------------------------------
 */
#include "name_set.h"

// ==============================================================================================
// Functions

name_set* name_set_initialize() {

	// your code here
	name_set *set_ptr;
	set_ptr = malloc(sizeof(name_set));

	if (set_ptr == NULL) {
		return NULL;
	}
	set_ptr->front = NULL;
	set_ptr->rear = NULL;
	set_ptr->count = 0;

	return set_ptr;
}

int name_set_free(name_set **source) {

	int freed_count;
	name_node *next_node;
	name_node *current;

	if (source == NULL || *source == NULL) {
		return 0;
	}
	freed_count = 0;

	current = (*source)->front;

	while (current != NULL) {
		next_node = current->next;
		free(current);
		freed_count++;
		current = next_node;
	}
	free(*source);
	freed_count++;
	*source = NULL;

	return freed_count;
}

bool name_set_append(name_set *source, const char *first_name,
		const char *last_name) {

	if (source == NULL) {
		return false;
	}
	if ((name_set_contains(source, first_name, last_name)) == true) {
		return false;
	}
	name_node *new_node;
	new_node = malloc(sizeof(*new_node));

	if (new_node == NULL) {
		return false;
	}
	strncpy(new_node->first_name, first_name, NAME_LEN-1);
	new_node->first_name[NAME_LEN - 1] = '\0';

	strncpy(new_node->last_name, last_name, NAME_LEN-1);
	new_node->last_name[NAME_LEN - 1] = '\0';

	new_node->next = NULL;

	if (source->front == NULL) {
		source->front = new_node;
		source->rear = new_node;
	} else {
		source->rear->next = new_node;
		source->rear = new_node;
	}
	source->count++;

	return true;
}

bool name_set_contains(const name_set *source, const char *first_name,
		const char *last_name) {

	name_node *node;

	if (source == NULL) {
		return false;
	}

	node = source->front;

	while (node != NULL) {

		if (strcmp(node->first_name, first_name) == 0
				&& strcmp(node->last_name, last_name) == 0) {

			return true;
		}
		node = node->next;

	}

	return false;
}

int name_set_count(const name_set *source) {

	if (source == NULL) {
		return 0;
	}

	return source->count;
}

void name_set_print(const name_set *source) {
	// Set node to point to the first node in the set.
	name_node *node = source->front;

	// Traverse the set.
	while (node != NULL) {
		printf("%s, %s\n", node->last_name, node->first_name);
		// Update the pointer to the next node.
		node = node->next;
	}
	return;
}
