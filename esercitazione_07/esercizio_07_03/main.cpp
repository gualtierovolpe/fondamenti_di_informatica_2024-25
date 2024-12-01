#include <iostream>

// Semplificato a 4 squadre e 6 giornate per inserire più agevolmente i dati manualmente
const int n = 4;
const int m = 6;

void riempi_matrice(int M[n][m]) {
   for (int i = 0; i < n; i++) {
        std::cout << "Riga " << i + 1 << std::endl;
        for (int j = 0; j < m; j++){
            std::cout << "Colonna " << j + 1 << ": ";
            std::cin >> M[i][j];
        }
   }
}

int capolista(int M[n][m], int k) {
    if (k>= 0 && k < m) {
        // Suppongo che la capolista sia la prima squadra
        int punti_prima = 0;
		int prima_classificata = 0;
		for (int h = 0; h < k; h++)
			punti_prima += M[0][h];

        // Se ne trovo una migliore aggiorno la capolista
		int punti = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < k; j++)
				punti += M[i][j];
			if (punti > punti_prima) {
				punti_prima = punti;
				prima_classificata = i;
			}
			punti = 0;
		}
		return prima_classificata;
	}

	return -1;
}

int main() {
	int C[n][m] = {0};
    int g = 0;

    //Acquisizione dell'input
	riempi_matrice(C);
	do {
        std::cout << "Inserire un numero intero (giornata da considerare): ";
        std::cin >> g;
        if (g <= 0 || g > m) {
            std::cout << "Attenzione: la giornata deve essere compresa tra 1 e " << n << std::endl;
        }
	} while (g <= 0 || g > m);

	// Chiamata della funzione
	int prima = capolista(C, g - 1);

	// Visualizzazione del risultato
    std::cout << "Squadra prima classificata: " << prima + 1 << std::endl;

	return 0;
}
