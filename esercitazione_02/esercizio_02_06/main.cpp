#include <iostream>

int main ()
{
	int numero_righe = 0, numero_colonne = 0;
	int test = 0;

	std::cout << "Inserire il numero di righe di una tabella: ";
	std::cin >> numero_righe;
	std::cout << "Inserire il numero di colonne di una tabella: ";
	std::cin >> numero_colonne;

	test = !((numero_righe == 1) || (numero_colonne == 1) || ((numero_righe == 1) && (numero_colonne == 1)));

	std::cout << "Ora stampo 0 se la tabella ha una sola riga oppure una sola colonna oppure un solo elemento" << std::endl;
	std::cout << "Altrimenti stampo un numero diverso da 0." << std::endl;
	std::cout << "Risultato: " << test << std::endl;

	return 0;
}
