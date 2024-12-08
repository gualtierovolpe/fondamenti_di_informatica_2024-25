#include <iostream>
#include <fstream>
#include <cstring>

const int dim_autore = 32;
const int dim_titolo = 64;

// Struttura libro
struct libro {
    int codice;
    char autore[dim_autore];
    char titolo[dim_titolo];
    int pagine;
    double prezzo;
};

int main() {
    const int dim_libreria = 100;
    libro libreria[dim_libreria];

    // Acquisizione input da file
    std::fstream fin;
    fin.open("libri.txt", std::ios::in);
    if (!fin) {
        std::cout << "Errore nell'apertura del file" << std::endl;
        return -1;
    }
    const int dim = 64;
    char temp[dim] = "";
    int i = 0;
    while(!fin.eof() && i < 100){
        fin.getline(temp, dim, ',');
        libreria[i].codice = std::stoi(temp);    // stoi: funzione di libreria che converte una stringa in un numero intero di tipo int
        fin.getline(libreria[i].titolo, dim, ',');
        fin.getline(libreria[i].autore, dim, ',');
        fin.getline(temp, dim, ',');
        libreria[i].pagine = std::stoi(temp);
        fin.getline(temp, dim, '\n');
        libreria[i].prezzo = std::stod(temp);    // stod: funzione di libreria che converte una stringa in un numero reale di tipo double
        i++;
    }
    fin.close();

    char richiesta[dim_titolo];
    char continua = 's';
    do {
        // Richiesta di input all'utente
        std::cin.sync();     // pulizia dello stream in ingresso
        std::cin.clear();    // pulizia dello stream in ingresso
        std::cout << "Di quale libro desideri avere informazioni?" << std::endl;
        std::cin.getline(richiesta, dim_titolo, '\n');

        // Ricerca del libro desiderato e visualizzazione del risultato
        int trovato = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(richiesta, libreria[j].titolo) == 0) {
                std::cout << "Il libro e' presente nel catalogo" << std::endl;
                std::cout << "Il suo codice e': " << libreria[j].codice << std::endl;
                std::cout << "Il suo autore e': " << libreria[j].autore << std::endl;
                std::cout << "Il libro ha " << libreria[j].pagine << " pagine" << std::endl;
                std::cout << "Il libro costa " << libreria[j].prezzo << " Euro" << std::endl;
                trovato = 1;
                break;
            }
        }
        if (!trovato) {
            std::cout << "Il libro non e' in catalogo" << std::endl;
        }
        std::cout << std::endl;

        // Verifica per continuazione
        do {
            std::cout << "Desideri continuare (s/n)? ";
            std::cin >> continua;
            if (continua != 's' && continua != 'n')
                std::cout << "Attenzione: inserire s oppure n" << std::endl;
        } while (continua != 's' && continua != 'n');
        std::cout << std::endl;

    } while (continua == 's');

    return 0;
}
