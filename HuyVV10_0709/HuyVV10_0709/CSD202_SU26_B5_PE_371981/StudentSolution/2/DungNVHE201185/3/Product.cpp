#include "Product.h"
#include <sstream>
#include <iomanip>

Product::Product() : id(0), name(""), rating(0.0) {}

Product::Product(int xId, const std::string& xName, double xRating)
        : id(xId), name(xName), rating(xRating) {}
        
std::string Product::toString() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << rating;
    return "(" + std::to_string(id) + "," + name + "," + oss.str() + ")";
}
