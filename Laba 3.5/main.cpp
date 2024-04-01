#include "Classes.h"

int main() {
    try {
        Money money(3);
        money[0] = 1;
        money[1] = 2;
        money[2] = 3;

        std::cout << "Money amount: " << money.toString() << std::endl;

        std::cout << "Dollar digit at index 0: " << money[0] << std::endl;
        std::cout << "Tens of cents digit at index 1: " << money[1] << std::endl;
        std::cout << "Cents digit at index 2: " << money[2] << std::endl;

        // std::cout << money[5] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}