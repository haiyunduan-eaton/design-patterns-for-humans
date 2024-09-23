/*
When to use?

Useful when there is some generic processing in a class but the required sub-class is dynamically decided at runtime. 
Or putting it in other words, when the client doesn't know what exact sub-class it might need.
*/

#include <iostream>
namespace clanguml{
namespace FactoryMethod {
    class Protocol {
    public:
        virtual void send(const char* data) = 0;
    };

    class QProtocol:public Protocol {
    public:
        void send(const char* data) {
            std::cout << "Sending data using Q protocol: " << data << std::endl;
        }
    };

    class ShutProtocol:public Protocol {
    public:
        void send(const char* data) {
            std::cout << "Sending data using Shut protocol: " << data << std::endl;
        }
    };

    class ModbusProtocol:public Protocol {
    public:
        void send(const char* data) {
            std::cout << "Sending data using Modbus protocol: " << data << std::endl;
        }
    };

    /// @brief  
    class UPSManager {
    public:
        //Factory method
        virtual Protocol* createProtocol() = 0;
        void sendData(const char* data) {
            Protocol* protocol = createProtocol();
            protocol->send(data);
            delete protocol;
        }
    };

    class UPSModelName1:public UPSManager {
    public:
        Protocol* createProtocol() {
            return new QProtocol();
        }
    };

    class UPSModelName2:public UPSManager {
    public:
        Protocol* createProtocol() {
            return new ShutProtocol();
        }
    };

    class UPSModelName3:public UPSManager {
    public:
        Protocol* createProtocol() {
            return new ModbusProtocol();
        }
    };

 
}
}

using namespace clanguml::FactoryMethod;
int main() {
    UPSManager* upsManager = new UPSModelName1();
    upsManager->sendData("test Q cmd");
    delete upsManager;

    upsManager = new UPSModelName2();
    upsManager->sendData("test Shut cmd");
    delete upsManager;

    upsManager = new UPSModelName3();
    upsManager->sendData("test Modbus cmd");
    delete upsManager;  
    return 0;
}


