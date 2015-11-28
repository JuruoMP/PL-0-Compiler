#include <iostream>
using namespace std;

class Test
{
public:
	static int s;
	int a;
	Test() {};
	Test(int n)
	{
		a = n;
	}
}a, b;
int Test::s = 1;

int main()
{
	a.s++;
	cout << a.s << endl;
	b.s++;
	cout << b.s << endl;
	system("pause");
	return 0;
}