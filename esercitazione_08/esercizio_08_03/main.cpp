#include <fstream>
#include <iostream>

int main() {

    // Dichiarazione degli stream
    std::fstream fin, fout;

    // Apertura dei file
    fin.open("input.txt", std::ios::in);
    if (!fin) {
        std::cout << "Attenzione: non e' stato possibile aprire il file input.txt" << std::endl;
        return -1;
    }
    fout.open("output.txt", std::ios::out);

    // Elaborazione del file
    char c = ' ';
    int contaoccorrenze['z' - 'a' + 1] = {0};
    fin >> c;
    while (!fin.eof()) {
        // Se c è una lettera minuscola
        if ((c >= 'a') && (c <= 'z')) {
            int posizione = c - 'a';        //individuo il numero progressivo della lettera nell'alfabeto
            contaoccorrenze[posizione]++;   //conto uno in più per quella lettera
        }

        // Se c è una lettera maiuscola faccio la stessa cosa
        if ((c >= 'A') && (c <= 'Z'))  {
            int posizione = c-'A';
            contaoccorrenze[posizione]++;
        }

        // Leggo il carattere successivo
        fin >> c;
    }

    // Chiusura del file in ingresso
    fin.close();

    // Stampa dell'output nel file in uscita
    for (int i = 0; i < 26; i++) {
        c = 'a' + i;
        fout << c << ": " << contaoccorrenze[i] << std::endl;
    }

    // Chiusura del file in uscita
    fout.close();

    std::cout << "Elaborazione completata" << std::endl;

    return 0;
}
