#include "UnionFindSet.hpp"

void Test1()
{
	int array[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	UnionFindSet<int> ufs(array, sizeof(array) / sizeof(array[0]));

	ufs.link(1, 2);
	ufs.link(1, 3);
	ufs.link(3, 2);
	ufs.link(4, 5);
	ufs.link(5, 6);
	ufs.link(6, 7);
	ufs.link(9, 10);
	ufs.link(0, 10);

	cout << ufs.Size() << endl;

	system("pause");
}

int main()
{
	Test1();
}