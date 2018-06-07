#include <iostream>
#include <array>

using namespace std;

array<int,5>  a = { 1,2,23,30,50 };
int binarySearch( int low, int high, int search )
{
	cout << low << ", " << high << ", " << search << endl;
	int guess = (low+high)/2;
	if( a[guess] == search || low > high ) 
		return a[guess];
	if( search < a[guess] )  {
		high = guess-1;
		binarySearch ( low, high, search );
	}
	else {
		low = guess+1;
		binarySearch ( low, high, search );
	}
}

int main( int argc, char** argv)
{
	cout << binarySearch( 0, a.size(), 2 ) << endl ;
	return 0;
}

