#pragma once
#include<iostream>
using namespace std;

class test1
{
public:
	//位运算巧用
	void swap(int& a, int& b)    //巧用异或运算节省空间开销，异或运算满足交换律和结合律，这么干的前提是两个变量所占用的内存不一致。他们的值可以相同，但内存地址不可以相同,否则会将这个内存的值抹除为0.
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	void printOddTimesNum1(int arr[], int length)  //找出一个数组中唯一一个出现奇数次的数
	{
		int eor = 0;
		for (int i = 0; i < length; i++)
		{
			eor ^= arr[i];
		}
		cout << eor << endl;

	}
	void printOddTimesNum2(int arr[], int length)   //一个数组只有两种不同数字出现奇数次，其余都是偶数次，求这两个数
	//算法思想，数组中的数可以在某一位上分为2种，为1或者为0，两个不同的数字a与b必然分别属于这两种，我们用eor异或所有的数得到的必然是a^b，此时的eor必然不等于0，假设他的第8为为1，则a与b的第8为必然不同。我们再用eor1异或所有第八位等于1的数，得到的必然是a或者b，在将eor与eor1异或，得到的必然是另一个数。
	{
		int eor = 0;
		for (int i = 0; i < length; i++)
		{
			eor ^= arr[i];  //eor得到a^b
		}
		int rightOne = eor & (~eor + 1);  //提取出一个数最右侧的1   //具体实现，将得到的eor与上一个eor取反加一后的结果

		int onlyOne = 0;  //也就是eor1
		for (int i = 0; i < length; i++)
		{
			if ((arr[i] & rightOne) == rightOne) //只有在某一位上与rightone相同均为1才参与与运算，且此时由于rightone其他位都是0，与出来的结果一定是rightone
				//此处写等于rightone或0都可以，只是为了分边，但要注意不能写1，因为如000001000的十进制并不是1
			{
				onlyOne ^= arr[i];
			}
		}
		int otherOne = onlyOne ^ eor;
		cout << onlyOne << "     " << otherOne << endl;

	}

	 
	void test01_1()
	{
		int a[] = { 1,2,99,2,2,2,1,0,0 };
		int length = sizeof(a) / sizeof(a[0]);
		printOddTimesNum1(a, length);

	}
	void test01_2()
	{
		int a[] = { 1,2,99,2,2,2,1,0,0,100,66,100,99,99,66,77 };
		int length = sizeof(a) / sizeof(a[0]);
		printOddTimesNum2(a, length);

	}


};

