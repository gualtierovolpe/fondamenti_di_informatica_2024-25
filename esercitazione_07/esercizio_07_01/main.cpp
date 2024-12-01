#include <iostream>

const int dim = 3;

void riempi_matrice(int M[dim][dim]) {
   for (int i = 0; i < dim; i++) {
        std::cout << "Riga " << i + 1 << std::endl;
        for (int j = 0; j < dim; j++){
            std::cout << "Colonna " << j + 1 << ": ";
            std::cin >> M[i][j];
        }
   }
}

void stampa_matrice(int M[dim][dim]) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            std::cout << M[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void prodotto_matrici(int A[dim][dim], int B[dim][dim], int C[dim][dim]) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            C[i][j] = 0;
            for (int k = 0; k < dim; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
   int A[dim][dim] = {0}, B[dim][dim] = {0}, C[dim][dim] = {0};

   // Acquisizione dell'input
   std::cout << "Inserire gli elementi della matrice A" << std::endl;
   riempi_matrice(A);
   std::cout << std::endl << "La prima matrice e': " << std::endl;
   stampa_matrice(A);

   std::cout << std::endl << "Inserire gli elementi della matrice B" << std::endl;
   riempi_matrice(B);
   std::cout << std::endl << "La seconda matrice e': " << std::endl;
   stampa_matrice(B);

   // Calcolo del prodotto
   prodotto_matrici(A, B, C);

   // Visualizzazione del risultato
   std::cout << std::endl << "La matrice prodotto e': " << std::endl;
   stampa_matrice(C);

   return 0;
}

