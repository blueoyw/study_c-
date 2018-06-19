#pragma once
#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton* getInstance()
	{
		if( instance==NULL )
			instance = new Singleton();
		return instance;
	}
	Singleton(const Singleton&) = delete ;
	Singleton& operator=(const Singleton&) = delete ;
private:
	Singleton();
	static Singleton* instance;
};

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

