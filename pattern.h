#pragma once
#include <iostream>
#include <memory>
/*
 * Cat lives in East.
 * Dag lives in West.
 */

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
	virtual void draw() {}
};

class Cat : public IAnimal
{
public:
	void draw() { cout << "Meow" << endl; }
};

class Dog : public IAnimal
{
public:
	void draw() { cout << "Woof" << endl; }
};

class CatFood : public IAnimal
{
public:
	void draw() { cout << "CatFood" << endl; }
};

class DogFood : public IAnimal
{
public:
	void draw() { cout << "DogFood" << endl; }
};


