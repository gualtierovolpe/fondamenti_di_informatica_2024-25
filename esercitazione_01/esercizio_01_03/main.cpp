#include <iostream>

int main()
{
    int cateto1 = 0, cateto2 = 0, quadrato_ipotenusa = 0;
    std::cout << "Inserisci la lunghezza di un cateto: ";
    std::cin >> cateto1;
    std::cout << "Inserisci la lunghezza del secondo cateto: ";
    std::cin >> cateto2;
    quadrato_ipotenusa = cateto1 * cateto1 + cateto2 * cateto2;
    std::cout << "Il quadrato dell'ipotenusa vale " << quadrato_ipotenusa << std::endl;
    return 0;
}
