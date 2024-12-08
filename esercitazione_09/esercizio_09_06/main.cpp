#include <iostream>
#include <cstring>

//////////////////////////////////////////////////////////////////////////////////////
// Strutture dati
//////////////////////////////////////////////////////////////////////////////////////

// Costanti
const int max_appartamenti = 100;

// Struttura per la memorizzazione dei dati relativi a un appartamento
struct appartamento {
	int codice;
	char indirizzo[100];
	char comune[32];
	int numero_vani;
	double superficie;
	double prezzo;
};

// Struttura per la memorizzazione degli appartamenti di una agenzia immobiliare
struct archivio_appartamenti {
	appartamento archivio[max_appartamenti];
	int num_appartamenti;
};


//////////////////////////////////////////////////////////////////////////////////////
// Funzioni per l'inizializzazione delle strutture dati
//////////////////////////////////////////////////////////////////////////////////////

// Inizializzazione di un appartamento
void inizializza_appartamento(appartamento& a) {
	a.codice = 0;
	strcpy(a.indirizzo, "");
	strcpy(a.comune, "");
	a.numero_vani = 0;
	a.superficie = 0.0;
	a.prezzo = 0.0;
}

// Inizializzazione dell'archivio di appartamenti
void inizializza_archivio(archivio_appartamenti& arch) {
	for (int k = 0; k < max_appartamenti; k++)
		inizializza_appartamento(arch.archivio[k]);
	arch.num_appartamenti = 0;
}


//////////////////////////////////////////////////////////////////////////////////////
// Funzioni per l'inserimento dei dati
//////////////////////////////////////////////////////////////////////////////////////

// Inserimento dei dati di un appartamento
void inserisci_dati_appartamento(appartamento& a) {
	std::cout << "Inserire il codice dell'appartamento: ";
	std::cin >> a.codice;
	std::cout << std::endl;

	// cleaning
	std::cin.clear();
	std::cin.sync();

	std::cout << "Inserire l'indirizzo dell'appartamento: ";
	std::cin.getline(a.indirizzo, 100, '\n');
	std::cout << std::endl;

	std::cout << "Inserire il comune: ";
	std::cin.getline(a.comune, 32, '\n');
	std::cout << std::endl;

	do {
		std::cout << "Inserire il numero di vani: ";
		std::cin >> a.numero_vani;
		std::cout << std::endl;
		if (a.numero_vani <= 0)
			std::cout << "Attenzione: il numero di vani deve essere un numero positivo" << std::endl << std::endl;
	} while (a.numero_vani <= 0);

	do {
		std::cout << "Inserire la superficie (in mq.): ";
		std::cin >> a.superficie;
		std::cout << std::endl;
		if (a.superficie <= 0)
			std::cout << "Attenzione: la superficie deve essere un numero positivo" << std::endl << std::endl;
	} while (a.superficie <= 0);

	do {
		std::cout << "Inserire il prezzo (in Euro): ";
		std::cin >> a.prezzo;
		std::cout << std::endl;
		if (a.prezzo <= 0)
			std::cout << "Attenzione: il prezzo deve essere un numero positivo" << std::endl << std::endl;
	} while (a.prezzo <= 0);
}

// Inserimento di un appartamento nell'archivio
int inserisci_appartamento(archivio_appartamenti& arch, appartamento a) {
	if (arch.num_appartamenti < max_appartamenti) {
		arch.archivio[arch.num_appartamenti] = a;
		arch.num_appartamenti++;
		return 1;
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////
// Funzioni per la stampa dei dati
//////////////////////////////////////////////////////////////////////////////////////

// Stampa di un appartamento
void stampa_dati_appartamento(appartamento a) {
	std::cout << "Codice: " << a.codice << std::endl;
	std::cout << "Indirizzo: " << a.indirizzo << std::endl;
	std::cout << "Comune: " << a.comune << std::endl;
	std::cout << "Numero di vani: " << a.numero_vani << std::endl;
	std::cout << "Superficie: " << a.superficie << std::endl;
	std::cout << "Prezzo: " << a.prezzo << std::endl << std::endl;
}

// Stampa dell'archivio di appartamenti
void stampa_archivio(const archivio_appartamenti& arch) {
	for (int k = 0; k < arch.num_appartamenti; k++)
		stampa_dati_appartamento(arch.archivio[k]);
}


//////////////////////////////////////////////////////////////////////////////////////
// Funzioni per l'elaborazione dei dati
//////////////////////////////////////////////////////////////////////////////////////

// Calcolo del prezzo minimo degli appartamenti in vendita
double calcola_prezzo_minimo(const archivio_appartamenti& arch) {
	if (arch.num_appartamenti > 0) {
		double minimo = arch.archivio[0].prezzo;
		for (int k = 0; k < arch.num_appartamenti; k++)
			if (arch.archivio[k].prezzo < minimo)
				minimo = arch.archivio[k].prezzo;
		return minimo;
	}
	return 0.0;
}

// Calcolo del prezzo massimo degli appartamenti in vendita
double calcola_prezzo_massimo(const archivio_appartamenti& arch) {
	if (arch.num_appartamenti > 0) {
		double massimo = arch.archivio[0].prezzo;
		for (int k = 0; k < arch.num_appartamenti; k++)
			if (arch.archivio[k].prezzo > massimo)
				massimo = arch.archivio[k].prezzo;
		return massimo;
	}
	return 0.0;
}

// Calcolo del prezzo medio degli appartamenti in vendita
double calcola_prezzo_medio(const archivio_appartamenti& arch) {
	if (arch.num_appartamenti > 0) {
		double somma = 0.0;
		for (int k = 0; k < arch.num_appartamenti; k++)
			somma += arch.archivio[k].prezzo;
		return somma / double(arch.num_appartamenti);
	}
	return 0.0;
}

// Calcolo del prezzo medio degli appartamenti la cui superficie e' compresa tra un valore minimo e un valore massimo
double calcola_prezzo_medio_superficie(const archivio_appartamenti& arch, double sup_min, double sup_max) {
	if ((arch.num_appartamenti > 0) && (sup_max >= sup_min)) {
		double somma = 0.0, contatore = 0.0;
		for (int k = 0; k < arch.num_appartamenti; k++) {
			if ((arch.archivio[k].superficie >= sup_min) && (arch.archivio[k].superficie <= sup_max)) {
				somma += arch.archivio[k].prezzo;
				contatore++;
			}
		}
		if (contatore > 0)
			return somma / contatore;
	}
	return 0.0;
}

// Calcolo dell'istogramma del numero di vani degli appartamenti in vendita
void calcola_istogramma_vani(const archivio_appartamenti& arch, int istogramma[9]) {
	for (int i = 0; i < 9; i++)
		istogramma[i] = 0;
	for (int k = 0; k < arch.num_appartamenti; k++) {
		int numero_vani = arch.archivio[k].numero_vani;
		if (numero_vani > 8)
			istogramma[8]++;
		else
			istogramma[numero_vani - 1]++;
	}
}

// Stampa dell'istogramma del numero di vani degli appartamenti in vendita
void stampa_istogramma_vani(const int istogramma[9]) {
	std::cout << "Numero di appartamenti per numero di vani:" << std::endl;
	std::cout << "Monolocali (1 vano): " << istogramma[0] << std::endl;
	std::cout << "Bilocali (2 vani): " << istogramma[1] << std::endl;
	std::cout << "Trlocali (3 vani): " << istogramma[2] << std::endl;
	for (int k = 3; k < 8; k++)
		std::cout << k + 1 << " vani: " << istogramma[k] << std::endl;
	std::cout << "Piu' di 8 vani: " << istogramma[8] << std::endl;
	std::cout << std::endl;
}

// Stampa dei dati relativi agli appartamenti con un dato numero di vani
void stampa_selezione_vani(const archivio_appartamenti& arch, int num_vani) {
	if ((num_vani > 0) && (arch.num_appartamenti > 0)) {
		int contatore = 0;
		for (int k = 0; k < arch.num_appartamenti; k++) {
			if (arch.archivio[k].numero_vani == num_vani) {
				stampa_dati_appartamento(arch.archivio[k]);
				contatore++;
			}
		}
		if (contatore == 0)
			std::cout << "Non vi sono appartamenti di " << num_vani << " vani" << std::endl << std::endl;
	}
	else
		std::cout << "Attenzione: l'archivio e' vuoto o e' stato inserito un valore negativo per il numero di vani." << std::endl << std::endl;
}

// Stampa dei dati relativi agli appartamenti il cui prezzo e' compreso tra un valore minimo e un valore massimo
void stampa_selezione_prezzo(const archivio_appartamenti& arch, double prezzo_minimo, double prezzo_massimo) {
	if ((arch.num_appartamenti > 0) && (prezzo_massimo >= prezzo_minimo)) {
		int contatore = 0;
		for (int k = 0; k < arch.num_appartamenti; k++) {
			if ((arch.archivio[k].prezzo >= prezzo_minimo) && (arch.archivio[k].prezzo <= prezzo_massimo)) {
				stampa_dati_appartamento(arch.archivio[k]);
				contatore++;
			}
		}
		if (contatore == 0)
			std::cout << "Non vi sono appartamenti con prezzo compreso tra " << prezzo_minimo << " e " << prezzo_massimo << " Euro" << std::endl << std::endl;
	}
	else
		std::cout << "Attenzione: l'archivio e' vuoto o e' il prezzo massimo inserito e' inferiore al prezzo minimo." << std::endl << std::endl;
}


//////////////////////////////////////////////////////////////////////////////////////
// Funzione main
//////////////////////////////////////////////////////////////////////////////////////

int main() {
	archivio_appartamenti arch;
	inizializza_archivio(arch);

	appartamento a;

	double sup_min, sup_max;
	double prezzo_medio = 0.0;
	double prezzo_min, prezzo_max;
	int numero_vani;
	int istogramma[9];

	int continua = 1;

	do {
		std::cin.clear();
		std::cin.sync();

		// Stampa del menu'
		int scelta = 0;
		std::cout << "Operazioni disponibili: " << std::endl;
		std::cout << "1 - Inserimento di un nuovo appartamento" << std::endl;
		std::cout << "2 - Calcolo del prezzo minimo, medio e massimo" << std::endl;
		std::cout << "3 - Calcolo del prezzo medio degli appartamenti con superficie compresa tra due estremi prefissati" << std::endl;
		std::cout << "4 - Calcolo del numero di appartamenti composti da diversi numeri di vani" << std::endl;
		std::cout << "5 - Stampa degli appartamenti composti da un dato numero di vani" << std::endl;
		std::cout << "6 - Stampa degli appartamenti con prezzo compreso tra due estremi prefissati" << std::endl;
		std::cout << "7 - Esci" << std::endl << std::endl;
		std::cout << "Selezionare un'opzione: ";
		std::cin >> scelta;
		system("cls");

		switch (scelta) {
			// Inserimento di un nuovo appartamento
			case 1:
				inserisci_dati_appartamento(a);
				if (inserisci_appartamento(arch, a))
					std::cout << "Nuovo appartamento inserito" << std::endl << std::endl;
				else
					std::cout << "E' stato raggiunto il massimo numero di appartamenti. Non si possono inserire ulteriori appartamenti" << std::endl << std::endl;
				system("pause");
				system("cls");
				break;
			// Calcolo del prezzo minimo, medio e massimo
			case 2:
				std::cout << "Prezzo minimo: " << calcola_prezzo_minimo(arch) << std::endl;
				std::cout << "Prezzo medio: " << calcola_prezzo_medio(arch) << std::endl;
				std::cout << "Prezzo massimo: " << calcola_prezzo_massimo(arch) << std::endl << std::endl;
				system("pause");
				system("cls");
				break;
			// Calcolo del prezzo medio degli appartamenti con superficie compresa tra due estremi prefissati
			case 3:
				std::cout << "Inserire la superficie minima: ";
				std::cin >> sup_min;
				std::cout << "Inserire la superficie massima: ";
				std::cin >> sup_max;
				system("cls");
				prezzo_medio = calcola_prezzo_medio_superficie(arch, sup_min, sup_max);
				std::cout << "Prezzo medio degli appartamenti con superficie compresa tra " << sup_min << " e " << sup_max << " mq: " << prezzo_medio << std::endl << std::endl;
				system("pause");
				system("cls");
				break;
			// Calcolo del numero di appartamenti composti da diversi numeri di vani
			case 4:
				calcola_istogramma_vani(arch, istogramma);
				stampa_istogramma_vani(istogramma);
				system("pause");
				system("cls");
				break;
			// Stampa degli appartamenti composti da un dato numero di vani
			case 5:
				std::cout << "Inserire un numero di vani: ";
				std::cin >> numero_vani;
				system("cls");
				stampa_selezione_vani(arch, numero_vani);
				system("pause");
				system("cls");
				break;
			// Stampa dei dati relativi agli appartamenti il cui prezzo e' compreso tra un valore minimo e un valore massimo
			case 6:
				std::cout << "Inserire il prezzo minimo: ";
				std::cin >> prezzo_min;
				std::cout << "Inserire il prezzo massimo: ";
				std::cin >> prezzo_max;
				system("cls");
				stampa_selezione_prezzo(arch, prezzo_min, prezzo_max);
				system("pause");
				system("cls");
				break;
			// Uscita dal programma
			case 7:
				continua = 0;
				break;
			default:
				system("cls");
				std::cout << "Opzione non disponibile: inserire un numero tra 1 e 7" << std::endl << std::endl;
		}

	} while (continua);

	return 0;
}
