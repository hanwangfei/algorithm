#include"Graph.h"
void test()
{
	int arr[][3] = { {1,4,1},{1,3,1},{4,3,1},{4,2,1},{3,2,1} };
	Graph g;
	Graph* t = g.creatGraph(arr, 5);
	g.bfs2((*t->nodes)[1]);
}

int main()
{
	test();
	return 0;
}