#include "Lib.h"
#include <iostream>
#include <filesystem>

void Lib::viewFile(const std::string& fname) {
    namespace fs = std::filesystem;
    if (!fs::exists(fname)) {
        std::cout << " The file " << fname << " does not exist!" << "\n";
        return;
    }

    std::ifstream f(fname, std::ios::in | std::ios::binary);
    if (!f) {
        std::cout << " Cannot open file " << fname << "!\n";
        return;
    }

    std::cout << " Content of the file " << fname << ":\n";
    std::string line;
    while (std::getline(f, line)) {
        std::cout << "  " << line << "\n";
    }
}

void Lib::dispIntArray(const std::vector<int>& a, std::ostream& out) {
    if (a.empty()) return;
    for (size_t i = 0; i < a.size(); ++i) {
        out << a[i] << (i + 1 < a.size() ? ' ' : '\0');
    }
    out << "\r\n";
}
