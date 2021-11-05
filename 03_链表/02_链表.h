#pragma once
#include<iostream>
using namespace std;
#include<stack>

class List
{
public:
	struct Node {
		int value;
		Node* next;
	};
	
	void creatList(Node* head, int length) //不带头节点，采用尾插法
	{
		head->value = 0;
		Node* p = head;
		for (int i = 1; i < length; i++)
		{
			Node* newNode = new Node;
			newNode->value = i;
			newNode->next = NULL;
			p->next = newNode;
			p = newNode;
			
		}
	}
	void creatList(Node* head, int length, int* a)   //重载一种根据给定数组数据创建链表的方法
	{
		head->value = a[0];
		head->next = NULL;
		Node* p = head;
		for (int i = 1; i < length; i++)
		{
			Node* newNode = new Node;
			newNode->value = a[i];

			newNode->next = NULL;
			p->next = newNode;
			p = newNode;

		}


	}
	void printList(Node* head)  //打印链表
	{
		Node* p = head;
		while (p != NULL)
		{
			cout << p->value << "\t";
			p = p->next;
		}
		cout << endl;
	}
	void deleteList(Node* head)  //销毁链表
	{
		Node* p = head;
		Node* pNext = p->next;
		while (pNext != NULL)
		{
			delete p;
			p = pNext;
			pNext = p->next;
		
		}
		delete p;
		p = NULL;
		head = NULL;
	}

	void reverseList(Node* &head) //反转链表 //采用引用的方式，就不需要一定返回Node*,可以返回void,从而使得函数调用更简便
	{
		Node* p = head;
		Node* pNext = head->next;
		Node* temp;  //准备三个连续的指针
		p->next = NULL;
		while (pNext!=NULL)
		{
			temp = pNext->next;
			pNext->next = p;
			p = pNext;
			pNext = temp;
		}
		head = p;
	}

	//链表回文结构判断
	bool isPalindrome1(Node* head)  //第一种方法，直接用栈
	{
		if (head->next == NULL || head == NULL)
			return true;
		stack<Node*> sta;
		Node* p = head;
		while (p!=NULL)
		{
			sta.push(p);
			p = p->next;
		}
		
		while (head != NULL)
		{
			if (head->value != sta.top()->value)
				return false;
			sta.pop();
			head = head->next;
		}
		return true;
	}
	
	bool isPalindrome2(Node* head)  //第二种方法用快慢指针找到中点然后只将后一半入栈进而节省空间
	{
		if (head == NULL || head->next == NULL)
			return true;
		Node* right = head;
		Node* p = head;
		while (right->next != NULL && right->next->next != NULL)
		{
			right = right->next->next;
			p = p->next;
		}
		stack<Node*> sta;
		p = p->next;
		while (p != NULL)
		{
			sta.push(p);
			p = p->next;
		}
		while (!sta.empty())  //这里的head放心使用，因为他是copy来的一份，此处的head发生移位并不会影响原来的head，但是如果用这个head的指向改变了链表结构，则原链表结构必然发生改变
		{
			if (head->value != sta.top()->value)
			{
				return false;
			}
			sta.pop();
			head = head->next;

		}
		return true;

	}

	bool isPalindrome3(Node* head)  //第三种方法将后半部分逆序然后从两边往中间走判断是否一样,这种方法只需要有限几个变量，是三种方法在面试情况下的最优解
	{
		if (head == NULL || head->next == NULL)
			return true;
		Node* q = head; //快指针
		Node* p = head; //慢指针
		while (q->next != NULL && q->next->next != NULL)
		{
			q = q->next->next;
			p = p->next;
		}
		p = p->next;

		q = p->next;
		p->next = NULL;
		Node* temp;
		while (q != NULL)
		{
			temp = q->next;
			q->next = p;
			p = q;
			q = temp;
		}
		q = p;   //保存最后一个位置

		bool res = true;
		while (head != NULL && p != NULL)
		{
			if (head->value != p->value)
			{
				res = false;
				break;
			}
			head = head->next;
			p = p->next;
		}

		p = q->next;
		q->next = NULL;
		//复原链表,有用指针只有q
		while (p != NULL)
		{
			temp = p->next;
			p->next = q;
			q = p;
			p = temp;
		}
		return res;
	}

	Node* getLoopNode(Node* head)  //判断一个链表是否有环，若没有返回空，若有环返回第一个入环节点
	{
		if (head == NULL || head->next == NULL || head->next->next == NULL)
			return NULL;
		Node* slow = head->next;  //慢指针
		Node* fast = head->next->next;  //快指针
		while (slow!=fast)
		{
			if (fast->next == NULL || fast->next->next == NULL)
				return NULL;
			slow = slow->next;
			fast = fast->next->next;
		}
		//两个节点相遇后，让快指针回到头节点并且一次走一步，慢指针留在原地继续一次走一步，则他们下一次相遇的节点一定是第一个入环节点，该结论有图论证得。
		fast = head;
		while (slow != fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;  //或者return slow都行
	}

	//若一个链表有环，一个链表无环，则它们必然不可能相交
	Node* noLoop(Node* head1, Node* head2)    //求两个无环链表的第一个相交节点
	{
		if (head1 == NULL || head2 == NULL)
			return NULL;
		Node* cur1 = head1;
		Node* cur2 = head2;
		int n = 0;
		while (cur1->next != NULL)
		{
			n++;
			cur1 = cur1->next;
		}
		while (cur2->next != NULL)
		{
			n--;
			cur2 = cur2->next;
		}
		if (cur1 != cur2)    //两个链表的最后一个节点地址不同
			return NULL;     //必不可能相交
		
		cur1 = n > 0 ? head1 : head2;   //谁长，谁的头变cur1
		cur2 = cur1 == head1 ? head2 : head1;  //另一个为cur2
		n = n > 0 ? n : -n;
		while (n != 0)
		{
			n--;
			cur1 = cur1->next;
		}
		while (cur1!=cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}

	Node* bothLoop(Node* head1, Node* loop1, Node* head2, Node* loop2)  //两个有环链表相交问题，提供两个头节点和各自的第一个入环节点
	{
		Node* cur1 = NULL;
		Node* cur2 = NULL;
		if (loop1 == loop2)
		{
			cur1 = head1;
			cur2 = head2;
			int n = 0;
			while (cur1 != loop1)
			{
				n++;
				cur1 = cur1->next;
			}
			while (cur2 != loop2)
			{
				n--;
				cur2 = cur2->next;
			}
			cur1 = n > 0 ? head1 : head2;
			cur2 = cur1 == head1 ? head2 : head1;
			n = n > 0 ? n : -n;
			while (n != 0)
			{
				n--;
				cur1 = cur1->next;
			}
			while (cur1 != cur2)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			return cur1;
		}
			
		else
		{
			cur1 = loop1->next;
			while (cur1 != loop1)
			{
				if (cur1 == loop1)
					return loop1;
				cur1 = cur1->next;
			}
			return NULL;
		}

	}

	

	void test02_1()
	{
		Node* head = NULL;
		head = new Node;
		
		int length = 10;
		creatList(head, length);
		printList(head);
		deleteList(head);

		head = new Node;  //原head被delete掉了，所以此处必须重新申请
		int arr[10] = { 10,20,66,10,31,1,5,45,5,4 };
		creatList(head, length, arr);
		printList(head);
		reverseList(head);
		printList(head);
		deleteList(head);
	}

	void test02_2()
	{
		Node* head = new Node;
		int length = 8;
		int arr[] = { 2,1,10,8,8,10,1,2 };
		creatList(head, length, arr);
		printList(head);
		if(isPalindrome3(head))
		{
			cout << "这是一个回文结构" << endl;
		}
		else
		{
			cout << "这不是一个回文结构" << endl;
		}
		printList(head);
		deleteList(head);
	}

};
