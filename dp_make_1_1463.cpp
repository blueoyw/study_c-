#include<iostream>
using namespace std;
//https://www.acmicpc.net/problem/1463
int d[1000000];

//1. d(n) = d(n/3) + 1;
//2. d(n) = d(n/2) + 1;
//3.d(n) = d(n-1) + 1;
//d(n) = MIN( 1,2,3)
int go(int n) {
	if ( n == 1 ) return 0;
	if( d[n] > 0) return d[n];
	cout << "n=" << n <<endl;
	d[n] = go (n-1) +1; //d(n-1) + 1의 값이 저장됨.
	if( n%2 == 0) {
		int temp = go(n/2) + 1; //d(n/2) +1의 값이 저장됨.
		if ( d[n] > temp ) { //d[n]의 이전에 구한 d(n-1) + 1의 값.
			cout << "n/2 d[n]=" << d[n] << " temp=" << temp <<endl;
			d[n] = temp;
		}
	}
	if( n%3 == 0) {
		int temp = go(n/3) + 1; //d(n/3) +1의 값이 저장됨.
		if ( d[n] > temp ) { //1,2,3 연산 중 최소값이 d[n]으로 결정.
			cout << "n/3 d[n]=" << d[n] << " temp=" << temp <<endl ;
			d[n] = temp;
		}
	}

	return d[n];
}

//bottom up
int go2(int n) 
{
	d[1] = 0;
	for( int i=2; i<=n ; i++ ) {
		d[i] = d[i-1] +1;
		if( i%2 ==0 && d[i] > (d[i/2]+1)) {
			d[i] = d[i/2] +1;
		}

		if( i%3==0 && d[i] > ( d[i/3]+1)) {
			d[i] =d[i/3]+1;
		}
	}
	return d[n];
}

int main()
{
	long n;
	cin >> n;
	if( n < 1 || n>1000000) {
		return 0;
	}
	//int rtn = go(n);
	int rtn = go2(n);

	cout << rtn << endl;

}

