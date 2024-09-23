
#include <iostream>
namespace clanguml{
namespace SimpleFactory{
	class Door{
	public:
		virtual float getWidth()=0;
		virtual float getHeight()=0;
	};

	class WoodenDoor: public Door{
	public:
		WoodenDoor(float w,float h){
			m_width = w;
			m_height = h;
		}

		float getWidth()
		{
			return m_width;
		}
		
		float getHeight()
		{
			return m_height;
		}
	private:
		float m_width;
		float m_height;
	};

	class DoorFactory
	{
	public:
		static Door*  makeDoor(float width,float height)
		{
			return new WoodenDoor(width,height);
		}
	};

	int main()
	{
		class Door* door1 = DoorFactory::makeDoor(100,220);
		class Door* door2 = DoorFactory::makeDoor(101,222);

		std::cout << door1->getWidth() << "-" << door1->getHeight()<<"\n";
		std::cout << door2->getWidth() << "-" << door2->getHeight()<<"\n";
		

		return 0;
	}
}
}