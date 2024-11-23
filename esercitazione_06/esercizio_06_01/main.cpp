#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    // Definizione dell'array
    const int dim = 30;
    int arr[dim] = {0};

    // Inizializzazione con numeri casuali tra 0 e 199
    srand(time(NULL));
    for (int i = 0; i < dim; i++){
        arr[i] = rand() % 100;
    }

    // Stampa dell'array
    std::cout << "Ecco l'array inizializzato con numeri casuali:" << std::endl << "[";
    for (int j = 0; j < dim - 1; j++){
        std::cout << arr[j] << ", ";
    }
    std::cout << arr[dim - 1] << "]" << std::endl;

    return 0;
}
