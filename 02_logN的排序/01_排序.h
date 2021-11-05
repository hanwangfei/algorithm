#pragma once
#include<iostream>
using namespace std;
#include<math.h>

class test1
{
public:
	int* generateRandomArray(int maxSize, int maxValue) //创建一个对数器用于测试数据，得到大小随机，值随机的数组
	{
		srand(time(NULL));
		int length = rand() % maxSize + 1;
		int* arr = new int[length]; //为数组分配不大于maxsize的任意空间
		for (int i = 0; i < length; i++)
		{
			arr[i] = (rand() % (2 * maxValue + 1)) -maxValue;
		}
		return arr;
	}

	void printArr(int* a, int length)
	{
		for (int i = 0; i < length; i++)
		{
			cout << a[i] << "\t";
		}
		cout << endl;
	}

	void mergeSort(int* arr, int L, int R)  //归并排序  由master公式得T(N) = 2T(N/2)+O(N),得a=2,b=2,d=1,logab==d,所以该排序时间复杂度为O(N*logN),但额外空间复杂度为O(N)  
	{ 
		if (L == R)
			return;
		int mid = L + ((R - L) >> 1);   //取中点
		mergeSort(arr, L, mid);   //左侧排好序
		mergeSort(arr, mid + 1, R);  //右侧排好序
		merge(arr, L, mid, R);   //左右侧合并
	}
	void swap(int& a, int& b)  //这里不能用异或交换，因为下面过程有很多自己和自己交换，用异或会将他们抹为0
	{
		int temp = a;
		a = b;
		b = temp;
	} 


	void merge(int* arr, int L, int M, int R)
	{
		int length = R - L + 1;
		int* help = new int[length + 4];  //额外开辟4个空间防止缓冲区溢出
		int i = 0;
		int p1 = L; 
		int p2 = M + 1;
		while (p1 <= M && p2 <= R)   //p1、p2都不越界
		{
			help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];  //谁小拷贝谁
		}
		while (p1 <= M)   //两个while只会中一个，将剩下的拷贝给help
		{
			help[i++] = arr[p1++];
		}
		while (p2 <= R)
		{
			help[i++] = arr[p2++];
		}
		for (int i = 0; i < length; i++)
		{
			arr[L + i] = help[i];
		}
		delete[] help;
	}

	void quickSort(int* arr, int L, int R)  //当选定num为最大或最小时出现最坏情况，算法复杂度为0(N^2)，当选定num为正中间值时出现最好情况，算法复杂度为O(N*logN），由于采用等概率取num,所以每种情况都是1/N概率，根据数学统计，该算法最终时间复杂度定为O(N*logN)
	{
		if (L < R)
		{
			swap(arr[L + rand() % (R - L + 1)], arr[R]);  //随机选择一个位置与最右侧位置交换 
			int* p = partition(arr, L, R);  //得到划分值的左边界和右边界
			quickSort(arr, L, p[0] - 1);  //在小于区域递归
			quickSort(arr, p[1] + 1, R);  //在大于区域递归
		}

	}
	int* partition(int* arr, int L, int R)
	{
		int less = L - 1;  //小于区域右边界
		int more = R;  //大于区域左边界
		while (L < more)
		{
			//L表示当前数的位置，arr[R]为划分值
			if (arr[L] < arr[R])
			{
				//当前数小于划分值
				swap(arr[++less], arr[L++]);
			}
			else if (arr[L] > arr[R])
			{
				swap(arr[--more], arr[L]);
			}
			else
			{
				L++;
			}

		}
		swap(arr[more], arr[R]);
		int* rs = new int[2];
		rs[0] = less + 1;
		rs[1] = more;
		return rs;
	}

	//完全二叉树有N个节点，其高度为logN级别
	void heapInsert(int* arr, int index)   //上升过程,将一个较大值调整使得原数组仍然保持大根堆
	{ 
		while (arr[index] > arr[(index - 1) / 2])
		{
			swap(arr[index], arr[(index - 1) / 2]);
			index = (index - 1) / 2;  //转到父位置继续，直到达到大根堆
		}
	} 

	void heapify(int* arr, int index, int heapSize)  //下潜过程
	{
		int left = index * 2 + 1;  //左孩子的下标
		while (left < heapSize)  //下方还有孩子的时候
		{
			//两个孩子中，谁的值大，吧下标给largest
			int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
			//父亲和较大孩子之间再次比较，将最大值的下标给largest
			largest = arr[largest] > arr[index] ? largest : index;
			if (largest == index)   //父亲节点更大，下潜结束
			{
				break;
			}
			swap(arr[largest], arr[index]);  //将父亲节点和较大节点的值交换
			index = largest;   //index来到较大子节点的位置继续下潜行为
			left = index * 2 + 1;  //更新左孩子下标，进入下一次循环
		}
	}

	void heapSort(int* arr, int length)   //堆排序,事件复杂度O（N*logN),空间复杂度O(1)
	{
		if (arr == NULL || length < 2)
			return;
		for (int i = 0; i < length; i++)
		{
			heapInsert(arr, i);  //O(logN)  
		}
		int heapSize = length;
		swap(arr[0], arr[--heapSize]);
		while (heapSize > 0) //O(N）
		{
			heapify(arr, 0, heapSize);    //O(logN)
			swap(arr[0], arr[--heapSize]);
		}
	}


	int maxbits(int* arr, int length)   //得到一个数组中最大的位数,即最大值有多少个10进制位
	{
		int max = arr[0];
		for (int i = 0; i < length; i++)
			max = max > arr[i] ? max : arr[i];
		int res = 0;
		while (max)
		{
			res++;
			max /= 10;
		}
		return res;

	}
	void radixSort(int* arr,int length)   //基排序入口，注意不是递归
	{
		if (arr == NULL || length < 2)
			return;
		radixSort(arr, 0, length - 1, maxbits(arr,length));

	}
	int getDigit(int x, int d)   //返回一个数x的第几位是谁
	{
		return ((x / ((int)pow(10, d - 1))) % 10);

	}
	void radixSort(int* arr, int L, int R, int digit)  //基数排序，按照位数出桶入桶，从而实现有序，此处堆排出现负数会出现问题
	{
		const int radix = 10;  //此处主要讨论10进制的数
		int i = 0, j = 0;
		int* bucket = new int[R - L + 1];  //有多少个数就准备多少的辅助空间
		for (int d = 1; d <= digit; d++)  //有多少位就进出桶多少次
		{
			int* count = new int[radix];   //cout[0.....9]
			for (i = 0; i < radix; i++)    //注意这个步骤很有必要，必须要先保证没个数所对应的个数为0
				count[i] = 0;
			for ( i = L; i <= R; i++)
			{
				j = getDigit(arr[i], d);
				count[j]++;
			}
			for (i = 1; i < radix; i++)
			{
				count[i] = count[i] + count[i - 1];  //将没个数的和变为小于等于这个数的和
			}
			for (i = R; i >= L; i--)   //从右往左遍历
			{
				j = getDigit(arr[i], d);
				bucket[count[j] - 1] = arr[i];
				count[j]--;
			}
			for (i = L, j = 0; i <= R; i++, j++)
			{
				arr[i] = bucket[j];  //将辅助空间的数据导入原数组，此时该位次的排序（入桶出桶）已完成
			}

		}
	}


	void test01_1()
	{
		int* a = generateRandomArray(15, 30);
		int length = _msize(a) / sizeof(a[0]);
		cout << "数组长度为：" << length << endl << endl;
		printArr(a, length);
		//注意数组下标是从0开始的,下面的归并排序与快速排序的两个参数分别为从左下标到右下标有序，所以如果要全有序应填length-1，但堆排序只有一个参数就是数组的元素个数，不代表下标，所以直接传length
		//mergeSort(a, 0, length - 3);
		//quickSort(a, 0, length-);   
		heapSort(a, length);  //堆排序中的length就是数组的元素个数
		printArr(a, length);
	}

	void test01_2()
	{
		int a[8] = { 4,30,100,39,20,1002,1030,900 };
		printArr(a, 8);
		radixSort(a, 8);
		printArr(a, 8);
		//cout << getDigit(109, 3) << endl;
		//cout << maxbits(a, 5) << endl;
	}
};
