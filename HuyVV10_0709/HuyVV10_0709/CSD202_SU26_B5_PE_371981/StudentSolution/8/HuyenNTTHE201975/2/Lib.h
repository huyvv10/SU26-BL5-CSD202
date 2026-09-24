#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iosfwd>

class Lib {
public:
    // Read and display on the screen the content of the file fname
    static void viewFile(const std::string& fname);

    // Display to file all elements of the array of integers
    static void dispIntArray(const std::vector<int>& a, std::ostream& out);
};
