#include "DisjointSet.h"

void unionSet(DisjointSet* set1, DisjointSet* set2) {
	set2 = findSet(set2);
	set2->parent = set1;
};
DisjointSet* findSet(DisjointSet* set) {
	while (set->parent != NULL) {
		set = set->parent;
	}
	return set;
};

DisjointSet* makeSet(void* newData) {
	DisjointSet* newSet = (DisjointSet*)malloc(sizeof(DisjointSet));
	newSet->parent = NULL;
	newSet->data = newData;
	return newSet;
};
void destroySet(DisjointSet* set) {
	free(set);
};
