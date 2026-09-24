#include "Lib.h"
#include <iostream>
#include <filesystem>
#include <fstream> 
#include <vector> 

void Lib::viewFile(const std::string& fname) {
    namespace fs = std::filesystem;
    if (!fs::exists(fname)) {
        std::cerr << " The file " << fname << " does not exist!" << "\n";
        return;
    }

    std::ifstream f(fname); // Mac dinh la text mode, phu hop de dung getline
    if (!f) {
        std::cerr << " Cannot open file " << fname << "!\n";
        return;
    }

    std::cout << " Content of the file " << fname << ":\n";
    std::string line;
    while (std::getline(f, line)) {
        std::cout << "  " << line << "\n";
    }
}

void Lib::dispIntArray(const std::vector<int>& a, std::ostream& out) {
    for (const auto& val : a) { // Dung range-based for cho gon
        out << val << ' ';
    }
    out << "\n";
}

void Lib::dispIntArray(const std::vector<int>& a) {
    dispIntArray(a, std::cout);
}

void Lib::dispIntArray(const std::vector<int>& a, std::size_t k, std::size_t h, std::ostream& out) {
    if (a.empty() || k > h || h >= a.size()) return;
    for (std::size_t i = k; i <= h; ++i) {
        out << a[i] << ' ';
    }
    out << "\n";
}

bool Lib::dispIntArrayToFile(const std::vector<int>& a, const std::string& out_fname) {
    std::ofstream f(out_fname); 
    if (!f) return false;
    dispIntArray(a, f);
    return true;
}