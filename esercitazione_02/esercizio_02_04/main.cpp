#include <iostream>

int main ()
{
	int n = 0, m = 0;
	int uguali = 0;

	std::cout << "Inserire un numero intero: ";
	std::cin >> n;
	std::cout << "Inserire un altro numero intero: ";
	std::cin >> m;

	uguali = (n == m);

	std::cout << "Ora stampo 0 se i due numeri sono diversi o un numero diverso da 0 se sono uguali." << std::endl;
	std::cout << "Risultato: " << uguali << std::endl;

	return 0;
}

