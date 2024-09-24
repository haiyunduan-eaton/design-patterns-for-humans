/*
When to use?

Useful when there is some generic processing in a class but the required sub-class is dynamically decided at runtime.
Or putting it in other words, when the client doesn't know what exact sub-class it might need.
*/

#include <iostream>
namespace clanguml
{
	namespace AbstractFactory
	{
		class Protocol
		{
		public:
			virtual ~Protocol() = default;
			virtual void send(const char *data) = 0;
		};

		class QProtocol : public Protocol
		{
		public:
			void send(const char *data)
			{
				std::cout << "Sending data using Q protocol: " << data << std::endl;
			}
		};

		class ShutProtocol : public Protocol
		{
		public:
			void send(const char *data)
			{
				std::cout << "Sending data using Shut protocol: " << data << std::endl;
			}
		};

		class ModbusProtocol : public Protocol
		{
		public:
			void send(const char *data)
			{
				std::cout << "Sending data using Modbus protocol: " << data << std::endl;
			}
		};

		/* ProtocolParser*/
		class ProtocolParser
		{
		public:
			virtual ~ProtocolParser() {};
			virtual void parse() = 0;
		};

		class QProtocolParser : public ProtocolParser
		{
		public:
			void parse()
			{
				std::cout << "Q parse" << std::endl;
			}
		};

		class ShutProtocolParser : public ProtocolParser
		{
		public:
			void parse()
			{
				std::cout << "Shut parse" << std::endl;
			}
		};

		class ModbusProtocolParser : public ProtocolParser
		{
		public:
			void parse()
			{
				std::cout << "Modbus parse" << std::endl;
			}
		};

		/*
		class ProtocolFactory
		*/
		class ProtocolFactory
		{
		public:
			virtual ~ProtocolFactory() {}

			// Factory method
			virtual Protocol *createProtocol() = 0;
			virtual ProtocolParser *createProtocolParser() = 0;
		};

		class UPSModelName1 : public ProtocolFactory
		{
		public:
			Protocol *createProtocol()
			{
				return new QProtocol();
			}
			ProtocolParser *createProtocolParser()
			{
				return new QProtocolParser();
			}
		};

		class UPSModelName2 : public ProtocolFactory
		{
		public:
			Protocol *createProtocol()
			{
				return new ShutProtocol();
			}
			ProtocolParser *createProtocolParser()
			{
				return new ShutProtocolParser();
			}
		};

		class UPSModelName3 : public ProtocolFactory
		{
		public:
			Protocol *createProtocol()
			{
				return new ModbusProtocol();
			}
			ProtocolParser *createProtocolParser()
			{
				return new ModbusProtocolParser();
			}
		};

	}
}

using namespace clanguml::AbstractFactory;
int main()
{
	////////////////////////////////////////////////////
	ProtocolFactory *upsManager = new UPSModelName1();
	Protocol *pProtocol = upsManager->createProtocol();
	ProtocolParser *pProtocolParser = upsManager->createProtocolParser();

	pProtocol->send("cmd");
	pProtocolParser->parse();

	delete pProtocol;
	delete pProtocolParser;
	delete upsManager;

	////////////////////////////////////////////////////
	upsManager = new UPSModelName2();
	pProtocol = upsManager->createProtocol();
	pProtocolParser = upsManager->createProtocolParser();

	pProtocol->send("cmd");
	pProtocolParser->parse();

	delete pProtocol;
	delete pProtocolParser;
	delete upsManager;

	upsManager = new UPSModelName3();
	pProtocol = upsManager->createProtocol();
	pProtocolParser = upsManager->createProtocolParser();

	pProtocol->send("cmd");
	pProtocolParser->parse();

	return 0;
}
