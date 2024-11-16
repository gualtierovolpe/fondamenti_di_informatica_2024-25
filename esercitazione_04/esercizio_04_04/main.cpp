#include <iostream>

int main () {
	double x = 0.0, sum = 0.0;
	int counter = 0;
	char stop = ' ';

	// Acquisizione della sequenza di numeri
	do {

		// Acquisizione di un numero
		std::cout << "Immettere un numero: ";
		std::cin >> x;

		// Aggiornamento della somma dei numeri immessi e del contatore dei numeri immessi
		sum += x;
		counter++;

		// Verifica della conclusione della sequenza
		do {
			std::cout << "Vuoi immettere un altro numero (s/n)? ";
			std::cin >> stop;
			if (stop != 's' && stop != 'S' && stop != 'n' && stop != 'N') {
				std::cout << "Attenzione! Digita 's' se vuoi immettere un altro numero o 'n' per terminare." << std::endl;
			}
		} while (stop != 's' && stop != 'S' && stop != 'n' && stop != 'N');

	} while (stop == 's' || stop == 'S');

	// Calcolo e stampa della media
	double mean = sum / double(counter);
	std::cout << "La media dei numeri immessi e': " << mean << std::endl;

	return 0;
}
