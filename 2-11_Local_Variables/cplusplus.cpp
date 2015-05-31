#include <iostream>
using namespace std;

int global_var = 20;

void foo(int x, int y)
{
	cout << x << " " << y << " ";
}

int main()
{
	foo(5,10);
	cout << global_var << endl;

	return 0;
}