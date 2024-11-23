#include <iostream>
#include <cstring>

void inverti(char s[]) {
    int lunghezza = strlen(s);
    int i = 0; int j = lunghezza - 1;
    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}

int main() {
    const int dim = 32;
    char str[dim] = "";

    // Acquisizione dell'input
    std::cout << "Inserire una stringa di caratteri: ";
    std::cin.getline(str, dim, '\n');

    // Chiamata alla funzione
    inverti(str);

    // Visualizzazione dell'output
    std::cout << "Stringa invertita: " << str;

    return 0;
}
