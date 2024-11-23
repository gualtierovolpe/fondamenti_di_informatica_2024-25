#include <iostream>
#include <cmath>

double distanza(double x1, double y1, double x2, double y2) {
	double a = x1 * x1 - 2 * x1 * x2 + x2 * x2;
	double b = y1 * y1 - 2 * y1 * y2 + y2 * y2;
	return sqrt(a + b);
}

int main () {
    double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, d =0.0;
	char continua = 's';

	do {
		// Acquisizione delle coordinate dei punti
		std::cout << "Immettere le coordinate del primo punto: " << std::endl;
		std::cout << "x1: ";
		std::cin >> x1;
		std::cout << "y1: ";
		std::cin >> y1;
		std::cout << std::endl;
		std::cout << "Immettere le coordinate del secondo punto: " << std::endl;
		std::cout << "x2: ";
		std::cin >> x2;
		std::cout << "y2: ";
		std::cin >> y2;
		std::cout << std::endl;

		// Calcolo della distanza
		d = distanza(x1, y1, x2, y2);

		// Visualizzazione del risultato
		std::cout << "La distanza tra i due punti vale: " << d << std::endl;

		do {
			std::cout << std::endl;
			std::cout << "Calcolare un'altra distanza (s/n)? ";
			std::cin >> continua;
			std::cout << std::endl;
			if ((continua != 's') && (continua != 'n'))
				std::cout << "Attenzione: inserire s per continuare, n per uscire" << std::endl;
		} while ((continua != 's') && (continua != 'n'));

	} while (continua != 'n');

	return 0;
}
