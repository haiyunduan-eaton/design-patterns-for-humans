/*
When to use?

When an object is required that is similar to existing object 
or when the creation would be expensive as compared to cloning.
*/

#include <iostream>
#include <memory>

namespace clanguml
{
    // Prototype class, declare a clone interface
    class Prototype
    {
    public:
        virtual ~Prototype() = default;
        // Clone interface, returns a pointer to the cloned object
        virtual std::shared_ptr<Prototype> clone() const = 0;
        virtual void setName(std::string) = 0;
        // Other business methods
        virtual void show() const = 0;
        
    };

    // Concrete prototype class, implementing the clone interface and business methods
    class ConcretePrototype : public Prototype
    {
    private:
        std::string m_name;

    public:
        ConcretePrototype(const std::string &name) : m_name(name) {}

        // Implementing the clone interface
        std::shared_ptr<Prototype> clone() const override
        {
            return std::make_shared<ConcretePrototype>(*this);
        }
        void setName(std::string name) override
        {
            m_name = name;
        }
        // Implementing the business method
        void show() const override
        {
            std::cout << "ConcretePrototype: " << m_name << std::endl;
        }
    };
}

using namespace clanguml;
int main()
{
    // Create a prototype object
    std::shared_ptr<Prototype> prototype = std::make_shared<ConcretePrototype>("Original");

    // Clone a new object through the prototype object
    std::shared_ptr<Prototype> cloned = prototype->clone();
    cloned->setName("cloned");
    // Display information of the prototype object and the cloned object
    prototype->show();
    cloned->show();

    return 0;
}