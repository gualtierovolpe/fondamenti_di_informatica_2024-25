#include <iostream>

int inverti(int n) {
	int m = 0;
	while (n >= 1) {
		m = (m * 10) + (n % 10);
		n /= 10;
	}
	return m;
}

int main () {
    int numero, risultato = 0;
	char continua = 's';

	do {
		// Acquisizione del numero
		std::cout << "Immettere un numero intero positivo: ";
		std::cin >> numero;
		std::cout << std::endl;

		// Verifica che sia positivo
		if (numero > 0) {

			// Inversione delle cifre
			risultato = inverti(numero);

			// Visualizzazione del risultato
			std::cout << "Il numero a cifre invertite e' " << risultato << std::endl;

		}
		else
			std::cout << "Attenzione: bisogna inserire un numero positivo" << std::endl;

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
