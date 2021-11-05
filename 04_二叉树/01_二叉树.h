#pragma once
#include<iostream>
using namespace std;
#include<stack>
#include<queue>
#include<map>
#include<math.h>
#include<string>
static int int_min = INT_MIN;
class Node
{
public:
	int value;
	Node* left;
	Node* right;
	Node(int value = 0)
	{
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
};
class Tree
{
public:
	Node node;
	
	//遍历本质是递归序，每个节点都必然来到三次，所谓的先序、中序、后序均是由递归序得到的
	void f(Node* head)  //递归本质
	{
		if (head == NULL)
			return;
		//第一次来到头

		f(head->left);
		//第二次来到头

		f(head->right);
		//第三次来到头

	}

	void preOrderCreat(Node*& head, char* arr, int& i) //先序构造函数
	{
		if (arr[i] == '#')
		{
			head = NULL;
			i++;
			return;
		}
		head = new Node(arr[i++]);
		preOrderCreat(head->left, arr, i);
		preOrderCreat(head->right, arr, i);
	}

	void preOrderRecur(Node* head)    //先序遍历
	{
		if (head == NULL)
			return;
		cout << head->value << "\t";
		preOrderRecur(head->left);
		preOrderRecur(head->right);
	}

	void inOrderRecur(Node* head)  //中序遍历
	{
		if (head == NULL)
			return;
		inOrderRecur(head->left);
		cout << head->value << "\t";
		inOrderRecur(head->right);
	}

	void posOrderRecur(Node* head)  //后续遍历
	{
		if (head == NULL)
			return;
		posOrderRecur(head->left);
		posOrderRecur(head->right);
		cout << head->value << "\t";
	}

	//非递归行为实现遍历
	void preOrderUnRecur(Node* head)
	{
		if (head != NULL)
		{
			stack<Node*>* sta = new stack<Node*>;
			sta->push(head);   //sta是一个栈指针，指向堆区开辟的存放一群节点指点的栈
			while (!sta->empty())
			{
				head = sta->top();
				sta->pop();
				cout << head->value << "\t";
				if (head->right != NULL)
					sta->push(head->right);
				if (head->left != NULL)
					sta->push(head->left);
			}
			delete sta;
		}
	}

	void inOrderUnRecur(Node* head)  //中序遍历  //实现思路，将左边界（left指针一路指到底）一直入栈，直到他没有left了，就弹出并打印，然后将他移到他的right上，再重复上述步骤
	{
		if (head != NULL)
		{
			stack<Node*>* sta = new stack<Node*>;
			while (!sta->empty() || head != NULL)
			{
				if (head != NULL)
				{
					sta->push(head);
					head = head->left;
				}
				else
				{
					head = sta->top();
					sta->pop();
					cout << head->value << "\t";
					head = head->right;    //head移动到right上周而复始
				}
			}
			delete sta;
		}
	}

	void posOrderUnRecur1(Node* head) //后序遍历 //实现思路，设置两个栈，首先将根节点放入辅助栈，再按照先左后右的顺序将节点放入栈一中，然后弹出后压入辅助栈中，最后直到栈一空了即将所有节点全压入了辅助栈，此时辅助栈有下往上应该是根右左的结构，在统一输出就可以得到左右根的后序遍历。
	{
		if (head != NULL)
		{
			stack<Node*>* sta = new stack<Node*>;
			stack<Node*>* sta2 = new stack<Node*>;
			sta->push(head);  //先将head仍入栈一
			while (!sta->empty())  //栈一不为空
			{
				head = sta->top();
				sta->pop();
				sta2->push(head);

				if (head->left != NULL)
					sta->push(head->left);
				if (head->right != NULL)
					sta->push(head->right);
			}
			while (!sta2->empty())
			{
				cout << sta2->top()->value << "\t";
				sta2->pop();
			}
			delete sta;
			delete sta2;
		}

	}

	void widthTravel(Node* head)  //宽度优先遍历
	{
		if (head == NULL)
			return;
		queue<Node*>* qu = new queue<Node*>;
		qu->push(head);
		while (!qu->empty())
		{
			Node* cur = qu->front();
			cout << cur->value << "\t";
			qu->pop();
			if (cur->left != NULL)
				qu->push(cur->left);
			if (cur->right != NULL)
				qu->push(cur->right);
		}
		delete qu;
	}

	int getMaxWidthNodes(Node* head)   //得到一棵二叉树的最多节点那一层的节点数
	{
		if (head == NULL)
			return 0;
		queue<Node*>* qu = new queue<Node*>;
		qu->push(head);
		map<Node*, int>* levelMap = new map<Node*, int>;
		levelMap->insert(make_pair(head, 1));
		int curLevel = 1;
		int curLevelNodes = 0;
		int max = -1;
		while (!qu->empty())
		{
			Node* cur = qu->front();
			qu->pop();
			int curNodeLevel = (*levelMap)[cur];
			if (curNodeLevel == curLevel)  //当前的层是我所统计的层
			{
				curLevelNodes++;
			}
			else   //当前遍历的层不是我要统计层,即当前节点已经来到第n+1层，而我仍然在统计第n层，此时就要将第n层的数据与max做比较取较大值后开始统计第n+1层
			{
				max = max > curLevelNodes ? max : curLevelNodes;
				curLevel++;
				curLevelNodes = 1;  //因为在节点第一次换层时节点已经弹出，上面if语句的内容不会执行,所以这里初始值应该设为1
			}
			if (cur->left != NULL)
			{
				qu->push(cur->left);
				levelMap->insert(make_pair(cur->left, curNodeLevel + 1));
			}
			if (cur->right != NULL)
			{
				qu->push(cur->right);
				levelMap->insert(make_pair(cur->right, curNodeLevel + 1));
			}
				
		}
		delete qu;
		return max > curLevelNodes ? max : curLevelNodes;  //最后要加上与最后一层的比较，因为最后一层不会进入到If语句中去
	}

	//关于二叉树的一些判断问题
	//判断是否是搜索二叉树（左子树的所有节点都比根节点小，右子树的所有节点都比根节点大的树）
	bool isBST(Node* head, int& preValue = int_min)  //搜索二叉树中序遍历出来后必然不降序
	{
		if (head == NULL)
			return true;
		bool isLeftBst = isBST(head->left);
		if (!isLeftBst) 
			return false;
		if (head->value < preValue)
			return false;
		else
		{
			preValue = head->value;
		}
		return isBST(head->right);
	}

	bool isCBT(Node* head)  //判断是否为完全二叉树，采用宽度优先遍历
	{
		if (head == NULL)
			return true;
		queue<Node*>* qu = new queue<Node*>;
		bool leaf = false;  //是否遇到过左右两个孩子不双全的节点，默认设为无
		Node* l = NULL;
		Node* r = NULL;
		qu->push(head);
		while (!qu->empty())
		{
			head = qu->front();
			qu->pop();
			l = head->left;
			r = head->right;
			if ((leaf && (l != NULL || r != NULL)) || (l == NULL && r != NULL))  //如果遇到了不双全的节点，又发现当前节点不是叶节点
				return false;

			if (l != NULL)
				qu->push(l);
			if (r != NULL)
				qu->push(r);
			if (l == NULL || r == NULL)  //左右孩子不双全，后续节点因全为叶子节点，只有false改true的操作
				leaf = true;
		}
		delete qu;
		return true;	
	}

	bool isBalabced(Node* head)   //判断是否是平衡二叉树
	{
		ReturnType* rs = process(head);  //这么写是为了防止内存泄露
		bool result = rs->isBalanced;
		delete rs;
		return result;
	}
	class ReturnType   //定义返回类型
	{
	public:
		bool isBalanced;
		int height;
		ReturnType(bool isB, int hei)
		{
			isBalanced = isB;
			height = hei;
		}

	};
	ReturnType* process(Node* X)
	{
		if (X == NULL)
			return new ReturnType(true, 0);
		ReturnType* leftData = process(X->left);
		ReturnType* rightData = process(X->right);

		int height = (leftData->height > rightData->height ? leftData->height : rightData->height) + 1;
		bool isBalanced = leftData->isBalanced && rightData->isBalanced && abs(leftData->height - rightData->height) < 2;
		delete leftData;   //递归行为极易造成内存泄露，一定要找到合适的时机将其释放
		delete rightData;
		return new ReturnType(isBalanced, height);
	}
	

	//二叉树的其他问题
	Node* lowerstAncestor(Node* head, Node* o1, Node* o2)  //返回最低公共祖先问题，给定一颗二叉树的两个节点，返回他们往上第一次相遇的节点，他们之间也可能互为最低公共祖先
	{
		if (head == NULL || head == o1 || head == o2)
			return head;  //如果head就是o1或o2，他就将自己往上返回。
		Node* left = lowerstAncestor(head->left, o1, o2);  //如果不是，他就向他的左树和右树要答案
		Node* right = lowerstAncestor(head->right, o1, o2);
		if (left != NULL && right != NULL)  //如果左树和右树给他的答案都不为空，这时就意味着o1和o2一定分别在他的左右子树上，那么他们也就时在此时的head处相遇,此时就将他们相遇的head也就是最终答案往上返回
			return head;
		return left != NULL ? left : right;   //如果有一边为空，就返回不为空的那一边，如果在这颗字树上既没有o1也没有o2那么这颗子树就向上返回空.

	}

	//给你一个特殊的带有父指针的二叉树（头节点的父指针指向空），请你找到某一个节点的后继节点（也就是中序中该节点的下一个节点），但是要求只走这个两个节点之间的距离步，因此不能使用中序遍历得到所有节点中序列表在寻找的方法（该方法时间复杂度O（N））。
	class Node1
	{
	public:
		int value;
		Node1* left;
		Node1* right;
		Node1* parent;
		Node1(int val)
		{
			value = val;
		}
	};
	Node1* getSuccessorNode(Node1* node)
	{
		if (node == NULL)
			return node;
		if (node->right != NULL)  //如果他的右子树不为空那么他的后继节点一定是他右字树的最左边的节点
			return getLeftMost(node->right);
		else  //没有右子树
		{
			Node1* parent = node->parent;
			while (parent != NULL && parent->left != node) //当前节点有父亲并且他不是父亲的左孩子，也就是说他是他父亲的右孩子
			{
				node = parent;  //他们两个往上窜
				parent = node->parent;
			}
			return parent;  //退出循环的条件，当他是他父亲的左孩子时，他的后继节点就是他的父亲，当他的父节点为空时他就时中序的最后一个节点，那么他的后继就也为空
		}
	}

	Node1* getLeftMost(Node1* node)
	{
		while (node->left!=NULL)
		{
			node = node->left;
		}
		return node;
	}


	//二叉树的序列化与反序列化
	string serialByPre(Node* head)   //给定二叉树的头，将二叉树的信息按照字符串返回，此处采用先序遍历，得到的结果可以通过文件操作保存
	{
		if (head == NULL)
			return "#_";  //采用#表示空，每一个信息后接_表示结束
		string res = head->value + "_";
		res += serialByPre(head->left);
		res += serialByPre(head->right);
		return res;
	}
	Node* reconByPreString(string prestr)  //解析一个字符串，还原出二叉树
	{
		vector<string> values = split(prestr);
		queue<string>* qu = new queue<string>;
		for (int i = 0; i < values.size(); i++)
		{
			qu->push(values[i]);
		}
		return reconPreOrder(qu);
	}
	Node* reconPreOrder(queue<string>* qu)
	{
		string value = qu->front();
		qu->pop();
		if (value == "#")
			return NULL;
		Node* head = new Node(stod(value));
		head->left = reconPreOrder(qu);
		head->right = reconPreOrder(qu);
		return head;
	}
	vector<string> split(string s, char c = '_')
	{
		s += c;
		vector<string> ret;
		string t = "";
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == c)
			{
				ret.push_back(t); 
				t = "";
			}
			else
				t += s[i];
		}
		return ret;
	}


	void deleteTree(Node* head)   //销毁树
	{
		if (head == NULL)
			return;
		deleteTree(head->left);
		deleteTree(head->right);
		delete head;
	}


	//微软面试问题：纸条折叠n次，每次折叠并展开时保持相同的一端，求打印n次后纸条自上而下的凸凹顺序
	void printAllFolds(int N)
	{
		printProcess(1, N, true);   //true表示凹，false表示凸
	}
	void printProcess(int i, int N, bool down)  //i是当前节点的层数，N是总共的折叠层数
	{
		if (i > N)
			return;
		printProcess(i + 1, N, true);  //折两次上面是凹折痕
		cout << (down ? "凹" : "凸" )<< endl;
		printProcess(i + 1, N, false);
	}



	void morris(Node* head)   //morris遍历
	{
		if (head == NULL)
			return;
		Node* cur = head;
		Node* mostRight = NULL;
		while (cur != NULL)
		{
			mostRight = cur->left;    //mostRight是cur的左孩子
			if (mostRight != NULL)    //cur有左孩子
			{
				while (mostRight->right != NULL && mostRight->right != cur)  //while跑完，mostRight来到cur左子树上的最右节点
				{
					mostRight = mostRight->right;
				}
				if (mostRight->right == NULL)   //这是第一次来到cur
				{
					mostRight->right = cur;   //将叶子指针指回cur
					cur = cur->left;    //cur向左移动
					continue;   //回到while循环继续
				}
				else     //mostRight->right==cur   第二次来到cur
				{
					mostRight->right = NULL;   //将指针复原
				}

			}
			cur = cur->right;   //如果cur没有左子树，或者第二次来到cur后，向右移动
		}
	}
	
	void test01_1()
	{
		//char arr[] = { 1,2,4,'#','#',5,'#','#',3,9,'#','#','#' };
		char arr[] = { 4,2,1,'#','#',3,'#','#',5,9,'#','#','#'};
		//char arr[] = { 1,2,4,4,'#','#','#','#',3,'#','#' };
		int index = 0;
		Node* head;
		preOrderCreat(head, arr, index);
		cout << "先序：" << endl;
		preOrderRecur(head); 
		cout << endl << "中序：" << endl;
		inOrderRecur(head);
		cout << endl << "后序：" << endl;
		posOrderRecur(head);
		cout << endl << "非递归先序：" << endl;
		preOrderUnRecur(head);
		cout << endl << "非递归中序：" << endl;
		inOrderUnRecur(head);
		cout << endl << "非递归后序：" << endl;
		posOrderUnRecur1(head);
		cout << endl << "宽度优先遍历：" << endl;
		widthTravel(head);
		cout << endl << "这棵树的节点最多那层的节点数是：" << getMaxWidthNodes(head) << endl;
		if (isBST(head))
			cout << "这颗树是搜索二叉树" << endl;
		else
		{
			cout << "这棵树不是搜索二叉树" << endl;
		}
		if (isCBT(head))
			cout << "这棵树是完全二叉树" << endl;
		else
		{
			cout << "这棵树不是完全二叉树" << endl;
		}
		if (isBalabced(head))
		{
			cout << "这棵树是平衡二叉树" << endl;
		}
		else
		{
			cout << "这棵树不是平衡二叉树" << endl;
		}
		deleteTree(head);
	}

	void test01_2()
	{
		int N = 3;
		printAllFolds(N);
	}

};