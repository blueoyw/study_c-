#include <iostream>
using namespace std;

//num 번째 fibonacchi 수열을 반환.
//return fibonacchi number of index N.
int fibo( int n )
{
	if( n == 1 || n==2 )
		return 1;
	return fibo(n-1) + fibo(n-2);
}

int main(int argc, char** argv)
//int main(void)
{
	int num = 10;
	cout << fibo( num ) << endl;
}
