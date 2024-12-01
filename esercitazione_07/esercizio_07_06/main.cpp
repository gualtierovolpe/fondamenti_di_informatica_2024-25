#include <iostream>

const int nr1 = 4;
const int nr2 = 2;
const int nc = 3;

void riempi_matrice(double M[nr1][nc]) {
   for (int i = 0; i < nr1; i++) {
        std::cout << "Riga " << i + 1 << std::endl;
        for (int j = 0; j < nc; j++){
            std::cout << "Colonna " << j + 1 << ": ";
            std::cin >> M[i][j];
        }
   }
}

int main() {
    double M[nr1][nc] = {0};
    double X[nr2][nc] = {0};
    double Y[nr2][nc] = {0};

    // Acquisizione dell'input
    std::cout << "Inserire gli elementi di una matrice 4x3" << std::endl;
    riempi_matrice(M);

    // Elaborazione: matrice X
    double somma_x = 0.0;
    for (int i = 0; i < nr1; i+=2)
        for (int j = 0; j < nc; j++) {
            X[i / 2][j] = M[i][j];
            somma_x += X[i / 2][j];
        }

    // Elaborazione: matrice X
    double somma_y = 0.0;
    for (int m = 1; m < nr1; m += 2)
        for (int n = 0; n < nc; n++) {
            Y[m / 2][n] = M[m][n];
            somma_y += Y[m / 2][n];
    }

    // Visualizzazione del risultato
    std::cout << std::endl;
    std::cout << "Somma degli elementi della matrice X: " << somma_x << std::endl;
    std::cout << "Somma degli elementi della matrice Y: " << somma_y << std::endl;

    return 0;
}

