#ifndef TABLE_H
#define TABLE_H
#include <stddef.h>

struct node {
	size_t key;
	void *val;
	struct node *next;
};

struct table {
	size_t size;
	struct node *first;
};

typedef struct table* Table;

struct table* newTable();
void freeTable();
void tAdd(struct table *table, void *val);
void* tSetK(struct table *table, size_t key, void *val);
void* tSetI(struct table *table, size_t index, void *val);
void* tGetK(struct table *table, size_t key);
void* tGetI(struct table *table, size_t index);
void* tPopK(struct table *table, size_t key);
void* tPopI(struct table *table, size_t index);

#endif
