#include <iostream>

int main() {
    int num = 0;

    // Acquisizione dell'input
    do {
        std::cout << "Inserire un numero tra 2 e 10: ";
        std::cin >> num;
        if (num < 2 || num > 10)
            std::cout << "Attenzione: occorre che il numero sia compreso tra 2 e 10" << std::endl;
    } while (num < 2 || num > 10);

    // Stampa del pattern
    std::cout << std::endl;
    for (int i = 1; i <= num; i++){
        for (int j = 1; j <= num; j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}

