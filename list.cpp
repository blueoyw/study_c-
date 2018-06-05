#include <iostream>
#include <memory>
#include <array>

using namespace std;

class Node {
public:
	Node():_next(NULL) {}
	Node(int i):_num(i), _next(NULL) {}

	int _num;
	Node* _next;
};

template<class T>
class List {
public:
	List<T>() : _size(0)
	{
		_head = new T();
	}

	~List()
	{
		if( _size > 0 ) {
			T* node = _head->_next;
			for( int i=0; i<_size; i++ ) {
				Node* tmp = node->_next;
				delete node;
				node = tmp;
			}
		}
		delete _head;
	}

	int size()
	{
		return _size;
	}

	void push_back( T node )
	{
		T* add = new T();
		*add = node;

		T* tmp = _head;
		for( int i=0; i<_size; i++ ) {
			tmp = tmp->_next;
		}
		add->_next = tmp->_next;
		tmp->_next = add;
		_size++;
	}

	T* get(int index)
	{
		T* tmp = _head->_next;
		for( int i=0; i<index; i++ ) {
			tmp = tmp->_next;
		}
		return tmp;
	}

	void pop_front()
	{
		cout << "pop" << endl;
		if( _size > 0 ) {
			T* tmp = _head->_next;
			_head->_next = tmp->_next;
			delete tmp;
			_size--;
		}
	}

private:
	int _size;
	T* 	_head;
};

int main()
{
	Node n1(1);
	Node n2(2);
	List<Node> list;
	list.push_back(n1);
	cout << "size="<< list.size() << endl;
	list.push_back(n2);
	cout << "size="<< list.size() << endl;

	Node* tmp = list.get(0);
	cout << "num="<<tmp->_num << endl;
	tmp = list.get(1);
	cout << "num="<<tmp->_num << endl;

	list.pop_front();
	cout << list.size() << endl;

	list.pop_front();
	cout << list.size() << endl;

	return 0;
}
