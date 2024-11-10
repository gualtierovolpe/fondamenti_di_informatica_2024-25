#include <iostream>

int main() {

    char a = ' ', b = ' ', c = ' ', d = ' ';

    // Acquisizione password
    std::cout << "Inserire una password di quattro caratteri: ";
    std::cin >> a >> b >> c >> d;

    // Condizioni di validita'
    int minuscolo = (a >= 'a' && a <= 'z') || (b >= 'a' && b <= 'z') || (c >= 'a' && c <= 'z') || (d >= 'a' && d <= 'z');
    int maiuscolo = (a >= 'A' && a <= 'Z') || (b >= 'A' && b <= 'Z') || (c >= 'A' && c <= 'Z') || (d >= 'A' && d <= 'Z');
    int cifra = (a >= '0' && a <= '9') || (b >= '0' && b <= '9') || (c >= '0' && c <= '9') || (d >= '0' && d <= '9');

    // Verifica delle condizioni
    if (minuscolo && maiuscolo && cifra) {
        std::cout << "Password OK!" << std::endl;
    }
    else {
        std::cout << "La password non e' sicura" << std::endl;
    }

    return 0;
}
