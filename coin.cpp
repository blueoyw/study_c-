#include <iostream>
#include <map>

using namespace std;

int main ()
{
	int change;
	cin >> change;
	map<int,int> mapChange;
	mapChange.insert( make_pair(10,0));
	mapChange.insert( make_pair(50,0));
	mapChange.insert( make_pair(100,0));
	mapChange.insert( make_pair(500,0));


	while( change >= 500 ) {
		change -= 500;
		mapChange[500] ++;
	}
	while( change >= 100 ) {
		change -= 100;
		mapChange[100] ++;
	}
	while( change >= 50 ) {
		change -= 50;
		mapChange[50] ++;
	}
	while( change >= 10 ) {
		change -= 10;
		mapChange[10] ++;
	}

	for( auto it = mapChange.begin(); it != mapChange.end(); it ++ ) {

		cout << it->first << "=" << it->second << endl;
	}

}
