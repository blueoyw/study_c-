#include <iostream>
#include <array>
#include <map>

using namespace std;

class Parent
{
public:
	Parent() 
	{
		cout << "Construct Parent" << endl;
	}

	~Parent() 
	{
		cout << "Destruct Parent" << endl;
	}
};

class VParent
{
public:
	VParent() 
	{
		cout << "Construct VParent" << endl;
	}

	virtual ~VParent() 
	{
		cout << "Destruct VParent" << endl;
	}
};

class Child : public Parent
{
public:
	Child() 
	{
		cout << "Construct Child" << endl;
	}

	~Child() 
	{
		cout << "Destruct Child" << endl;
	}
};

class VChild : public VParent
{
public:
	VChild() 
	{
		cout << "Construct VChild" << endl;
	}

	~VChild() 
	{
		cout << "Destruct VChild" << endl;
	}
};

int main( int argc, char** argv )
{
	array<int, 3> arr = {9,8,7};
	cout << arr.size() << endl;
	for ( auto it = arr.begin() ; it!=arr.end() ; it++ ) {
		cout << *it << endl;
	}

	map<int, int> m;
	m.insert( make_pair(1,10) );
	m.insert( pair<int,int>(2,20) );

	for( auto it = m.begin() ; it != m.end() ; it ++ ) {
		cout << it->first << "=" << it->second << endl;
	}

	return 0;
}
