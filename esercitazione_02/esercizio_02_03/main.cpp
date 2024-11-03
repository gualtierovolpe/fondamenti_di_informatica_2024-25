#include <iostream>

int main ()
{
	int n = 0;
	int precedente = 0, successivo = 0;

	std::cout << "Inserire un numero intero: ";
	std::cin >> n;

	// Calcolo del numero precedente
	precedente = --n;

	// Calcolo del numero successivo
	successivo = ++(++n);

	std::cout << "Il numero precedente e': " << precedente << std::endl;
	std::cout << "Il numero successivo e': " << successivo << std::endl;

	return 0;
}

