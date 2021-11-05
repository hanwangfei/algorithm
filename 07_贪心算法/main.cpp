//贪心算法：在某一个标准下，优先考虑最满足标本的样本，最后考虑最不满足标准的样本，最终得到一个答案的算法，叫做贪心算法
//注意，很多情况下贪心算法要找的是优良解而不是最优解，因为很多情况局部最优无法推出整体最优
#include"会议安排问题.h"
void test()
{
	BestProgram b;
	vector<Program> p;
	p.push_back(Program(6, 7));
	p.push_back(Program(6, 8));
	p.push_back(Program(8, 13));
	p.push_back(Program(14, 16));
	p.push_back(Program(15, 16));
	p.push_back(Program(17, 18));
	cout << b.bestArrange(p, 6) << endl;
	
}
int main()
{
	test();
	return 0;
}