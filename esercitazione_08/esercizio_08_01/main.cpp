#include <iostream>
#include <fstream>

int controllo_vocale(char carattere){
    int ritorno;
    switch (carattere) {
        case 'a': case 'A':
        case 'e': case 'E':
        case 'i': case 'I':
        case 'o': case 'O':
        case 'u': case 'U':
            ritorno = 1;
            break;
        default:
            ritorno = 0;
            break;
    }
    return ritorno;
}

int main() {
    // Dichiarazione degli stream
    std::fstream fin, fout1, fout2;

    // Associazione degli stream ai file
    fin.open("ciao.txt", std::ios::in);
    if (!fin) {
        std::cout << "Attenzione: non e' stato possibile aprire il file ciao.txt" << std::endl;
        return -1;
    }
    fout1.open("vocali.txt", std::ios::out);
    fout2.open("consonanti.txt", std::ios::out);

    // Lettura ed elaborazione del file di ingresso
    char a = ' ';
    while (!fin.eof()) {
        fin >> a;
        if (isalpha(a) > 0) {
            if (controllo_vocale(a) == 1)
                fout1 << a;
            else
                fout2 << a;
        }
    }
    std::cout << "Elaborazione completata" << std::endl;

    // Chiusura dei file
    fin.close();
    fout1.close();
    fout2.close();

    return 0;
}
