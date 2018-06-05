#include <iostream>
#include <array>

using namespace std;

class Node {
public:
	Node() {}
	Node( int value ) : _value(value)
	{
	}
	~Node() {}
	
	int getValue() 
	{
		return _value;
	}

	void setValue( int value )
	{

		_value = value;
	}

private:
	int _value;

};

class Stack {
public:
	Stack(int max) : _top(-1), _max(max)
	{
		_nodes = new Node[_max];
	}

	~Stack()
	{
		delete[] _nodes;
	}

	bool isFull()
	{
		return (_top>_max)?true:false;
	}

	bool isEmpty()
	{
		return (_top<0)?true:false;
	}

	int size()
	{
		return (_top+1);
	}

	bool push( Node node )
	{
		if( isFull() )
			return false;
		_nodes[++_top] = node;
		return true;
	}

	Node pop()
	{
		cout << "pop" << endl;
		if( isEmpty() )
			return 0;
		return _nodes[_top--];	
	}

private:
	int _top;
	int _max;
	Node* _nodes;
};

int main()
{
	Node n1(1);
	Node n2(2);
	Stack stack(5);
	stack.push(n1);
	stack.push(n2);
	cout<<"size="<<stack.size()<<endl;
	int size = stack.size();
	for( int i=0; i <= size ; ++i ) {
		cout << i << endl;
		Node n = stack.pop();
		cout << n.getValue() << endl;
	}



	return 0;
}
