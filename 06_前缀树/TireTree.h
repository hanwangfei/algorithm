#pragma once
#include<iostream>
using namespace std;
#include<string>
class TireNode
{
public:
	int pass;  //这个节点经过的次数
	int end;  //以这个节点结尾的次数
	TireNode** nexts;  //这个节点下面的节点信息,这个指针指向26个节点指针

	TireNode()
	{
		pass = 0;
		end = 0;
		nexts = new TireNode * [26]{ NULL }; //代表26个字母 //如果字符种类不只26个，可以换成哈希表 map<char,node*> nexts;
	}
};
class TireTree
{
public:
	TireNode* root;  //根节点
	TireTree()
	{
		root = new TireNode;
	}

	TireTree& insert(string word)   //采用引用返回，实现链式编程
	{
		if (word == "")
			return *this;
		TireNode* node = root;
		node->pass++;
		int index = 0;
		for (int i = 0; i < word.size(); i++)
		{
			index = word[i] - 'a';   //由字符对应成走哪条路
			if (node->nexts[index] == NULL)  //如果没有走向这个节点的路
				node->nexts[index] = new TireNode;  //创建这条路
			node = node->nexts[index];   //node来到下面这个节点
			node->pass++;
		}
		node->end++;  //一个字符串走完，此时node所在的节点pass++
		return *this;
	}

	int search(string world)   //查询某个单词之前加入了几次
	{
		if (world == "")
			return 0;
		TireNode* node = root;
		int index = 0;
		for (int i = 0; i < world.size(); i++)
		{
			index = world[i] - 'a';
			if (node->nexts[index] == NULL)
			{
				return 0;   //没路了，说明这个单词没有出现过
			}
			node = node->nexts[index];
		}
		return node->end;
	}

	int prefixNumber(string pre)  //所有加入的字符串中，有几个是以pre这个字符串作为前缀的
	{
		if (pre == "")
			return NULL;
		TireNode* node = root;
		int index = 0;
		for (int i = 0; i < pre.size(); i++)
		{
			index = pre[i] - 'a';
			if (node->nexts[index] == NULL)
				return 0;
			node = node->nexts[index];
		}
		return node->pass;
	}

	void clear(TireNode*& node)  //注意这里一定要用引用传递这个指针，不然在这个递归函数中释放是正常的，也就是要释放的那个节点下的所有空间是正常释放的，但由于这里的node是一个备份的指针，在函数返回后，他的原指针是不变的，也就是说原指针不会是空指针，但他下面的内容又确实被释放了，因此是无法访问的，所以在后续一定会引发内存访问冲突
	{
		if (node == NULL)
			return;
		for (int i = 0; i < 26; i++)
		{
			if (node->nexts[i] != NULL)
				clear(node->nexts[i]);
		}
		delete node;
		node = NULL;  //这里一定要将指针赋空，不然就造成野指针从而引起内存访问冲突
	}
	void deleteTree(string world)
	{
		if (search(world) != 0)  //只有不等于0才释放，这里不建议写等于0返回，应为初始时这个节点应该为空
		{
			TireNode* node = root;
			node->pass--;
			int index = 0;
			for (int i = 0; i < world.size(); i++)
			{
				index = world[i] - 'a';
				if (--node->nexts[index]->pass == 0)
				{
					//遍历到底去析构
					clear(node->nexts[index]);
					return;
				}
				node = node->nexts[index];
			}
			node->end--;
		}
	}
};
