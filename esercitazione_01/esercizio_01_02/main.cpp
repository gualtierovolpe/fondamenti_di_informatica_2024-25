#include <iostream>

int main()
{
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, media = 0;
    std::cout << "Inserisci il primo numero: ";
    std::cin >> num1;
    std::cout << "Inserisci il secondo numero: ";
    std::cin >> num2;
    std::cout << "Inserisci il terzo numero: ";
    std::cin >> num3;
    std::cout << "Inserisci il quarto numero: ";
    std::cin >> num4;
    std::cout << "Inserisci il quinto numero: ";
    std::cin >> num5;
    media = (num1 + num2 + num3 + num4 + num5) / 5;
    std::cout << "La media dei 5 numeri immessi vale " << media << std::endl;
    return 0;
}
