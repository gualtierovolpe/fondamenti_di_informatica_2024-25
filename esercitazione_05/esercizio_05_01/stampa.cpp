#include <iostream>
#include <iomanip>
#include "stampa.h"

void stampa_data(int giorno, int mese, int anno)
{
    std::cout << std::setw(2) << std::setfill('0') << giorno << "/";
    std::cout << std::setw(2) << std::setfill('0') <<  mese << "/";
    std::cout << std::setw(4) << std::setfill('0') << anno;
}

void stampa_ora(int ora, int minuto, int secondo) {
    std::cout << std::setw(2) << std::setfill('0') << ora << ":";
    std::cout << std::setw(2) << std::setfill('0') <<  minuto << ":";
    std::cout << std::setw(2) << std::setfill('0') << secondo;
}

void stampa_pattern(int righe, int colonne, char simbolo) {

    for (int i = 1; i <= righe; i++) {
        for (int j = 1; j <= colonne; j++)
            std::cout << simbolo;
        std::cout << std::endl;
    }
}
