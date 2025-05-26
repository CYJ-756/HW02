#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal {
public:
    virtual void makeSound() = 0;   
    virtual void move() = 0;
    virtual ~Animal() {
    
    }
};

class Cat : public Animal {
    void makeSound() override {
        cout << "catcat" << endl;
    }
    void move() override { 
        cout << "cat move" << endl; 
    }
}; 

class Dog : public Animal {
    void makeSound() override {
        cout << "dogdog" << endl;
    }
    void move() override {
        cout << "dog move" << endl;
    }
};

class Cow : public Animal {
public:
    void makeSound() override {
        cout << "cowcow" << endl;
    }
    void move() override {
        cout << "cow move" << endl;
    }
};

class Zoo {
private:
    Animal* animals[10];
    int animalCount = 0;
public:
    void addAnimal(Animal* animal) {
        if (animalCount < 10) {
            animals[animalCount++] = animal;
        }
        else {
            std::cout << "can't add " << std::endl;
        }
    }

    void performActions() {
        for (int i = 0; i < animalCount; ++i) {
            animals[i]->makeSound();
            animals[i]->move();
        }
    }
    ~Zoo() {
        for (int i = 0; i < animalCount; ++i) {
            delete animals[i];
        }
    }
};

Animal* createRandomAnimal() {
    int r = rand() % 3; // 0, 1, 2 중 하나의 값 생성
    if (r == 0)
        return new Dog();
    else if (r == 1)
        return new Cat();
    else
        return new Cow();
}

int main()
{
    std::srand(std::time(0));
    Animal* animals[3];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Cow();

    for (int i = 0; i < 3; i++) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }
    
    Zoo zoo;
    for (int i = 0; i < 5; ++i) {
        zoo.addAnimal(createRandomAnimal());
    }

    zoo.performActions();
    
    return 0;
}
