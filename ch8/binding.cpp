#include<iostream>

using namespace std;

// impooooooooooortant
/*
class Animal
{
public:

    void speak()
    {
        cout<<"Animal"<<endl;
    }
};

class Dog : public Animal
{
public:

    void speak()
    {
        cout<<"Dog"<<endl;
    }
};

int main()
{
    Dog d;

    Animal* ptr=&d;

    ptr->speak(); // result is Animal as NOOOOOOO (virtual) 
}*/

class Animal
{
public:

    virtual void speak()
    {
        cout<<"Animal"<<endl;
    }
};

class Dog:public Animal
{
public:

    void speak() override
    {
        cout<<"Dog"<<endl;
    }
};

int main()
{
    Dog d;

    Animal* ptr=&d;

    ptr->speak(); // result is Dog as (virtual) 
}