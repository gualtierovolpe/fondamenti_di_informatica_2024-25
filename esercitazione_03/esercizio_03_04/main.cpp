#include <iostream>

int main () {

	// Acqusizione del mese e dell'anno
	int mese, anno;
	std::cout << "Inserire mese e anno" << std::endl;
	std::cout << "Mese: ";
	std::cin >> mese;
	std::cout << "Anno: ";
	std::cin >> anno;
	std::cout << std::endl;

	// Calcolo del numero di giorni
	switch (mese) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			std::cout << "Il mese indicato ha 31 giorni" << std::endl;
			break;
		case 4: case 6: case 9: case 11:
			std::cout << "Il mese indicato ha 30 giorni" << std::endl;
			break;
		case 2:
			// Verifica anno bisestile
			if (((anno % 4 == 0) && (anno % 100 != 0)) || (anno % 400 == 0))
				std::cout << "Il mese indicato ha 29 giorni" << std::endl;
			else
				std::cout << "Il mese indicato ha 28 giorni" << std::endl;
			break;
		default:
			std::cout << "Errore: per il mese hai indicato un numero non compreso tra 1 e 12" << std::endl;
	}

	return 0;
}
