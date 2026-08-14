#include "iostream"
#include "iomanip"
#include "Car.h"

Car::Car(){
	this->id="";
	this->name="";
	this->color=0;
	this->price=0.0;
};

Car::Car(std::string _id, std::string _name, int _color, double _price) {
	this->id = _id;
	this->name=_name;
	this->color=_color;
	this->price=_price;
}

Car::~Car(){};


std::string Car::display(){
	return "("+id+", "+name+", "
			+std::to_string(color) +", "+std::to_string(price)+")";
};

void Car::display2() {
    std::cout << std::left
              << std::setw(5)  << id
              << std::setw(25) << name
              << std::setw(10) << color
              << std::right
              << std::setw(15)
              << std::fixed
              << std::setprecision(2)
              << price
              << std::endl;
}