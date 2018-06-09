#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int *array, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = array[(i + j) / 2];
	int temp;

	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}

	if (low < j) {
		//cout << "j=" << j << endl;
		quickSort(array, low, j);
	}
	if (i < high) {
		//cout << "i=" << i << endl;
		quickSort(array, i, high);
	}
}

void print( int* data, int size )
{
	for( int i=0; i<size; i++ ) {
		cout << data[i] << endl;
	}
}

void selectionSort( int* data, int n)
{
	int min = 0;
	for( int i=0; i<n-1; i++ ) {
		min = data[i];
		for( int j=i+1; j< n; j++ ) {
			if ( min > data[j] ) {
				data[i] = data[j];
				data[j] = min;
				min = data[i];
			}
		}
	}
}

void bubbleSort( int* data, int n)
{
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
}

void insertionSort( int* data, int n) 
{
	for ( int i=1; i< n; i++ ) {
		int j = i;
		int temp = data[i];
		while( j > 0 && data[j-1] > temp)  {
			data[j] = data[j-1];
			j--;
		}
		data[j] = temp;
	}
}

int main(int argc, char** argv)
{
	cout << "selection sort" << endl;
	int data[] = {8, 10, 7, 3 , 1};
	int n = 5;
	selectionSort ( data, 5);
	print( data, n);

	cout << "bubble sort" << endl;
	int data1[] = {8, 10, 7, 3 , 1};
	bubbleSort( data1, 5);
	print( data1, n);

	cout << "quick sort" << endl;
	int data2[] = {8, 10, 7, 3 , 1};
	quickSort( data2, 0, n-1); //why n-1, -1 is pivot
	print( data2, n);

	cout << "insertion sort" << endl;
	int data3[] = {8, 10, 7, 3 , 1};
	insertionSort( data3, 5);
	print( data3, n);
	
}
