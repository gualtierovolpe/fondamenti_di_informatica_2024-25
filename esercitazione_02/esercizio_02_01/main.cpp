#include <iostream>

int main ()
{
	const int secondi_in_settimana = 60 * 60 * 24 * 7;
	const int secondi_in_giorno = 60 * 60 * 24;
	const int secondi_in_ora = 60 * 60;
	const int secondi_in_minuto = 60;

	int durata = 0;
	int settimane = 0, ore = 0, giorni = 0, minuti = 0, secondi = 0;

	std::cout << "Inserire una durata in secondi: ";
	std::cin >> durata;
	std::cout << std::endl;

	// Calcolo del numero di settimane
	settimane = durata / secondi_in_settimana;
	durata = durata % secondi_in_settimana;

	// Calcolo del numero di giorni
	giorni = durata / secondi_in_giorno;
	durata = durata % secondi_in_giorno;

	// Calcolo del numero di ore
	ore = durata / secondi_in_ora;
	durata = durata % secondi_in_ora;

	// Calcolo del numero di minuti
	minuti = durata / secondi_in_minuto;
	durata = durata % secondi_in_minuto;

	// Calcolo del numero di secondi
	secondi = durata;

	std::cout << "La durata inserita corrisponde a: " << std::endl;
	std::cout << settimane << " settimane" << std::endl;
	std::cout << giorni << " giorni" << std::endl;
	std::cout << ore << " ore" << std::endl;
	std::cout << minuti << " minuti" << std::endl;
	std::cout << secondi << " secondi" << std::endl;

	return 0;
}
