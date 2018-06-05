#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	//bubble sort
	int data[] = {5, 3, 7, 9 , 1};
	int n = 5;

	int tmp = 0;
	for( int i=0; i<n; i++ ) {
		for( int j=0; j< n-(i+1); j++ ) {
			if ( data[j] > data[j+1] ) {
				tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
			}
		}
	}
	for( int i=0; i<n; i++ ) {
		cout << data[i] << endl;
	}
	//end
	//quick sort
	//
}
