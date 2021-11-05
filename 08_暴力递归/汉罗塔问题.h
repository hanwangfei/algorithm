#pragma once
#include<iostream>
using namespace std;
#include<string>
//汉罗塔问题是指，有3个柱子，每个柱子上有N个大小均不相同的圆盘，如何将这些圆盘从一个柱子移动到另一个柱子上去，注意大圆盘不能压小圆盘，请打印出所有的移动路径
void hanLuoTa(int i, string start, string end, string other)
{
	if (i == 1)//base case
	{
		cout << "Move 1 from " << start << " to " << end << endl;
	}
	else
	{
		hanLuoTa(i - 1, start, other, end);  //先将i-1个圆盘从start移动到other上去
		cout << "Move " << i << " form " << start << " to " << end << endl;
		hanLuoTa(i - 1, other, end, start);  //再将i-1个圆盘从other移动到end上区，最后将最小的那一个从start移动到end上去
	}

}
void test1()
{
	int n = 3;
	hanLuoTa(n, "左", "右", "中");
}