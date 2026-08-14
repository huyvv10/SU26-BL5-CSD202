#ifndef CAR_H
#define CAR_H
#include <string>

class Car{
	public:
		std::string id;
		std::string name;
		int color;
		double price;
		
		Car(std::string id, std::string _name, int _color, double _price);
		virtual ~Car();
		std::string display();
};

#endif