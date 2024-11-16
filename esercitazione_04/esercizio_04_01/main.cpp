#include <iostream>

int main() {

    int n = 0;
    char r = ' ';

    // Ciclo per ripetere l'esecuzione del programma
    do {

        // Immissione dell'input
        do {
            std::cout << "Inserire un numero positivo: ";
            std::cin >> n;
            if (n <= 0)
                std::cout << "Attenzione: occorre inserire un numero positivo" << std::endl;
        } while (n <= 0);

        // Caso n==1 trattato a parte
        if (n == 1) {
            std::cout << "Hai inserito il numero 1, l'unico fattore e' 1";
        }

        // Caso generale
        else {
            int i = 2;
            std::cout << "Scomposizione: ";
            while (n != 1) {

                while (n % i == 0) {
                    std::cout << i << " ";
                    n = n / i;
                }

                if (i == 2)
                    i++;
                else
                    i += 2;
            }
        }

        // Richiesta all'utente per continuare l'esecuzione del programma
        std::cout << std::endl << "Desideri continuare (s/n)? ";
        std::cin >> r;
    }
    while (r == 's');

    return 0;
}
