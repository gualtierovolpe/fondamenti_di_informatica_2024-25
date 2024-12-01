#include <iostream>

const int d = 3;

void stampa_matrice(double M[d][d]) {
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            std::cout << M[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

double traccia(double M[d][d]) {
	double somma = 0.0;
	for (int k = 0; k < d; k++) {
		somma += M[k][k];
	}
	return somma;
}

int main () {
	double A[d][d] = {1, 1, 2, 0, 2, 1, 3, 4, 3};

	std::cout << "La traccia della matrice" << std::endl << std::endl;
    stampa_matrice(A);
	std::cout << std::endl;
	std::cout << "vale " << traccia(A) << std::endl << std::endl;

	return 0;
}
