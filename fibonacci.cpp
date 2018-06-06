#include <iostream>
#include <string.h>
#include <chrono>
using namespace std;

#define MAX 50
int memo[50];

//num 번째 fibonacchi 수열을 반환.
//return fibonacchi number of index N.
//O(2N)
int recursiveFibo( int n )
{
	if( n == 1 || n==2 )
		return 1;
	return recursiveFibo(n-1) + recursiveFibo(n-2);
}

//Dynamic Programming 
//memoization을 활용한다.
//O(N2)
int dpFibo( int n )
{
	if( n<= 1 )
		return n;
	if( memo[n] != 0 )  
		return memo[n];
	memo[n] = dpFibo(n-1) + dpFibo(n-2);
	return memo[n];
}

//loop
//O(N)
int loopFibo( int n)
{
	memo[0] =0 ;
	memo[1] =1 ;
	for( int i=2;i<n; i++ ) {
		memo[i] = memo[i-1] + memo[i-2];
	}
	return memo[n-1] + memo[n-2];
}

int main(int argc, char** argv)
//int main(void)
{
	memset( memo, 0x00, sizeof(memo) );

	int num = 30;
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	cout << recursiveFibo( num ) << endl;
	std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
	cout << "time=" << sec.count() << endl;

	start = std::chrono::system_clock::now();
	cout << dpFibo( num ) << endl;
	sec = std::chrono::system_clock::now() - start;
	cout << "time=" << sec.count() << endl;

	start = std::chrono::system_clock::now();
	cout << loopFibo( num ) << endl;
	sec = std::chrono::system_clock::now() - start;
	cout << "time=" << sec.count() << endl;
}
