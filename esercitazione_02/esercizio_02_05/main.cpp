#include <iostream>

int main ()
{
	int a = 0, b = 0;
	int temp = 0;

	std::cout << "Inserire un numero intero: ";
	std::cin >> a;
	std::cout << "Inserire un altro numero intero: ";
	std::cin >> b;

	// Utilizziamo la variabile temporanea temp per operare lo scambio
	temp = a;
	a = b;
	b = temp;

	std::cout << "Ecco il nuovo valore del primo numero: " << a << std::endl;
	std::cout << "Ecco il nuovo valore del secondo numero: " << b << std::endl;

	return 0;
}

