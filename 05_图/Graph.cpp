#include"Graph.h"
Graph::Graph()
{
	this->nodes = new map<int, Node*>;
	this->edges = new set<Edge*>;
}

//给顶一个N*3的二维数组，第一个是入点编号，第二个是出点编号，第三个是该边的权值，创建图
Graph* Graph::creatGraph(int matrix[][3],int length)  //创建一个图
{
	Graph *graph = new Graph;
	for (int i = 0; i < length; i++)
	{
		int from = matrix[i][0];
		int to = matrix[i][1];
		int weight = matrix[i][2];
		
		if (!graph->nodes->count(from)) //from节点在 图中不存在
			graph->nodes->insert(make_pair(from, new Node(from)));
		if (!graph->nodes->count(to))
			graph->nodes->insert(make_pair(to, new Node(to)));

		Node* fromNode = (*graph->nodes)[from];
		Node* toNode = (*graph->nodes)[to];
		Edge* newEdge = new Edge(weight, *fromNode, *toNode);

		fromNode->nexts->push_back(*toNode);
		fromNode->out++;
		toNode->in++;
		fromNode->edges->push_back(*newEdge);
		graph->edges->insert(newEdge);
	}
	return graph;
}

//给定一个点，实现宽度优先遍历
void Graph::bfs(Node* node)   //采用数组实现
{
	queue<Node>qu;
	int visit[1000] = { 0 };
	qu.push(*node);
	visit[node->value] = 1;
	while (!qu.empty())
	{
		Node cur = qu.front();
		qu.pop();
		cout << cur.value << endl;  //此处可以换成宽度优先遍历的其他操作
		for (int i = 0; i < (*cur.nexts).size(); i++)
		{
			if (visit[(*cur.nexts)[i].value] == 0)
			{
				qu.push((*cur.nexts)[i]);
				visit[(*cur.nexts)[i].value] = 1;
			}
		}
	}
}
//给定一个点，实现宽度优先遍历
void Graph::bfs2(Node* node)  //采用set实现
{
	queue<Node>qu;
	set<Node>sets;
	qu.push(*node);
	sets.insert(*node);
	while (!qu.empty())
	{
		Node cur = qu.front();
		qu.pop();
		cout << cur.value << endl;  //此处可以换成宽度优先遍历的其他操作
		for (vector<Node>::iterator it = (*cur.nexts).begin(); it != (*cur.nexts).end(); it++)
		{
			if (!sets.count(*it))
			{
				qu.push(*it);
				sets.insert(*it);
			}
		}
	}
}

//给定一个点，实现深度优先遍历
void Graph::dfs(Node* node)
{
	if (node == NULL)
		return;
	stack<Node> sta;
	set<Node>sets;
	sta.push(*node);
	sets.insert(*node);
	cout << node->value << endl;
	while (!sta.empty())
	{
		Node cur = sta.top();
		sta.pop();
		for (int i = 0; i < (*cur.nexts).size(); i++)
		{
			if (!sets.count((*cur.nexts)[i]))  //发现当前节点存在没有遍历过的相邻节点
			{
				sta.push(cur);    //把当前节点和他的其中一个相邻节点压入栈
				sta.push((*cur.nexts)[i]);
				sets.insert((*cur.nexts)[i]);  //集合中注册上这个相邻节点，代表他已经访问过了
				cout << (*cur.nexts)[i].value << endl;
				break;   //直接break掉，不再管其他的相邻节点
			}
		}

	}
}

//拓补排序
vector<Node>* Graph::sortedTopology(Graph g)
{
	map<Node, int> inmap;   //key为某一个节点，value为该节点的入度
	queue<Node> zeroqu;   //入度为0的点才能进入队列
	for (map<int, Node*>::iterator it = (*g.nodes).begin(); it != (*g.nodes).end(); it++)  //这个for循环跑完，图中所有点的入读信息被记录，所有入度为0的点进入队列
	{
		Node t = *(*it).second;
		inmap.insert(make_pair(t, t.in));
		if (t.in == 0)
			zeroqu.push(t);
	}
	//拓补排序的结果依次加入到result
	vector<Node>* result = new vector<Node>;
	while (!zeroqu.empty())
	{
		Node cur = zeroqu.front();
		result->push_back(cur);
		for (vector<Node>::iterator it = (*cur.nexts).begin(); it != (*cur.nexts).end(); it++) //遍历这个点的指向节点，将他们的入读全部减一，从而消除这个点在图中的影响
		{
			inmap[*it]--;
			if (inmap[*it] == 0)
				zeroqu.push(*it);
		}
	}
	return result;
}

//prim算法,待完成
set<Edge> Graph::primMST(Graph g)
{
	priority_queue<Edge, vector<Edge>, greater<Edge>> pQu;  //解锁的边进小根堆
	set<Node> sets;
	set<Edge> result;  //依次挑选的边在result里


	return result;

}
