#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void solution( char* src )
{
	printf("start %s\n", src);
	char tmp;
	int end = strlen(src)-1;
	for( int i=0; i<end; i++, end-- ) {
		tmp = src[i];
		src[i] = src[end];	
		src[end] = tmp;
	}	

	printf("end %s\n", src);
}

int main( int argc, char** argv )
{
	char src[] = "start";
	solution(src);

	return 0;
}
