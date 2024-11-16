#include <iostream>

int main() {

    double peso = 0.0;
    double peso_in_grammi = 0.0;
    char um = ' ';

    while(1) {

        // Acquisizione dell'input
        std::cout << "Inserire il valore di un peso: ";
        std::cin >> peso;
        if (peso < 0)
            break;
        std::cout << "Inserire l'unita' di misura del peso: ";
        std::cin >> um;

        // Calcolo dell'equivalente in grammi
        switch (um) {
        case 'm':
            peso_in_grammi = peso / 1000;
            break;
        case 'g':
            std::cout << "Il peso e' gia' espresso in grammi" << std::endl;
            continue;
        case 'h':
            peso_in_grammi = peso * 100;
            break;
        case 'k':
            peso_in_grammi = peso * 1000;
            break;
        default:
            std::cout << "Attenzione, inserisci m oppure g, oppure h, oppure k" << std::endl;
            continue;
        }

        // Stampa dell'output
        std::cout << "Il peso equivalente in grammi vale " << peso_in_grammi << std::endl;
    }

    return 0;
}
