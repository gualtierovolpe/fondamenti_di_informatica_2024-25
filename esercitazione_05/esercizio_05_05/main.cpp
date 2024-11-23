#include <iostream>

int primo(int n) {
	int i = 2;
	while (i <= n/2) {
		if (n % i == 0)
			return 0;
		i++;
	}
	return 1;
}

int main () {
    int numero = 0, risultato = 0;
	char continua = 's';

	do {
		// Acquisizione del numero
		std::cout << "Immettere un numero intero positivo: ";
		std::cin >> numero;
		std::cout << std::endl;

		// Verifica che sia positivo
		if (numero > 0) {

			// Verifica che sia primo
			risultato = primo(numero);

			// Visualizzazione del risultato
			if (risultato)
				std::cout << numero << " e' un numero primo" << std::endl;
			else
				std::cout << numero << " non e' un numero primo" << std::endl;
		}
		else
			std::cout << "Attenzione: bisogna inserire un numero positivo." << std::endl;

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
