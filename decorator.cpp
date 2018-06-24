#include <pattern.h>

class Decorator : public IAnimal {
private:
    IAnimal* _animal;
public:
    Decorator( IAnimal* animal) {
        _animal = animal;
    }

    void draw() {
        _animal->draw();
    }

    ~Decorator() {
        delete _animal;
    }

};

//extends function
class ArmorCat : public Decorator {
public:
    ArmorCat( IAnimal* animal) : Decorator(animal) {}

    
    void draw() {
        Decorator::draw();
        cout << " ArmorCat " << endl;
    }
};

//extends function
class MadCat : public Decorator {
public:
    MadCat( IAnimal* animal) : Decorator(animal) {}

    
    void draw() {
        Decorator::draw();
        cout << " MadCat " << endl;
    }
};


int main()
{
	cout << "start" <<endl;
    IAnimal* animal = new MadCat(new ArmorCat( new Cat() ));
    animal->draw();

	return 0;
}
