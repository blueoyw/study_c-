#include <pattern.h>


//using namespace std;

class IAnimalFactory
{
public:
	virtual IAnimal* createAnimal( ) = 0;
	virtual ~IAnimalFactory() {}
};

class EastAnimalFactory : public IAnimalFactory
{
public:
	IAnimal* createAnimal()
	{
		return new Cat();
	}
};

class WestAnimalFactory : public IAnimalFactory
{
public:
	IAnimal* createAnimal()
	{
		return new Dog();
	}
};

int main()
{
	cout << "start" <<endl;
	IAnimalFactory* eastAnimalFactory = Singleton<EastAnimalFactory>::getInstance();
	eastAnimalFactory->createAnimal()->speak();
	
	IAnimalFactory* westAnimalFactory = Singleton<WestAnimalFactory>::getInstance();
	westAnimalFactory->createAnimal()->speak();

	return 0;
}
