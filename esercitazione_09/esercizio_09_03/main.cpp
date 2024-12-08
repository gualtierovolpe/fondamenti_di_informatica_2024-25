#include <iostream>
#include <cmath>

struct punto2d {
    double x;
    double y;
};

struct retta {
    double a;
    double b;
    double c;
};

double distanza(punto2d p, retta r) {
    if (r.a == 0.0 && r.b == 0.0)
        return 0.0;
    double num = abs(r.a * p.x + r.b * p.y + r.c);
    double den = sqrt(r.a * r.a + r.b * r.b);
    return num / den;
}

int main() {
    punto2d pt;
    retta rt;
    char continua = ' ';

    do {
        // Acquisizione dell'input
        do {
            std::cout << "Calcolo della distanza punto-retta" << std::endl;
            std::cout << "Inserire il coefficiente a dell'equazione di una retta: ";
            std::cin >> rt.a;
            std::cout << "Inserire il coefficiente b dell'equazione di una retta: ";
            std::cin >> rt.b;
            std::cout << "Inserire il coefficiente c dell'equazione di una retta: ";
            std::cin >> rt.c;
            if (rt.a == 0.0 && rt.b == 0.0)
                std::cout << "Attenzione: i coefficienti a e b non possono essere entrambi nulli" << std::endl;
        } while (rt.a == 0.0 && rt.b == 0.0);
        std::cout << "Inserire la coordinata x di un punto: ";
        std::cin >> pt.x;
        std::cout << "Inserire la coordinata y di un punto: ";
        std::cin >> pt.y;

        // Chiamata della funzione elabora
        double d = distanza(pt, rt);

        // Visualizzazione del risultato
        std::cout << "La distanza vale " << d << std::endl;

        do {
            std::cout << "Vuoi continuare (s/n)? ";
            std::cin >> continua;
            if ((continua != 's') && (continua != 'n'))
                    std::cout << "Attenzione: inserire s per continuare, n per uscire" << std::endl;
        } while ((continua != 's') && (continua != 'n'));

    } while (continua == 's');

	return 0;
}
