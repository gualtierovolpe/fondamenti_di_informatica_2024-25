#include <iostream>
#include <fstream>

int main() {
	const int dim = 10;
	double km[dim];

	// Inizializzazione dell'array km
	for (int k = 0; k < dim; k++)
		km[k] = 0.0;

    // Dichiarazione dello stream
	std::fstream fin;

	// Apertura del file
	fin.open("lavori.txt", std::ios::in);
    if (!fin) {
        std::cout << "Attenzione: non e' stato possibile aprire il file Lavori.txt" << std::endl;
        return -1;
    }

    // Elaborazione del file
	int num = 0;
	double km_inizio = 0.0, km_fine = 0.0, costo = 0.0;
	double costo_totale = 0.0, km_totali = 0.0, costo_km = 0.0;
	for (int i = 0; i < dim; i++) {
        fin >> num >> km_inizio >> km_fine >> costo;
		km[i] = km_fine - km_inizio;
        costo_totale += costo;
	}

	// Chiusura del file
	fin.close();

	// Calcolo della lunghezza totale delle tratte interessate dai lavori e del costo medio
	for (int h = 0; h < dim; h++)
		km_totali += km[h];
	costo_km = costo_totale / km_totali;

	// Visualizzazione del risultato
	std::cout << "Il costo medio per chilometro e' " << costo_km << std::endl;

    return 0;
}
