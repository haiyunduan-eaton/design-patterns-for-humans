/*
In software engineering, the adapter pattern is a software design pattern that allows the interface of an existing class to be used as another interface.
It is often used to make existing classes work with others without modifying their source code.
*/
#include <iostream>
#include <memory>
#include <string>

namespace clanguml
{
    class Animal
    {
    public:
        virtual ~Animal() = default;
        virtual void makeSound() const = 0;
    };

    class Lion : public Animal
    {
    public:
        void makeSound() const override
        {
            std::cout << "Roar" << std::endl;
        }
    };

    class Tiger : public Animal
    {
    public:
        void makeSound() const override
        {
            std::cout << "Growl" << std::endl;
        }
    };

    // WildDog class with a bark method
    class WildDog
    {
    public:
        void bark() const
        {
            std::cout << "Bark" << std::endl;
        }
    };

    // Adapter class to convert WildDog interface to Animal interface
    class WildDogAdapter : public Animal
    {
    private:
        WildDog* wildDog_;
    public:
        WildDogAdapter(WildDog* wildDog) : wildDog_(wildDog) {}

        void makeSound() const override
        {
            wildDog_->bark();
        }
    };

    // Hunter class with a hunt method
    class Hunter
    {
    public:
        void hunt(const Animal& animal) const
        {
            std::cout << "Hunter is hunting an animal that says: ";
            animal.makeSound();
        }
    };
}

using namespace clanguml;

int main()
{
    std::unique_ptr<Animal> lion = std::make_unique<Lion>();
    std::unique_ptr<Animal> tiger = std::make_unique<Tiger>();
    std::unique_ptr<WildDog> wildDog = std::make_unique<WildDog>();
    std::unique_ptr<Animal> adaptedWildDog = std::make_unique<WildDogAdapter>(wildDog.get());
    std::unique_ptr<Hunter> hunter = std::make_unique<Hunter>();

    hunter->hunt(*lion);          // Hunter is hunting an animal that says: Roar
    hunter->hunt(*tiger);         // Hunter is hunting an animal that says: Growl
    //hunter->hunt(*wildDog);     // Wrong interface
    hunter->hunt(*adaptedWildDog);// Hunter is hunting an animal that says: Bark

    return 0;
}