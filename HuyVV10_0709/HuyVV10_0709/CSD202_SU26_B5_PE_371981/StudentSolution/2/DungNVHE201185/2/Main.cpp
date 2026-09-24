#include <iostream>
#include <string>
#include "MyList.h"
#include "Lib.h"

int main() {
	MyList t;
	int choice;

	std::cout << "\n";
	std::cout << " 1. Test f1 (1 mark)\n";
	std::cout << " 2. Test f2 (1 mark)\n";
	std::cout << " 3. Test f3 (1 mark)\n";
	std::cout << " 4. Test f4 (1 mark)\n";
	std::cout << " 0. Exit\n";
	std::cout << "    Your selection (0 -> 4): ";
	if (!(std::cin >> choice)) {
		std::cout << "Wrong selection\n\n";
		return 0;
	}

	switch (choice) {
		case 0:
			// Exit
			break;

		case 1:
			t.f1();
			std::cout << "Your output:\n";
			Lib::viewFile("f1.txt");
			break;

		case 2:
			t.f2();
			std::cout << "Your output:\n";
			Lib::viewFile("f2.txt");
			break;

		case 3:
			t.f3();
			std::cout << "Your output:\n";
			Lib::viewFile("f3.txt");
			break;

		case 4:
			t.f4();
			std::cout << "Your output:\n";
			Lib::viewFile("f4.txt");
			break;

		default:
			std::cout << "Wrong selection\n";
			break;
	}
	std::cout << "\n";
	return 0;
}
