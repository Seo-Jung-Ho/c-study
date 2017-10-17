#include <stdio.h>
#include <stdlib.h>

typedef struct tagDisjointSet {
	struct tagDisjointSet* parent;
	void* data;
}DisjointSet;

void unionSet(DisjointSet* set1, DisjointSet* set2);
DisjointSet* findSet(DisjointSet* set);
DisjointSet* makeSet(void* newData);
void destroySet(DisjointSet* set);
