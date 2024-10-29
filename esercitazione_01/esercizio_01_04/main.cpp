#include <iostream>

int main()
{
    int num1 = 0, num2 = 0, quoziente = 0, resto = 0;
    std::cout << "Inserisci il primo numero: ";
    std::cin >> num1;
    std::cout << "Inserisci un altro numero: ";
    std::cin >> num2;
    quoziente = num1 / num2;
    resto = num1 % num2;
    std::cout << "La divisione tra i due numeri ha come quoziente " << quoziente <<
        " e come resto " << resto << std::endl;
    return 0;
}
