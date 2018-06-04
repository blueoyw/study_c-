#include <iostream>
#include <memory>

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

	void print()
	{
		cout << "VChild print" << endl;
	}

	//shared_ptr<VChild> m_child; //recursive reference
	weak_ptr<VChild> m_child;	//recursive reference solution
};

int main( int argc, char** argv )
{
	/*
	cout << "unique_ptr" << endl;
	std::unique_ptr<VChild> p1(new VChild());
	p1->print();
	unique_ptr<VChild> p3 = move(p1);
	p1->print();
	p1.reset();
	p3->print();

	cout << "shared_ptr" << endl;
	shared_ptr<VChild> sp1(new VChild());
	sp1->print();
	shared_ptr<VChild> sp2 =sp1;
	sp2->print();
	VChild* ptr = sp2.get(); //get pointer
	ptr->print();
	cout << "shared_ptr count" << sp1.use_count() << endl;
	sp1.reset();
	cout << "shared_ptr count" << sp2.use_count() << endl;
	sp2.reset();	//call destructor
	cout << "shared_ptr count" << sp2.use_count() << endl;
	*/

	//recursive reference
	cout << "recursive reference problem" << endl;
	auto rp1 = make_shared<VChild>();
	cout << "rp1 shared_ptr count" << rp1.use_count() << endl;
	{
		auto rp2 = make_shared<VChild>();
		//rp2->m_child = rp1;
		rp2->m_child = rp1;
		cout << "rp1 shared_ptr count" << rp1.use_count() << endl;
		cout << "rp2 shared_ptr count" << rp2.use_count() << endl;
		rp1->m_child = rp2;
		cout << "rp2 shared_ptr count" << rp2.use_count() << endl;
		auto rp3 = rp1->m_child.lock();
		cout << "rp3 shared_ptr count" << rp3.use_count() << endl;
	}
	cout << "rp1 shared_ptr count" << rp1.use_count() << endl;
	cout << "rp2 shared_ptr count" << rp1->m_child.use_count() << endl;

	return 0;
}
