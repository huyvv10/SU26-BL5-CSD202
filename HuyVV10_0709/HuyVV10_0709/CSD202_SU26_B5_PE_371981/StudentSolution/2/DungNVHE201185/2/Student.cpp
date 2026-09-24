#include "Student.h"
#include <sstream>
#include <iomanip>

Student::Student() : name(""), gpa(0), credit(0) {}

Student::Student(const std::string& xName, double xGpa, int xCredit) 
    : name(xName), gpa(xGpa), credit(xCredit) {}

std::string Student::toString() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << gpa;
    return "(" + name + "," + oss.str() + "," + std::to_string(credit) + ")";
}