#ifndef TABLE_H
#define TABLE_H
#include <stddef.h>

typedef struct table {
	size_t size;
} Table;

Table* newTable();
void freeTable();
void tAdd(Table *table, void *val);
void* tSetK(Table *table, size_t key, void *val);
void* tSetI(Table *table, size_t index, void *val);
void* tGetK(Table *table, size_t key);
void* tGetI(Table *table, size_t index);
void* tRemoveK(Table *table, size_t key);
void* tRemoveI(Table *table, size_t index);

#endif
