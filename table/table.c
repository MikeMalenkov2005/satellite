#include "table.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
	size_t key;
	void *val;
	struct node *next;
};

typedef struct table {
	size_t size;
	struct node *first;
} Table;

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
	return next
}

Table* newTable() {
	Table *table = (Table*) malloc(sizeof(Table));
	table -> size = 0;
	table -> node = NULL;
}

void freeTable(Table *table) {
	struct node *node = table -> first
	free((void*)table);
	while (node != NULL) {
		node = freeNode(node);
	}
}

void tAdd(Table *table, void *val) {
	struct node *node = table -> first;
	while (node -> next != NULL) node = node -> next;
	node -> next = newNode(0, val);
	table -> size++;
}

void* tSetK(Table *table, size_t key, void *val) {
	struct node *node = table -> first;
	while (node -> next != NULL) {
		if (node -> key == key) {
			void *prev = node -> val;
			node -> val = val;
			return prev;
		}
		node = node -> next;
	}
	node -> next = newNode(key, val);
	table -> size++;
	return NULL;
}

void* tSetI(Table *table, size_t index, void *val) {
	if (index > table -> size) {
		fprintf(stderr, "Runtime index out of range exception!!!\n");
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
