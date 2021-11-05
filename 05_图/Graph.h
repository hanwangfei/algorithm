#pragma once
#include"点和边.h"
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<concurrent_priority_queue.h>
#include<algorithm>
class Graph
{
public:
	map<int, Node*>* nodes;
	set<Edge*>* edges;

	Graph();
	

	//给定一个N*3的二维数组，第一个是入点，第二个是出点，第三个是该边的权值，创建图
	Graph* creatGraph(int matrix[][3],int length); //创建一个图

	//给定一个点，实现宽度优先遍历
	void bfs(Node* node);     //采用数组实现
	void bfs2(Node* node);    //采用set容器实现
	//给定一个点，实现深度优先遍历
	void dfs(Node* node); 

	//拓补排序
	vector<Node>* sortedTopology(Graph g);

	//prim算法
	set<Edge>primMST(Graph g);
	
};
