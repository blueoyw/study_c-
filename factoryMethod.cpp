#include <pattern.h>


//using namespace std;

class IAnimalFactory
{
public:
	virtual IAnimal* factory( ) = 0;
	virtual ~IAnimalFactory() {}

	IAnimal anOperation()
	{
		IAnimal* animal = factory();
		animal->draw();
	}
};

class EastAnimalFactory : public IAnimalFactory
{
public:
	IAnimal* factory()
	{
		return new Cat();
	}
};

class WestAnimalFactory : public IAnimalFactory
{
public:
	IAnimal* factory()
	{
		return new Dog();
	}
};

int main()
{
	cout << "start" <<endl;
	IAnimalFactory* eastAnimalFactory = Singleton<EastAnimalFactory>::getInstance();
	eastAnimalFactory->anOperation();
	
	IAnimalFactory* westAnimalFactory = Singleton<WestAnimalFactory>::getInstance();
	westAnimalFactory->anOperation();

	return 0;
}
