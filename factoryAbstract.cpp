#include <pattern.h>


class IAnimalFactory
{
public:
	virtual IAnimal* createAnimal( ) = 0;
	virtual IAnimal* createFood( ) = 0;
	virtual ~IAnimalFactory() {}
};

class EastAnimalFactory : public IAnimalFactory
{
public:
	IAnimal* createAnimal() 
	{
		return new Cat();
	}
	IAnimal* createFood() 
	{
		return new CatFood();
	}
};

class WestAnimalFactory : public IAnimalFactory
{
public:
	IAnimal* createAnimal() 
	{
		return new Dog();
	}
	IAnimal* createFood() 
	{
		return new DogFood();
	}
};


void raise( IAnimalFactory* factory)
{
	factory->createAnimal()->draw();
	factory->createFood()->draw();
}

int main()
{
	cout << "start" <<endl;
	IAnimalFactory* eastAnimalFactory = Singleton<EastAnimalFactory>::getInstance();
	raise( eastAnimalFactory );

	
	IAnimalFactory* westAnimalFactory = Singleton<WestAnimalFactory>::getInstance();
	raise( westAnimalFactory);

	return 0;
}
