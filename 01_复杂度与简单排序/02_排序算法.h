#pragma once
#include<iostream>
#include"01_异或巧用.h"
using namespace std;
#include<math.h>
#include<time.h>

class test2:public test1
{
public:
	int* generateRandomArray(int maxSize, int maxValue) //创建一个对数器用于测试数据，得到大小随机，值随机的数组
	{
		srand(time(NULL));
		int length = rand() % maxSize + 1;
		int* arr = new int[length]; //为数组分配不大于maxsize的任意空间
		for (int i = 0; i < length; i++)
		{
			arr[i] =(rand() % (2 * maxValue + 1)) - maxValue;
		}
		return arr;
	}

	void printArr(int* arr, int length)
	{
		for (int i = 0; i < length; i++)
			cout << arr[i] << "\t";
		cout << endl;
	}

	void insertSort(int* arr, int length)  //插入排序，O（n^2）  但其最好情况为O(n),所以该算法一般优于冒泡排序和选择排序
	{
		if (arr == NULL || length < 2)
			return;
		for (int i = 0; i < length; i++)  //想做到0-i有序
		{
			for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
			{
				swap(arr[j], arr[j + 1]);
			}
		}

	} 
	
	int getMax(int* arr, int L, int R) //使用递归与二分法求一个数组指定范围内的最大值
	{
		if (L == R)
			return arr[L];
		int mid = L + ((R - L) >> 1);  //右移一位在除了负奇数的情况下等于除二 
		int leftMax = getMax(arr, L, mid);
		int rightMax = getMax(arr, mid + 1, R);
		return (leftMax > rightMax ? leftMax : rightMax);
	}

	void test02_1() 
	{
		int* a = generateRandomArray(20,50);  //生成随机动态数组，长度随机，值也随机
		int length = _msize(a) / sizeof(a[0]);
		cout << "数组长度为：" << length << endl << endl;
		printArr(a, length);
		insertSort(a, length);
		printArr(a, length);
		delete[] a;  //释放数组空间
	}  
	
	void test02_2()
	{
		int a[] = { 102,99,101,53,2,5,25,54,98,53 };
		cout << getMax(a, 2, sizeof(a) / sizeof(a[0])); 
	}

	 
};
