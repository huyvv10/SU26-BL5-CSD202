#include "Car.h"

Car::Car(std::string id, std::string _name, int _color, double _price) {
	this->id = _id;
	this->name=_name;
	this->color=_color;
	this->price=_price;
}

Car::~Car(){};

std::string Car::display(){
	return cout<<"("<<this->id<<", "<<this->name<<", "<<this->color<<", "<<this->price<<")"<<endl;
}