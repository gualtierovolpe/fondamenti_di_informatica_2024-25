#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

const int dim = 5;

double differenza_medie_triangoli(int M[dim][dim]) {
    int somma_superiore = 0, somma_inferiore = 0;
    double media_superiore = 0.0, media_inferiore = 0.0;

    // Il numero di elementi nel triangolo superiore/inferiore
    // e' pari alla somma delle serie aritmetica tra 1 e dim
    const int num_elementi = dim * (dim + 1) / 2;

    // Calcolo della media degli elementi nel triangolo superiore
    for (int i = 0; i < dim; i++)
        for (int j = i; j < dim; j++)
            somma_superiore += M[i][j];
    media_superiore = double(somma_superiore) / num_elementi;

    // Calcolo della media degli elementi nel triangolo inferiore
    for (int i = 0; i < dim; i++)
        for (int j = 0; j <= i; j++)
            somma_inferiore += M[i][j];
    media_inferiore = double(somma_inferiore) / num_elementi;

    return abs(media_superiore - media_inferiore);
}

void inizializza_matrice_causale(int M[dim][dim]) {
    srand(time(NULL));
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            M[i][j] = rand() % 10;
}

int main() {
    const int d = 1000;
    int Q[dim][dim];

    double somma = 0.0;
    for (int i = 0; i < d; i++) {
        inizializza_matrice_causale(Q);
        somma += differenza_medie_triangoli(Q);
    }

    double media = somma / d;

    std::cout << "Valore medio della differenza assoluta su 1000 tentativi: " << media << std::endl;

    return 0;
}
