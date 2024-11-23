#include <iostream>

int verifica_intervallo(double a[], int d, double x, double y) {
	if (x < y) {
		int contatore = 0;
		for (int k = 0; k < d; k++)
			if ((a[k] < x) || (a[k] > y)) {
				a[k] = 0;
				contatore++;
			}
		return contatore;
	}
	return -1;
}

int main() {
	const int dim = 6;
	double a[dim] = {10.0, 5.2, -1.5, 8.0, 3.4, 12.1};

	// Visualizzazione dell'array originale
	std::cout << "Array originale: [";
	for (int i = 0; i < dim - 1; i++)
		std::cout << a[i] << ", ";
	std::cout << a[dim - 1] << ']' << std::endl;

	// Chiamata della funzione
	int risultato = verifica_intervallo(a, dim, 3, 8);

	// Visualizzazione dell'array elaborato
	std::cout << "Nuovo array: [";
	for (int i = 0; i < dim - 1; i++)
		std::cout << a[i] << ", ";
	std::cout << a[dim - 1] << ']' << std::endl;

	std::cout << risultato << " elementi posti a 0." << std::endl;

	return 0;
}
