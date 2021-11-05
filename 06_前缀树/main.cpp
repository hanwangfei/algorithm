#include"TireTree.h"
void test1()
{
	TireTree t;
	t.insert("ab");
	cout << t.search("ab") << endl;
	//cout << t.prefixNumber("a") << endl;
	t.deleteTree("ab");
	cout << t.search("ab") << endl;
	t.insert("ab").insert("ab").insert("abc");
	cout << t.search("ab") << endl;
	cout << t.search("abc") << endl;

	


}
int main()
{
	//system("chcp 65001");
	cout << "什么鬼" << endl;
	cout << "有毛病吧" << endl;
	test1();
	return 0;
}