#include "table.h"

struct node {
	size_t key;
	void *val;
	struct node *next;
};

typedef struct table {
	size_t size;
	struct node *first;
} Table;
