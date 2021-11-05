#pragma once
//利用位运算实现加减乘除
#include<iostream>
using namespace std;
//默认结果一定不溢出，如果a+b是溢出的，那么用户活该
int add(int a, int b)
{
	int sum = a;
	while (b!=0)
	{
		sum = a ^ b;  //无进位相加的结果
		b = (a & b) << 1;  //进位信息
		a = sum;
	}
	return sum;
}
int negNum(int n)   //取相反数
{
	return add(~n, 1);
}
int sub(int a, int b)
{
	return add(a, negNum(b));   //a-b=a+(-b)
}

int multi(int a, int b)   //乘法不能有负号，否则会出错，原因是下面注释处的无符号右移，在java中可以直接用<<<，但c++没有提供这个操作。解决方法：通过函数或重载实现<<<,或者在乘法前加几个判断，单独确定结果符号取向.
{
	int res = 0;
	while (b!=0)
	{
		if ((b & 1) != 0)
		{
			res = add(res, a);
		}
		a <<= 1;
		b >>= 1;   //这里应该用无符号右移

	}
	return res;
}
bool isNeg(int n)
{
	return n < 0;
}
//除法有问题
//int divs(int a, int b)  
//{
//	int x = isNeg(a) ? negNum(a) : a;
//	int y = isNeg(b) ? negNum(b) : b;
//	int res = 0;
//	for (int i = 31; i > -1; i = sub(i, 1))
//	{
//		if ((x >> i) >= y)
//		{
//			res |= (1 << i);
//			x = sub(x, y << i);
//		}
//		return isNeg(a) ^ isNeg(b) ? negNum(res) : res;
//
//	}
//}

void test3()
{
	cout << add(1,2) << endl;
	cout << sub(1, -1) << endl;
	cout << multi(5, 2) << endl;
}