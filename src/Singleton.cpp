/*
Singleton pattern is actually considered an anti-pattern and overuse of it should be avoided. It is not necessarily bad and could have some valid use-cases but should be used with caution because it introduces a global state in your application and change to it in one place could affect in the other areas and it could become pretty difficult to debug. 
The other bad thing about them is it makes your code tightly coupled plus mocking the singleton could be difficult.
*/
#include <iostream>
#include <memory>

class President {
private:
    static President* instance;

    // Private Constructor
    President() {
        // Initialization code here
    }

public:
    // Delete copy constructor and assignment operator
    President(const President&) = delete;
    President& operator=(const President&) = delete;

    // Public method to access the instance
    static President* getInstance() {
        if (instance == nullptr) {
            instance = new President();
        }
        return instance;
    }

    // Example method
    void showMessage() const {
        std::cout << "Hello from President Singleton!" << std::endl;
    }
};

// Initialize the static member
President* President::instance = nullptr;

int main() {
    President* president1 = President::getInstance();
    President* president2 = President::getInstance();

    president1->showMessage();
    president2->showMessage();

    // Both pointers point to the same instance
    std::cout << "Both pointers are the same: " << (president1 == president2) << std::endl;

    return 0;
}