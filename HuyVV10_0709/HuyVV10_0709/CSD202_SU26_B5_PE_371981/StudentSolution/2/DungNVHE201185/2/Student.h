#pragma once
#include <string>

class Student {
public:
    std::string name;
    double gpa;
    int credit;

    Student();
    Student(const std::string& xName, double xGpa, int xCredit);
    std::string toString() const; // Format as: (name,gpa,credit)
};