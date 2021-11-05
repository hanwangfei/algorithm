#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
//有一间会议室，例如可使用时间从6.00到18.00，现有一堆会议，找出一个方案，使得可安排的会议尽可能多

//贪心策略：结束时间越早越先安排
class Program
{
public:
	int start;
	int end;
	Program(int start, int end)
	{
		this->start = start;
		this->end = end;
	}
	bool operator<(Program p)
	{
		return this->end < p.end;  //比较器
	}
};
class BestProgram
{
public:
	int bestArrange(vector<Program>& p, int timePoint, int endPoint=18)  //第一个参数为会议数组指针，第二个参数为当前时间节点,第三个参数为会议室关门时间
	{
		sort(p.begin(), p.end());
		int result = 0;
		for (int i = 0; i < p.size(); i++)
		{
			if (timePoint <= p[i].start && p[i].end <= endPoint)
			{
				result++;
				timePoint = p[i].end;  //当前时间来到会议结束时间
			} 
		}
		return result; 
	}
	
};


