#include <iostream>

int main() {

    // Acquisizione dei valori di giorno e mese
    int giorno = 0, mese = 0;
    std::cout << "Inserire due numeri interi (giorno e mese)" << std::endl;
    std::cout << "Giorno: ";
    std::cin >> giorno;
    std::cout << "Mese: ";
    std::cin >> mese;

    // Verifica della validita' dei dati
    if (giorno <= 0 || giorno > 31 || mese <= 0 || mese > 12) {
   		std::cout << "Errore: dati inseriti non validi!" << std::endl;
   		return -1;
   	}

   	// Calcolo della stagione
    switch (mese) {
    	case 1: case 2:
    	    std::cout << "Inverno" << std::endl;
    	    break;
    	case 3:
    	    if (giorno < 21)
                std::cout << "Inverno" << std::endl;
            else
                std::cout << "Primavera" << std::endl;
            break;
    	case 4: case 5:
    	    std::cout << "Primavera" << std::endl;
    	    break;
    	case 6:
    	    if (giorno < 21)
                std::cout << "Primavera" << std::endl;
            else
                std::cout << "Estate" << std::endl;
            break;
    	case 7: case 8:
    	    std::cout << "Estate" << std::endl;
    	    break;
    	case 9:
    	    if (giorno < 23)
                std::cout << "Estate" << std::endl;
            else
                std::cout << "Autunno" << std::endl;
            break;
    	case 10: case 11:
    	    std::cout << "Autunno" << std::endl;
    	    break;
    	case 12:
    	    if (giorno < 22)
                std::cout << "Autunno" << std::endl;
            else
                std::cout << "Inverno" << std::endl;
            break;
    }

	return 0;
}
