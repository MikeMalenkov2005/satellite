#include "table.h"
#include <stdio.h>
#include <stdlib.h>

struct node* newNode(size_t key, void *val) {
	struct node *node = (struct node*) malloc(sizeof(struct node));
	node -> key = key;
	node -> val = val;
	node -> next = NULL;
	return node;
}

struct node* freeNode(struct node *node) {
	struct node *next = node -> next;
	free((void*)node);
	return next;
}

struct table* newTable() {
	struct table *table = malloc(sizeof(struct table));
	table -> size = 0;
	table -> first = NULL;
	return table;
}

void freeTable(struct table *table) {
	struct node *node = table -> first;
	free((void*)table);
	while (node != NULL) {
		node = freeNode(node);
	}
}

void tAdd(struct table *table, void *val) {
	if (table -> size == 0) table -> first = newNode(0, val);
	else {
		struct node *node = table -> first;
		while (node -> next != NULL) node = node -> next;
		node -> next = newNode(0, val);
	}
	table -> size++;
}

void* tSetK(struct table *table, size_t key, void *val) {
	struct node *node = table -> first;
	while (node -> next != NULL) {
		if (node -> key == key) {
			void *prev = node -> val;
			node -> val = val;
			return prev;
		}
		node = node -> next;
	}
	if (node -> key == key) {
		void *prev = node -> val;
		node -> val = val;
		return prev;
	}
	node -> next = newNode(key, val);
	table -> size++;
	return NULL;
}

void* tSetI(struct table  *table, size_t index, void *val) {
	if (index > table -> size) {
		printf("Runtime index out of range exception!!!\n");
		exit(-1);
	}
	else if (index == table -> size) {
		tAdd(table, val);
	}
	struct node *node = table -> first;
	for (size_t i = 0; i < index; i++) {
		node = node -> next;
	}
	void *prev = node -> val;
	node -> val = val;
	return prev;
}

void* tGetK(struct table *table, size_t key) {
	struct node *node = table -> first;
	while (node != NULL) {
		if (node -> key == key) {
			return node -> val;
		}
		node = node -> next;
	}
	return NULL;
}

void* tGetI(struct table *table, size_t index) {
	if (index >= table -> size) {
		printf("Runtime index out of range exception!!!\n");
		exit(-1);
	}
	struct node *node = table -> first;
	for (size_t i = 0; i < index; i++) {
		node = node -> next;
	}
	return node -> val;
}

void* tPopK(struct table *table, size_t key) {
	struct node *prev = NULL;
	struct node *node = table -> first;
	while (node != NULL) {
		if (node -> key == key) {
			void *v = node -> val;
			if (prev != NULL) prev -> next = node -> next;
			else table -> first = node -> next;
			table -> size--;
			return v;
		}
		prev = node;
		node = node -> next;
	}
	return NULL;
}

void* tPopI(struct table *table, size_t index) {
	if (index >= table -> size) {
		printf("Runtime index out of range exception!!!\n");
		exit(-1);
	}
	struct node *prev = NULL;
	struct node *node = table -> first;
	for (size_t i = 0; i < index; i++) {
		prev = node;
		node = node -> next;
	}
	void *v = node -> val;
	if (prev != NULL) prev -> next = node -> next;
	else table -> first = node -> next;
	freeNode(node);
	table -> size--;
	return v;
}
