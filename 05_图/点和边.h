#pragma once
#include<iostream>
using namespace std;
#include<vector>
class Edge;
class Node  //点的数据项
{
public:
	int value;  //节点编号
	int in;  //入度
	int out;  //出度
	vector<Node>* nexts;
	vector<Edge>* edges;
	bool operator<(const Node& node) const  //重载小于号便于set建立二叉排序（set底层是红黑树有序)
	{
		return this->value < node.value;

	}
	Node() 
	{
		value = 0;
		in = 0;
		out = 0;
		nexts = new vector<Node>;
		edges = new vector<Edge>;
	}
	Node(int value)
	{
		this->value = value;
		in = 0;
		out = 0;
		nexts = new vector<Node>;
		edges = new vector<Edge>;
	}
};

class Edge  //边的数据项
{
public:
	int weight;  //边的权值
	Node from;   //从哪出
	Node to;   //到哪去
	Edge(int weight,Node from,Node to)
	{
		this->weight = weight;
		this->from = from;
		this->to = to;
	}
	bool operator<(Edge e) const
	{
		return this->weight < e.weight;
	}
};
