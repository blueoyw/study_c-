#include <iostream>
#include <functional>
using namespace std;

typedef int(*cFunc)(int);
typedef function<int(int)> Func2;

int print(int a )
{
	cout << a << endl;
	return a;
}

class Functor
{
public:
	Functor(int x):_x(x) {}

	void operator()(){ cout << _x << endl; }

	int _x;
};

int main() 
{
	cout << "c_style" << endl;
	cFunc f1 = &print;
	f1(1);

	cout << "c++_style" << endl;
	Func2 f2 = move(print);
	f2(2);

	cout << "Functor class" << endl;
	Functor functor(3);
	functor();

	cout << "lambda" << endl;
	auto Func4 = [](int x) void { cout<<x<<endl; };
	Func4(4);
	return 0;
}
