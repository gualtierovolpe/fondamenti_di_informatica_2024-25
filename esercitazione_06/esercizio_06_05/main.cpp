#include <iostream>

int occorrenze(int a[], int n, int b[10]) {
    // Inizializzazione degli elementi di b a 0
	for (int h = 0; h < 10; h++)
		b[h] = 0;

    // Calcolo del numero di occorrenze
	int r = 0;
	for (int k = 0; k < n; k++) {
		int n = a[k];
		if (n >= 0 && n <= 9)
			b[n]++;
		else
			r = -1;
	}

	return r;
}

int main() {
	const int dim = 12;
	int arr[dim] = {1, 9, 5, 5, 5, 2, 8, 1, 0, 3, 2, 3};
	int b[10];

	// Chiamata della funzione
	int risultato = occorrenze(arr, dim, b);

	// Visualizzazione dell'output
	std::cout << "Le occorrenze dei valori di a = [ ";
	for (int k = 0; k < dim; k++)
		std::cout << arr[k] << " ";
	std::cout << "]" << std::endl;

	std::cout << "sono b = [";
	for (int h = 0; h < 10; h++)
		std::cout << b[h] << " ";
	std::cout << "]" << std::endl;

	if (risultato != 0)
		std::cout << "Attenzione: almeno un elemento di a non appartiene all'intervallo [0, 9]" << std::endl;
	else
		std::cout << "Tutti gli elementi di a appartengono all'intervallo [0, 9]" << std::endl;

	return 0;
}
