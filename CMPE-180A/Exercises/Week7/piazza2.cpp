#include<iostream>

class Animal{
public:
    virtual void sound() = 0;   // Pure virtual
};
class Dog: public Animal{
public:
    void sound(){
        std::cout << "Dog bark\n";
    }
};
class Cat: public Animal{
public:
    void sound(){
        std::cout << "cat meows\n";
    }
};
int main(){
    Animal* ptr = new Animal;
    ptr->sound();
    return 0;
}
