#include <iostream>

int main()
{
    int euro = 0, lire = 0;
    const int conv = 1936;
    std::cout << "Inserisci il prezzo in euro: ";
    std::cin >> euro;
    lire = euro * conv;
    std::cout << "Il prezzo immesso equivale a " << lire << " lire!" << std::endl;
    return 0;
}
