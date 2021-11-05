#pragma once
//判断一个32为整数是不是2的某次幂？4的某次mi？
#include<iostream>
using namespace std;
bool is2Power(int n)
{
	return (n & (n - 1)) == 0;
}

bool is4Power(int n)
{
	return (n & (n - 1)) == 0 && (n & 0x55555555) != 0;  //首先这个数一定是二的幂，其次这个数的1一定出现在偶数位上，那么它与上....101010101 一定不等与0
}
void test2()
{
	cout << is4Power(16) << endl;
	
}