#include"01_二叉树.h"


void test()
{
	Tree* t = new Tree;
	char arr[] = { 4,2,1,'#','#',3,'#','#',5,9,'#','#','#' };
	Node* head;
	int i = 0;
	t->preOrderCreat(head, arr, i);
	cout << "先序：" << endl;
	t->preOrderRecur(head);
	cout << endl << "中序：" << endl;
	t->inOrderRecur(head);
	cout << endl << "后序：" << endl;
	t->posOrderRecur(head);
	cout << endl << "非递归先序：" << endl;
	t->preOrderUnRecur(head);
	cout << endl << "非递归中序：" << endl;
	t->inOrderUnRecur(head);
	cout << endl << "非递归后序：" << endl;
	t->posOrderUnRecur1(head);
	cout << endl << "宽度优先遍历：" << endl;
	t->widthTravel(head);
	cout << endl << "这棵树的节点最多那层的节点数是：" << t->getMaxWidthNodes(head) << endl;
	if (t->isBST(head))
		cout << "这颗树是搜索二叉树" << endl;
	else
	{
		cout << "这棵树不是搜索二叉树" << endl;
	}
	if (t->isCBT(head))
		cout << "这棵树是完全二叉树" << endl;
	else
	{
		cout << "这棵树不是完全二叉树" << endl;
	}
	if (t->isBalabced(head))
	{
		cout << "这棵树是平衡二叉树" << endl;
	}
	else
	{
		cout << "这棵树不是平衡二叉树" << endl;
	}
	t->deleteTree(head);
	
}
int main()
{
	//Tree().test01_1();
	//Tree().test01_2();
	
	return 0;
}
