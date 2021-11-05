#pragma once
//有N个位置，机器人从S走到E，要求机器人必须走K步，问有多少种走法，已知N>1
#include<iostream>
using namespace std;
#include<vector>

//暴力尝试方法
int f1(int N, int E, int rest, int cur)  //rest指还剩rest步要走，cur指当前来到位置
{
	if (rest == 0)
	{
		return cur == E ? 1 : 0;  //base case
	}
	//否则说明还有路可以走
	if (cur == 1)    //1位置只能往右走来到2
	{
		return f1(N, E, rest - 1, 2);
	}
	if (cur == N)   //N位置智能往左走来到N-1
	{
		return f1(N, E, rest - 1, N - 1);
	}
	return f1(N, E, rest - 1, cur - 1) + f1(N, E, rest - 1, cur + 1);   //其他位置既可以往左走也可以往右走
}

//暴力尝试改记忆化搜索
int f2(int N, int E, int rest, int cur, vector<vector<int>>& dp)  //在调这个函数之前，先开一个dp[K,N]的数组并将其所有数据初始化为-1,这个dp就相当于一个缓存
{
	if (dp[rest][cur] != -1)
	{
		return dp[rest][cur];
	}
	//缓存没命中
	if (cur == 1)
	{
		dp[rest][cur] = f1(N, E, rest - 1, 2);
		return dp[rest][cur];
	}
	if (cur == N)
	{
		dp[rest][cur] = f1(N, E, rest - 1, N - 1);
		return dp[rest][cur];
	}

	dp[rest][cur] = f1(N, E, rest - 1, cur - 1) + f1(N, E, rest - 1, cur + 1);
	return dp[rest][cur];
}


//记忆化搜索根据依赖关系改动态规划，在本题种与记忆化搜索时间复杂度一样，都为O(k*n)
int f3(int N, int E, int rest, int cur, vector<vector<int>>& dp)
{
	if (dp[rest][cur] != -1)
	{
		return dp[rest][cur];
	}
	//缓存没命中
	if (rest == 0)
	{
		dp[rest][cur] = cur == E ? 1 : 0;
		return dp[rest][cur];
	}
	if (cur == 1)
	{
		dp[rest][cur] = f3(N, E, rest - 1, 2,dp);
	}
	else if (cur == N)
	{
		dp[rest][cur] = f3(N, E, rest - 1, N - 1,dp);
	}
	else
	{
		dp[rest][cur] = f3(N, E, rest - 1, cur - 1,dp) + f3(N, E, rest - 1, cur + 1,dp);

	}
	return dp[rest][cur];
}
void test1()
{
	
	int N = 5;
	int K = 4;
	int S = 2;
	int E = 4;
	vector<vector<int>> dp(K + 1, vector<int>(N + 1, -1));  //用N+1个-1去给每一列赋值，这样的一共有K+1行，最终二维数组全部赋值为-1
	cout << f3(N, E, K, S, dp);
}

