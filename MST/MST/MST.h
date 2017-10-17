#include "DisjointSet.h"
#include "Graph.h"
#include "PriorityQueue.h"

#define MAX_WEIGHT 36267

void prim(Graph* g, Vertex* startVertex, Graph* MST);
void kruskal(Graph* g, Graph* mst);