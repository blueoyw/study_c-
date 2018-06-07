#include <iostream>
#include <array>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <deque>
#include <set>

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
	cout<<"=====array" << endl;
	array<int, 3> arr = {9,8,7};
	cout << arr.size() << endl;
	for ( auto it = arr.begin() ; it!=arr.end() ; it++ ) {
		cout << *it << endl;
	}
	cout << "size=" << arr.size() << endl;

	cout<<"vector" << endl;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	//v.pop_back();
	for( auto it = v.begin() ; it!=v.end();  ) {
		cout << *it << endl;
		it = v.erase(it);
	}
	cout << "size=" << v.size() << endl;

	cout<<"=====list" << endl;
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_front(0);
	l.pop_back();
	//v.pop_back();
	for( auto it = l.begin() ; it!=l.end();  ) {
		cout << *it << endl;
		it = l.erase(it);
	}
	cout << "size=" << l.size() << endl;

	cout<<"=====deque" << endl;
	deque<int> q;
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);
	q.push_front(0);
	q.pop_back();
	q.pop_front();
	//v.pop_back();
	for( auto it = q.begin() ; it!=q.end();  ) {
		cout << *it << endl;
		it = q.erase(it);
	}
	cout << "size=" << q.size() << endl;

	cout<<"=====set" << endl;
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	auto sit = s.find(3);
	if( sit != s.end() ) {
		s.erase(sit);
	}
	//v.pop_back();
	for( auto it = s.begin() ; it!=s.end();  ) {
		cout << *it << endl;
		s.erase(it++);
	}
	cout << "size=" << s.size() << endl;

	cout<<"=====map" << endl;
	map<int, int> m;
	m.insert( make_pair(1,10) );
	m.insert( pair<int,int>(2,20) );

	auto it = m.find(1);
	if( it != m.end() ) {
		cout << "find " << it->first << "=" << it->second << endl;
	}

	for( auto it = m.begin() ; it != m.end() ;  ) {
		cout << it->first << "=" << it->second << endl;
		m.erase(it++);
	}
	cout << "size=" << m.size() << endl;
	
	cout<<"=====hash map" << endl;
	unordered_map<int, int> um;
	um.insert( make_pair(1,10) );
	um.insert( pair<int,int>(2,20) );

	for( auto it = um.begin() ; it != um.end() ; it ++ ) {
		cout << it->first << "=" << it->second << endl;
	}


	return 0;
}
