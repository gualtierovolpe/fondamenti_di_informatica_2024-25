#include <iostream>
#include <cmath>

int potenza(int n, int b, int& e, int& m) {
	e = 0;
	m = 1;

	if (n <= 0 || b <= 1)
		return -1;

	while (m <= n) {
		e++;
		m *= b;
	}

	return 0;
}

int main () {
    int numero_input = 0, base = 0;
    int numero_output = 1, esponente = 0, risultato = 0;
	char continua = 's';

	do {
		// Acquisizione del numero e della base
		std::cout << "Immettere un numero intero positivo: ";
		std::cin >> numero_input;
		std::cout << "Immettere una base: ";
		std::cin >> base;
		std::cout << std::endl;

		risultato = potenza(numero_input, base, esponente, numero_output);

		// Verifica che sia positivo
		if (risultato != 0)
			std::cout << "Attenzione: numero e base devono essere positivi; la base deve inoltre essere diversa da 1." << std::endl;

		else {
			// Visualizzazione del risultato
			std::cout << "L'esponente della piu' piccola potenza di " << base
				<< " il cui valore e' maggiore di " << numero_input << " e' " << esponente << std::endl;
			std::cout << "Il valore della piu' piccola potenza di " << base
				<< " il cui valore e' maggiore di " << numero_input << " e' " << numero_output << std::endl;
		}

		do {
			std::cout << std::endl;
			std::cout << "Inserire un altro numero (s/n)? ";
			std::cin >> continua;
			std::cout << std::endl;
			if ((continua != 's') && (continua != 'n'))
				std::cout << "Attenzione: inserire s per continuare, n per uscire" << std::endl;
		} while ((continua != 's') && (continua != 'n'));

	} while (continua != 'n');

	return 0;
}
