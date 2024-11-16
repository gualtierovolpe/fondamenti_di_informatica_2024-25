#include <iostream>

int main() {
    int num = 0;
    int contapari = 0;
    int contadispari = 0;

    do {
        // Acquisizione dell'input
        std::cout << "Inserisci un numero intero maggiore di zero (zero o un numero negativo per terminare): ";
        std::cin >> num ;

        // Conteggio dei numeri pari e dispari
        if (num <= 0) {
            std::cout << "Grazie!" << std::endl;
        }
        else if (num % 2 == 0) {
            contapari++;
        }
        else {
            contadispari++;
        }
    } while (num > 0);

    std::cout << "Hai immesso " << contapari << " numeri pari!" << std::endl;
    std::cout << "Hai immesso " << contadispari << " numeri dispari!" << std::endl;

    return 0;
}
