#include <iostream>
using namespace std;

class Test
{
public:
	int a;
	Test(int n)
	{
		a = n;
	}
};

int main()
{
	Test a(1);
	cout << a.a << endl;
	Test a(2);
	cout << a.a << endl;
	return 0;
}