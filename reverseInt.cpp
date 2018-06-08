#include <iostream>
using namespace std;

int reverse( int x )
{
	int tmp = 0;
	int rtn = 0 ;

	while( x > 0 ) {
		tmp = x % 10 ;
		rtn = rtn * 10 + tmp;
		x = x / 10;
	}
	return rtn;
}

int solution ( int x, int y) 
{
	x = reverse( x );
	y = reverse( y );
	return reverse( x+y);
}

int main ()
{
	int rtn = 321 + 654;
	cout << rtn << endl;
	cout << solution ( 123, 456 ) << endl;
}
