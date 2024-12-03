#include <iostream>
#include <fstream>

int main() {

    // Dichiarazione dello stream
    std::fstream fin;

    // Associazione del file allo stream
    fin.open("dati.txt", std::ios::in);
    if (!fin) {
        std::cout << "Attenzione: non e' stato possibile aprire il file dati.txt" << std::endl;
        return -1;
    }

    // Elaborazione del file
    char codice[16] = "";
    int n_membri = 0;
    fin >> codice >> n_membri;
    while (!fin.eof()) {

        // Lettura delle eta'
        int valore = 0, somma = 0;
        for (int i = 1; i <= n_membri; i++) {
            fin >> valore;
            somma += valore;
        }

        // Calcolo dell'eta' media (secondo il testo, si suppone n_membri > 0)
        double media = double(somma) / n_membri;

        // Visualizzazione del risultato
        std::cout << "Gruppo: " << codice << ", età media: " << media << std::endl;

        // Lettura della riga successiva
        fin >> codice >> n_membri;
    }

    // Chiusura del file
    fin.close();

    return 0;
}
