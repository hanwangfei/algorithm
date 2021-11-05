#pragma once
#include<iostream>
using namespace std;
#include<string>
class Kmp
{
public:
	int getIndexOf(string s, string m)  //在s中找出一个字串与m相同，返回他在s中的首位置
	{
		if (s == "" || m == "" || m.length() < 1 || s.length() < m.length())
		{
			return -1;
		}
		int* next = getNextArray(m);
		int i1 = 0;   //i1是在大字符串s中的位置
		int i2 = 0;   //i2是在小字符串m中的位置
		while (i1 < s.length() && i2 < m.length())
		{
			if (s[i1] == m[i2])
			{
				i1++;
				i2++;
			}
			else if (next[i2] == -1)   //等效与i2==0,也就是i2来到了小字符串的首位置，没有办法前移了，此时只有大字符串后移
			{
				i1++;
			}
			else
			{
				i2 = next[i2];
			}
		}
		delete[] next;
		return i2 == m.length() ? i1 - i2 : -1;
	}


	int* getNextArray(string ms)
	{
		if (ms.length() == 1)
			return new int[] {-1};
		int* next = new int[ms.length()];//加4防止缓冲区溢出
		next[0] = -1;
		next[1] = 0;

		int i = 2;  //next数组的位置
		int cn = 0;  //哪个位置的信息和i-1的信息比
		while (i < _msize(next) / sizeof(next[0]))
		{
			if (ms[i - 1] == ms[cn])
			{
				next[i++] = ++cn;
			}
			else if (cn > 0)  //当前cn位置的信息和i-1位置的信息不一致
			{
				cn = next[cn];
			}
			else
			{
				next[i++] = 0;
			}
		}
		return next;
	}

	void test()
	{
		string str1 = "abcdcde";
		string str2 = "cd";
		cout << getIndexOf(str1, str2) << endl;
	}

};
