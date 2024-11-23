#include <iostream>
#include "stampa.h"

int main() {

    // Intestazione
    stampa_pattern(2, 30, '*');
    std::cout << std::endl;
    std::cout << "Impostazione di un evento" << std::endl;
    std::cout << std::endl;
    stampa_pattern(2, 30, '*');

    // Acquisizione input
    int g = 0, ms = 0, a = 0, h = 0, mn = 0, s = 0;
    std::cout << std::endl;
    std::cout << "Inserire la data" << std::endl;
    std::cout << "Giorno: ";
    std::cin >> g;
    std::cout << "Mese: ";
    std::cin >> ms;
    std::cout << "Anno: ";
    std::cin >> a;
    std::cout << std::endl;
    std::cout << "Inserire l'ora" << std::endl;
    std::cout << "Ora: ";
    std::cin >> h;
    std::cout << "Minuto: ";
    std::cin >> mn;
    std::cout << "Secondo: ";
    std::cin >> s;
    std::cout << std::endl;

    // Conferma inserimento
    stampa_pattern(2, 30, '*');
    std::cout << std::endl;
    std::cout << "Evento inserito" << std::endl;
    std::cout << std::endl;
    std::cout << "Data: ";
    stampa_data(g, ms, a);
    std::cout << std::endl;
    std::cout << "Ora: ";
    stampa_ora(h, mn, s);
    std::cout << std::endl;
    std::cout << std::endl;
    stampa_pattern(2, 30, '*');

    return 0;
}
