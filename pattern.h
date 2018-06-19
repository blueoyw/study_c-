#pragma once
#include <iostream>

using namespace std;

template< typename T >
class Singleton
{
public:
	static T* getInstance()
	{
		if( _instance==NULL )
			_instance = new T();
		return _instance;
	}
	Singleton(const Singleton&) = delete ;
	Singleton& operator=(const Singleton&) = delete ;
private:
	Singleton(){};
	static T* _instance;
};

template<typename T> 
T* Singleton<T>::_instance = NULL;

enum AnimalType {
	CAT,
	DOG
};

class IAnimal
{
public:
	virtual void speak() = 0;
};

class Cat : public IAnimal
{
public:
	void speak() { cout << "Meow" << endl; }
};

class Dog : public IAnimal
{
public:
	void speak() { cout << "Woof" << endl; }
};

