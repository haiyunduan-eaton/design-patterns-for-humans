/*
When to use?

When there could be several flavors of an object and to avoid the constructor telescoping. 
The key difference from the factory pattern is that; factory pattern is to be used when the creation is a one step process while builder pattern is to be used when the creation is a multi step process.
*/
#include <iostream>
#include <memory>

namespace clanguml
{
    namespace Builder
    {
        class Burger;
        // 定义BurgerBuilder类
        class BurgerBuilder {
        public:
            int size;
            bool cheese = false;
            bool pepperoni = false;
            bool lettuce = false;
            bool tomato = false;

            explicit BurgerBuilder(int size) : size(size) {}

            BurgerBuilder& addPepperoni() {
                pepperoni = true;
                return *this;
            }

            BurgerBuilder& addLettuce() {
                lettuce = true;
                return *this;
            }

            BurgerBuilder& addCheese() {
                cheese = true;
                return *this;
            }

            BurgerBuilder& addTomato() {
                tomato = true;
                return *this;
            }

            std::unique_ptr<Burger> build(){
                return std::make_unique<Burger>(*this);
            }
        };
                // 定义Burger类
        class Burger {
        private:
            int size;
            bool cheese;
            bool pepperoni;
            bool lettuce;
            bool tomato;

        public:
            Burger(const BurgerBuilder& builder) 
                : size(builder.size), 
                cheese(builder.cheese), 
                pepperoni(builder.pepperoni), 
                lettuce(builder.lettuce), 
                tomato(builder.tomato) {}

            void display() const {
                std::cout << "Burger Size: " << size << "\n";
                std::cout << "Cheese: " << (cheese ? "Yes" : "No") << "\n";
                std::cout << "Pepperoni: " << (pepperoni ? "Yes" : "No") << "\n";
                std::cout << "Lettuce: " << (lettuce ? "Yes" : "No") << "\n";
                std::cout << "Tomato: " << (tomato ? "Yes" : "No") << "\n";
            }
        };
    }
}
int main()
{
    auto burger = clanguml::Builder::BurgerBuilder(14)  // 创建一个大小为14的汉堡建造者
                    .addPepperoni()  // 链式调用添加配料
                    .addLettuce()
                    .addTomato()
                    .build();
    burger->display();

    delete burger.release();

    return 0;
}
