#pragma once
#include<iostream>
using namespace std;
#include<vector>
//假如给你一个硬币数组，全是正数，让你凑出aim块钱来，返回使用的最小硬币数量
int minCoin(vector<int>& arr, int index, int rest)   //index是当前来到的位置，rest表示离aim还差多少钱
{
	if (rest < 0)
		return -1;
	if (rest == 0)
		return 0;    //刚好完成目标
	if (index == arr.size())
		return -1;   //来到了最后一个硬币位置的下一个位置，此时已经没有硬币可供你选择了，你不可能完成任务
	//rest>0  并且你当前有硬币可以选择
	int p1 = minCoin(arr, index + 1, rest);  //不要当前硬币
	int p2Next = minCoin(arr, index + 1, rest - arr[index]);  //要当前硬币
	if (p1 == -1 && p2Next == -1)
		return -1;
	else
	{
		if (p1 == -1)
			return p2Next + 1;
		else if (p2Next == -1)
			return p1;
		else
		{
			return p1 < p2Next + 1 ? p1 : p2Next + 1;  //返回较小者
		}	
	}
}

//改记忆化搜索
int minCoin(vector<int>& arr, int index, int rest, vector<vector<int>>& dp)   //index是当前来到的位置，rest表示离aim还差多少钱
{
	if (rest < 0)
		return -1;   //无效区直接返回
	if (dp[index][rest] != -2)
		return dp[index][rest];
	if (rest == 0)
	{
		dp[index][rest] = 0;    //刚好完成目标
	}
	else if (index == arr.size())
	{
		dp[index][rest] = -1;
	}
	else
	{
		int p1 = minCoin(arr, index + 1, rest, dp);  //不要当前硬币
		int p2Next = minCoin(arr, index + 1, rest - arr[index], dp);  //要当前硬币
		if (p1 == -1 && p2Next == -1)
			dp[index][rest] = -1;
		else
		{
			if (p1 == -1)
				dp[index][rest] = p2Next + 1;
			else if (p2Next == -1)
				dp[index][rest] = p1;
			else dp[index][rest] = p1 < p2Next + 1 ? p1 : p2Next + 1;  //返回较小者
		}
	}	
	return dp[index][rest];
}  



void test2()
{
	vector<int> arr;
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(100);
	int aim = 5;
	cout << minCoin(arr, 0, aim) << endl;
	vector<vector<int>> dp(arr.size() + 1, vector<int>(aim + 1, -2));   //-2状态表示没算过
	//cout << minCoin(arr, 0, aim, dp) << endl;
}