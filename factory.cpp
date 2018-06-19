#include <pattern.h>


//using namespace std;

class AnimalFactory
{
public:

	static AnimalFactory* getInstance()
	{
		if( _instance ==NULL )
		{
			cout << "test" << endl;
			_instance  = new AnimalFactory();
		}
		return _instance ;
	}

	static IAnimal* createAnimal( AnimalType type)
	{
		switch( type ) {
		case CAT:
			return new Cat();
		case DOG:
			return new Dog();
		default:
			cout << "default" << endl;
		}
		return NULL;
	}

	AnimalFactory(const AnimalFactory&) = delete ;
	AnimalFactory& operator=(const AnimalFactory&) = delete ;
private:
	AnimalFactory(){}
	static AnimalFactory* _instance ;
};

//instance initialization
AnimalFactory* AnimalFactory::_instance = NULL;

int main()
{
	cout << "start" <<endl;
	AnimalFactory* factory = AnimalFactory::getInstance();
	Cat* cat = (Cat*)factory->createAnimal( AnimalType::CAT );
	cat->speak();

	Dog* dog = (Dog*)factory->createAnimal( AnimalType::DOG );
	dog->speak();

	return 0;
}
