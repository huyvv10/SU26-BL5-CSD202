#pragma once
#include <string>
#include <vector>
#include <iostream>

class Lib {
	public:
		static void viewFile(const std::string& fname);
		static void dispIntArray(const std::vector<int>& a, std::ostream& out);
		static void dispIntArray(const std::vector<int>& a);
		static void dispIntArray(const std::vector<int>& a, std::size_t k, std::size_t h, std::ostream& out);
		static bool dispIntArrayToFile(const std::vector<int>& a, const std::string& out_fname);
};