#include <iostream>

const int num_righe = 4;
const int num_colonne = 5;
const int num_righe_out = 2;

void riempi_matrice(double M[num_righe][num_colonne]) {
   for (int i = 0; i < num_righe; i++) {
        std::cout << "Riga " << i + 1 << std::endl;
        for (int j = 0; j < num_colonne; j++){
            std::cout << "Colonna " << j + 1 << ": ";
            std::cin >> M[i][j];
        }
   }
}

void stampa_matrice(int M[num_righe_out][num_colonne]) {
    for (int i = 0; i < num_righe_out; i++) {
        for (int j = 0; j < num_colonne; j++) {
            std::cout << M[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void intervalli(double M[num_righe][num_colonne], double a, double b, int P[2][num_colonne]) {
    for (int k = 0; k < num_colonne; k ++) {
        int num_compresi = 0;
        for (int h = 0; h < num_righe; h++) {
            if (M[h][k] >= a && M[h][k] <= b)
            num_compresi++;
        }
        P[0][k] = num_compresi;
        P[1][k] = num_righe - num_compresi;
    }
}

int main() {
    double M[num_righe][num_colonne] = {0};
    double a, b;
    int P[num_righe_out][num_colonne] = {0};

    // Acquisizione dell'input
    std::cout << "Inserire gli elementi di M" << std::endl;
    riempi_matrice(M);
    std::cout << std::endl << "Inserire a e b" << std::endl;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;

    // Chiamata della funzione
    intervalli(M, a, b, P);

    // Visualizzazione dell'output
    std::cout << std::endl << "Matrice P: " << std::endl;
    stampa_matrice(P);
    std::cout << std::endl;

    return 0;
}
