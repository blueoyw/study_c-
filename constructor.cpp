#include <iostream>

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
	Child* child = new Child();
	delete child;

	cout << "dynamic binding" << endl;
	Parent* p = new Child();
	delete p;

	cout << "virtual dynamic binding" << endl;
	VParent* vp = new VChild();
	delete vp;

	return 0;
}
