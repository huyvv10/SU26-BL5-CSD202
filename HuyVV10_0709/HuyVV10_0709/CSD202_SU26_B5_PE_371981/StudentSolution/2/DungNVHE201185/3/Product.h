#pragma once
#include <string>

class Product{
public:
    int         id;
    std::string name;
    double      rating;

    Product() ;
    Product(int xId, const std::string& xName, double xRating);

    std::string toString() const;
};