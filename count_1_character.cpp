#include <iostream>
#include <map>
#include <string>
using namespace std;
int main( int argc, char** argv)
{
	string test = "street";
	map<char,int> m;	
	map<char,int>::iterator it;

	for( int i=0; i<test.length(); i++ ) {
		it = m.find( test[i] ) ;
		if ( it== m.end() ) {
			m.insert( make_pair(test[i], 1 ) );
		} else {
			it->second = it->second + 1;
		}

	}

	for ( it = m.begin(); it != m.end(); it ++ ) {
		if ( it->second == 1 )
		{
			cout << it->first << endl;
		}
	}

	return 0;
}

