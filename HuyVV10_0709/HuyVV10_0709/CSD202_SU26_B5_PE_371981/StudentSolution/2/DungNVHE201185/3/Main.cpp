#include <iostream>
#include <string>
#include "BSTree.h"
#include "Lib.h"

int main() {
    BSTree t;
    int choice;

    std::cout << std::endl;
    std::cout << " 1. Test f1 (1 mark)" << std::endl;
    std::cout << " 2. Test f2 (1 mark)" << std::endl;
    std::cout << " 3. Test f3 (1 mark)" << std::endl;
    std::cout << " 4. Test f4 (1 mark)" << std::endl;
    std::cout << " 0. Exit" << std::endl;
    std::cout << "    Your selection (0 -> 4): ";
    if (!(std::cin >> choice)) return 0;

    switch (choice) {
        case 0:
            // Exit
            break;

        case 1:
            t.f1();
            std::cout << "Your output:" << std::endl;
            Lib::viewFile("f1.txt");
            break;

        case 2:
            t.f2();
            std::cout << "Your output:" << std::endl;
            Lib::viewFile("f2.txt");
            break;

        case 3:
            t.f3();
            std::cout << "Your output:" << std::endl;
            Lib::viewFile("f3.txt");
            break;

        case 4:
            t.f4();
            std::cout << "Your output:" << std::endl;
            Lib::viewFile("f4.txt");
            break;

        default:
            std::cout << "Wrong selection" << std::endl;
            break;
    }

    std::cout << std::endl;
    return 0;
}