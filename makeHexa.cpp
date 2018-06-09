#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void solution( int red, int green, int blue )
{
	char buf[7];
	int idx=0;
	idx = sprintf( buf, "%2X", red);
	idx += sprintf( buf+idx, "%2X", green);
	idx += sprintf( buf+idx, "%2X", blue);

	cout << buf << endl;
}

string toHexa( int x )
{
	string rtn = "";
	int tmp = 0;
	int i = 0;
	while ( x > 0 ) 
	{
		tmp = x % 16;
		switch ( tmp ) {
		case 10 :
			rtn = 'A' + rtn ;
			break;
		case 11 :
			rtn = 'B' + rtn;
			break;
		case 12 :
			rtn = 'C' + rtn;
			break;
		case 13 :
			rtn = 'D' + rtn;
			break;
		case 14 :
			rtn = 'E' + rtn;
			break;
		case 15 :
			rtn = 'F' + rtn;
			break;
		default :
			char ascii = tmp + '0';
			rtn = ascii + rtn;
			break;
		}
		cout << tmp << endl;
		x = x / 16;
	}
	if( rtn.length() == 1 )  rtn = "0" + rtn;
	return rtn;
}

int main()
{
	//solution( 255,255,9);
	cout << toHexa( 255 ) << toHexa(255) << toHexa(9) << endl;
	return 0;
}

