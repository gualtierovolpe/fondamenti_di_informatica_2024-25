#include <iostream>

int main() {
    int num = 0;
    int contacifre = 0;

    // Acquisizione dell'input
    do {
        std::cout << "Inserire un numero intero maggiore di zero: ";
        std::cin >> num;
        if (num <= 0) {
            std::cout << "Attenzione: occorre immettere un numero positivo" << std::endl;
        }
    } while (num <= 0);

    // Calcolo del numero di cifre
    while (num > 0) {
        num = num / 10;
        contacifre++;
    }

    // Produzione dell'output
    if (contacifre > 1)
        std::cout << "Il numero immesso ha " << contacifre << " cifre!" << std::endl;
    else
        std::cout << "Il numero immesso ha una cifra!" << std::endl;

    return 0;
}
