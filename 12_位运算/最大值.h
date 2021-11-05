#pragma once
#include<iostream>
using namespace std;
//返回a,b中的较大值，要求不适用比较
int flip(int n)    //请保证参数不是1就是0，实现0，1互换
{
	return n ^ 1;
}

//n是非负数，返回1，否则返回0
int sign(int n)
{
	return flip((n >> 31) & 1);
}

int getMax1(int a, int b)  //不考虑溢出的做法
{
	int c = a - b;
	int scA = sign(c);   //a-b为非负数，scA为1
	int scB = flip(scA);  //取互斥
	return a * scA + b * scB;  //scA与scB互斥，必然一个为0，一个为1
}

int getMax2(int a, int b)  //考虑溢出的方法
{
	int c = a - b;
	int sa = sign(a);
	int sb = sign(b);
	int sc = sign(c);
	int difSab = sa ^ sb;  //a和b的符号不一样为1，一样为0
	int sameSab = flip(difSab);  //a和b的符号一样为1，不一样为0
	int returnA = difSab * sa + sameSab * sc;  //返回a的条件，a和b的符号不一样并且a为非负数，或者a和b的符号一样但是a-b的符号（此时a-b一定不越界）为正，也就是a>b
	int returnB = flip(returnA);   //反面返回b
	return a * returnA + b * returnB;
}

void test1()
{
	cout << getMax2(-1, 0);
}
