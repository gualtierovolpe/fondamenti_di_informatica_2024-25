#include <iostream>
#include <cstring>

//////////////////////////////////////////////////////////////////////////////////////
// Strutture dati
//////////////////////////////////////////////////////////////////////////////////////

// Costanti
const int max_esami = 100;
const int max_lunghezza_stringhe = 32;

// Struttura per la memorizzazione dei dati relativi a un esame
struct esame {
	char nome_studente[max_lunghezza_stringhe];
	char cognome_studente[max_lunghezza_stringhe];
	int numero_matricola;
	int voto;
};

// Struttura per la memorizzazione degli esami della sessione
struct sessione_di_esami {
	esame archivio_esami[max_esami];
	int num_esami;
};


//////////////////////////////////////////////////////////////////////////////////////
// Funzioni per l'inizializzazione delle strutture dati
//////////////////////////////////////////////////////////////////////////////////////

// Inizializzazione di un esame
void inizializza_esame(esame& e) {
	strcpy(e.nome_studente, "");	//Inizializza e.Nome con la stringa vuota ""
	strcpy(e.cognome_studente, "");
	e.numero_matricola = 0;
	e.voto = 0;
}

// Inizializzazione di una sessione di esami
void inizializza_sessione_esami(sessione_di_esami& sessione) {
	for (int k = 0; k < max_esami; k++)
		inizializza_esame(sessione.archivio_esami[k]);
	sessione.num_esami = 0;
}


//////////////////////////////////////////////////////////////////////////////////////
// Funzioni per l'inserimento dei dati
//////////////////////////////////////////////////////////////////////////////////////

// Inserimento dei dati di un esame
void inserisci_dati_esame(esame& e) {
	// cleaning
	std::cin.clear();
	std::cin.sync();

	std::cout << "Inserire il nome dello studente: ";
	std::cin.getline(e.nome_studente, 32, '\n');
	std::cout << std::endl;

	std::cout << "Inserire il cognome dello studente: ";
	std::cin.getline(e.cognome_studente, 32, '\n');
	std::cout << std::endl;

	std::cout << "Inserire il numero di matricola: ";
	std::cin >> e.numero_matricola;
	std::cout << std::endl;

	do {
		std::cout << "Inserire il voto di esame: ";
		std::cin >> e.voto;
		std::cout << std::endl;
		if ((e.voto > 30) || (e.voto < 18))
			std::cout << "Attenzione: il voto deve essere compreso tra 18 e 30." << std::endl << std::endl;
	} while ((e.voto > 30) || (e.voto < 18));
}

// Inserimento di un esame in una sessione
// Ritorna 1 se l'inserimento � riuscito, 0 altrimenti
int inserisci_esame(sessione_di_esami& sessione, esame e) {
	if (sessione.num_esami < max_esami) {
		sessione.archivio_esami[sessione.num_esami] = e;
		sessione.num_esami++;
		return 1;
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////
// Funzioni per la stampa dei dati
//////////////////////////////////////////////////////////////////////////////////////

// Stampa di un esame
void stampa_dati_esame(esame e) {
	std::cout << "Nome: " << e.nome_studente << std::endl;
	std::cout << "Cognome: " << e.cognome_studente << std::endl;
	std::cout << "Numero di matricola: " << e.numero_matricola << std::endl;
	std::cout << "Voto di esame: " << e.voto << std::endl << std::endl;
}

// Stampa di una sessione di esami
// const significa che s (passato per riferimento) non verr� modificato dalla funzione
// Passiamo s per riferimento per evitare il passaggio per valore che implica
// la copia di TUTTA la struttura dati, che pu� essere uno spreco di tempo(e memoria)!
void stampa_sessione(const sessione_di_esami& sessione) {
	for (int k = 0; k < sessione.num_esami; k++)
		stampa_dati_esame(sessione.archivio_esami[k]);
}


//////////////////////////////////////////////////////////////////////////////////////
// Funzioni per l'elaborazione dei dati
//////////////////////////////////////////////////////////////////////////////////////

// Calcolo della media dei voti di una sessione
double calcola_media_voti(const sessione_di_esami& sessione) {
	if (sessione.num_esami > 0) {
		double somma = 0.0;
		for (int k = 0; k < sessione.num_esami; k++)
			somma += sessione.archivio_esami[k].voto;
		return somma / sessione.num_esami;
	}
	return 0.0;
}

// Calcolo del numero di studenti con voto maggiore di n
int calcola_num_studenti(const sessione_di_esami& sessione, int n) {
	int contatore = 0;
	for (int k = 0; k < sessione.num_esami; k++)
		if (sessione.archivio_esami[k].voto > n)
			contatore++;
	return contatore;
}

// Calcolo dell'istogramma dei voti di esame di una sessione
void calcola_istogramma(const sessione_di_esami& sessione, int istogramma[13]) {
	for (int i = 0; i < 13; i++)
		istogramma[i] = 0;
	for (int k = 0; k < sessione.num_esami; k++) {
		int indice = sessione.archivio_esami[k].voto - 18;  // Riporta l'indice da 0 a 13 in base al voto
		istogramma[indice]++;
	}
}


//////////////////////////////////////////////////////////////////////////////////////
// Funzione main
//////////////////////////////////////////////////////////////////////////////////////

int main() {
	// Sessione di esami
	sessione_di_esami sessione;
	inizializza_sessione_esami(sessione);

	// Variabili ausiliarie per l'elaborazione dati
	esame e;
	inizializza_esame(e);
	double media = 0.0;
	int soglia = 18;
	int num_studenti = 0;
	int istogramma[13];

	// Variabile per la condizione di terminazione del programma
	int continua = 1;

	// Pulizia dei flussi in ingresso
	std::cin.clear();
	std::cin.sync();

	do {

		// Stampa del menu delle operazioni diponibili
		std::cout << "Operazioni disponibili: " << std::endl;
		std::cout << "1 - Inserire un nuovo esame" << std::endl;
		std::cout << "2 - Media dei voti conseguiti" << std::endl;
		std::cout << "3 - Numero di studenti con voto superiore ad una specifica soglia" << std::endl;
		std::cout << "4 - Istogramma dei voti conseguiti" << std::endl;
		std::cout << "5 - Esci" << std::endl << std::endl;
		std::cout << "Selezionare un'opzione: ";

		// Inserimento della scelta da parte dell'utente
		int scelta = 0;
		std::cin >> scelta;
		system("cls");

		// Esecuzione dell'operazione richiesta
		switch (scelta) {
			case 1:			// Inserimento di un nuovo esame
				inserisci_dati_esame(e);
				if (inserisci_esame(sessione, e))
					std::cout << "Nuovo esame inserito" << std::endl << std::endl;
				else
					std::cout << "E' stato raggiunto il massimo numero di esami per sessione. Non si possono inserire ulteriori esami" << std::endl << std::endl;
				system("pause");
				system("cls");
				break;
			case 2:			// Calcolo della media dei voti conseguiti
				media = calcola_media_voti(sessione);
				std::cout << "La media dei voti conseguiti e': " << media << std::endl << std::endl;
				system("pause");
				system("cls");
				break;
			case 3:			// Calcolo del numero di studenti che hanno conseguito un voto superiore ad una data soglia
				std::cout << "Inserire il voto di soglia: ";
				std::cin >> soglia;
				std::cout << std::endl;
				num_studenti = calcola_num_studenti(sessione, soglia);
				std::cout << num_studenti << " studenti hanno conseguito un voto maggiore o uguale a " << soglia << std::endl << std::endl;
				system("pause");
				system("cls");
				break;
			case 4:		// Calcolo dell'istogramma dei voti conseguiti
				calcola_istogramma(sessione, istogramma);
				std::cout << "Istogramma dei voti conseguiti:" << std::endl;
				for (int k = 0; k < 13; k++)
					std::cout << k + 18 << ": " << istogramma[k] << std::endl;
				std::cout << std::endl;
				system("pause");
				system("cls");
				break;
			case 5:		// Uscita dal programma
				continua = 0;
				break;
			default:	// Opzione non disponibile
				system("cls");
				std::cout << "Opzione non disponibile: inserire un numero tra 1 e 6" << std::endl << std::endl;
		}

	} while (continua);

	return 0;
}
