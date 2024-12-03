#include <iostream>
#include <fstream>

const int r = 31;
const int c = 10;

double totaleMerce(double T[r][c]) {
    double s = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            s += T[i][j];
    return s;
}

int numTreni(double T[r][c]) {
    int contatore = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (T[i][j] != 0.0) {
                contatore++;
                break;
            }
    return contatore;
}

double maxTreno(double T[r][c], int& v, int& g) {
    g = 0; v = 0; double s = 0.0;
    for (int i = 0; i < r; i++) {
        int contatore = 0;
        double sum = 0.0;
        for (int j = 0; j < c; j++) {
            if (T[i][j] != 0.0) {
                contatore++;
                sum += T[i][j];
            }
        }
        if (contatore > v) {
            v = contatore;
            g = i;
            s = sum;
        }
   }
   return s;
}

int main() {
    double Treni[r][c] = {0};
    std::fstream fin;

    fin.open("Dati.txt", std::ios::in);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            fin >> Treni[i][j];
    fin.close();

    std::cout << "Totale merce movimentata: " << totaleMerce(Treni) << std::endl;
    std::cout << "Numero di treni: " << numTreni(Treni) << std::endl;

    int giorno = 0; int nVagoni = 0;
    double merce = maxTreno(Treni, nVagoni, giorno);
    std::cout << "Massimo numero di vagoni: " << nVagoni << std::endl;
    std::cout << "Giorno di viaggio: " << giorno + 1 << std::endl;
    std::cout << "Merce trasportata: " << merce << std::endl;

    return 0;
}
