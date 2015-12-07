
int fact(int *n)
{
	int m = 1;
	return m;
}

int main()
{
	int a = 0xaaaaaaaa;
	a = fact(&a);
	return 0;
}