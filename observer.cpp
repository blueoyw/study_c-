#include <pattern.h>
#include <set>

// 방송( Subject )
// 시청자 ( Observer )

class Observer
{
public:
	virtual void update( )=0;
	
};

class ConcreteObserver : public Observer
{
public:
	virtual void update() { cout << this << ": update" << endl; }
};

class Subject
{
public:
	virtual ~Subject() {}
	void attach( Observer* o ) { _list.insert(o); }
	void detach( Observer* o ) 
	{ 
		auto it = _list.find(o);
		if( it != _list.end() )
			_list.erase(it);
	}

	void notify()
	{
		auto it = _list.begin();
		for( ; it != _list.end(); it++ ) {
			(*it)->update();
		}

	}
	virtual void update() = 0;
private:
	set<Observer*> _list;
};

class ConcreteSubject: public Subject
{
public:
	virtual void update()
	{
		cout << "ConcreteSubject update " << endl;

	}
};

int main()
{
	Subject* subject = new ConcreteSubject();
	Observer* observer = new ConcreteObserver();

	subject->attach(observer);
	subject->notify();
	subject->update();

	return 0;
}
