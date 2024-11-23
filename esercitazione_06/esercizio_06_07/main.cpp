#include <iostream>

int main() {
    char c = 's';
    const int dim = 12;
    int a[dim];
    int b[dim];

    do {
        // Acquisizione dell'input
        std::cout << "Inserire i 12 elementi di un array" << std::endl;
        for (int i = 0; i < dim; i++) {
            std::cout << "Elemento " << i + 1 << ": ";
            std::cin >> a[i];
        }

        // Elaborazione dell'array
        b[0] = 1;
        for (int k = dim - 1; k > 0; k--)
            b[k] = a[k - 1] * a[k + 1];
        b[dim - 1] = 1;

        // Visualizzazione dell'output
        std::cout << "Array elaborato: [";
            for (int j = 0; j < dim - 1; j++)
                std::cout << b[j] << ", ";
        std::cout << b[dim - 1] << "]" << std::endl;

        do {
            std::cout << "Vuoi continuare (s/n)? ";
            std::cin >> c;
            if (c != 's' && c != 'n')
                std::cout << "Attenzione: Inserire s o n" << std::endl;
        } while (c != 's' && c != 'n');

    } while (c != 'n');

    return 0;
}
