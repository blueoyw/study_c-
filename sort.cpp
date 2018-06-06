#include <iostream>
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
	if (j > low) {
		cout << "j=" << j << endl;
		quickSort(array, low, j);
	}
	if (i < high) {
		cout << "i=" << i << endl;
		quickSort(array, i, high);
	}
}

int main(int argc, char** argv)
{
	//bubble sort
	int data[] = {8, 10, 7, 3 , 1};
	int n = 5;
	/*

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
	*/
	//end

	//quick sort
	quickSort( data, 0, n);
	for( int i=0; i<n; i++ ) {
		cout << data[i] << endl;
	}
	
}
