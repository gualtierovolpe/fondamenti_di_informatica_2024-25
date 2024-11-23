#include <iostream>

// Calcolo del massimo comune divisore
int mcd(int a, int b) {
  int resto = 0;
  while (b != 0) {
    resto = a % b;
    a = b;
    b = resto;
  }
  return a;
}

// Riduzione di una frazione in fattori primi
void riduci(int& numeratore, int& denominatore){
    int m = mcd(numeratore, denominatore);
    numeratore /= m;
    denominatore /= m;
}

int main() {
    int num = 0, den = 0;
    char continua = 's';
    do {
        // Acquisizione dell'input
        do {
            std::cout << "Inserisci una frazione:" << std::endl;
            std::cout << "Numeratore: ";
            std::cin >> num;
            std::cout << "Denominatore: ";
            std::cin >> den;
            if (num <= 0 || den <= 0)
                std::cout << "Attenzione: occorre che numeratore e denominatore siano numeri positivi" << std::endl;
        } while (num <= 0 || den <= 0);

        // Calcolo
        riduci(num, den);

        // Visualizzazione del risultato
        std::cout << "La frazione si puo' ridurre a: " << num << "/" << den << std::endl;

        // Verifica di terminazione della sequenza in input
        do {
            std::cout << std::endl;
            std::cout << "Inserire un altro numero (s/n)? ";
            std::cin >> continua;
            std::cout << std::endl;
            if ((continua != 's') && (continua != 'n'))
                std::cout << "Attenzione: inserire s per continuare, n per uscire" << std::endl;
        } while ((continua != 's') && (continua != 'n'));
	} while (continua != 'n');

    return 0;
}
