#include <iostream>
#include <fstream>
#include <cstring>

int main() {
    const int dim = 16;
    char nome_file[dim] = "";
    int contatore = 0;
    int termina = 0;
    std::fstream fin;

    while(1) {
        int aperto;
        do {
            // Acquisizione dell'input
            std::cout << "Inserire il nome di un file o exit per terminare" << std::endl;
            std::cin.getline(nome_file, dim, '\n');

            // Verifica per la terminazione del programma
            if (strcmp(nome_file, "exit") == 0) {
                termina = 1;
            }
            else {
                // Verifica del nome del file e apertura del file
                aperto = 1;
                fin.open(nome_file, std::ios::in);
                if (!fin) {
                    aperto = 0;
                    std::cout << "Attenzione: il file inserito non esiste" << std::endl;
                }
            }
        } while (aperto == 0 && termina == 0);

        if (termina == 1)
            break;

        // Elaborazione del file
        double temperatura = 0.0;
        fin >> temperatura;
        double minimo = temperatura, massimo = temperatura;
        int file_vuoto = 1;
        while (!fin.eof()) {
            file_vuoto = 0;
            fin >> temperatura;
            if (temperatura < minimo)
                minimo = temperatura;
            if (temperatura > massimo)
                massimo = temperatura;
        }

        // Chiusura del file
        fin.close();

        // Visualizzazione dell'output
        if (file_vuoto)
            std::cout << std::endl << "Attenzione: il file e' vuoto" << std::endl << std::endl;
        else {
            contatore++;
            std::cout << std::endl << "File: " << nome_file << std::endl;
            std::cout << "Temperatura minima: " << minimo << "C" << std::endl;
            std::cout << "Temperatura massima: " << massimo << "C" << std::endl << std::endl;
        }
    }

    std::cout << std::endl << "Numero di file non vuoti elaborati: " << contatore << std::endl;

    return 0;
}
