#include <iostream>
using namespace std;

class Test
{
public:
	Test() { this->a = 1; }
	int a;
};

void func(Test **a)
{
	*a = new Test();
}

int main()
{
	Test *a = NULL;
	func(&a);
	cout << a->a << endl;
	system("pause");
	return 0;
}