#include <iostream>
#include <cmath>

// Struttura per equazioni di primo grado
struct equazione_1 {
    double a;
    double b;
};

// Struttura per equazioni di secondo grado
struct equazione_2 {
    double a;
    double b;
    double c;
};

// Struttura per soluzioni (reali) di equazioni di secondo grado
struct soluzione {
    double x1;
    double x2;
};

int risolvi_primo_grado(equazione_1 e, double& s) {
    int ritorno = 0;
    s = 0.0;
    if (e.a == 0) {
        if (e.b == 0)
            ritorno = 0;    // equazione sempre verificata
        else
            ritorno = -1;   // equazione impossibile
    }
    else {
        s = -e.b / e.a;
        ritorno = 1;
    }
    return ritorno;
}

int risolvi_secondo_grado(equazione_2 e, soluzione& s) {
    int ritorno = 0;
    s.x1 = 0.0; s.x2 = 0.0;
    if (e.a != 0) {
        double delta = e.b * e.b - 4 * e.a * e.c;
        if (delta > 0) {        // soluzioni reali e distinte
            s.x1 = (-e.b - sqrt(delta)) / (2 * e.a);
            s.x2 = (-e.b + sqrt(delta)) / (2 * e.a);
            ritorno = 1;
        }
        else if (delta == 0) {   // soluzioni reali e coincidenti
            s.x1 = -e.b / (2 * e.a);
            s.x2 = s.x1;
            ritorno = 0;
        }
        else {                  // non esistono soluzioni reali
            ritorno = -1;
        }
    }
    return ritorno;
}

int main() {
    // Acquisizione coefficienti
    equazione_2 eq;
    std::cout << "Inserire i coefficienti a, b e c di una equazione di secondo grado" << std::endl;
    std::cout << "Coefficiente a: ";
    std::cin >> eq.a;
    std::cout << "Coefficiente b: ";
    std::cin >> eq.b;
    std::cout << "Coefficiente c: ";
    std::cin >> eq.c;

    // Caso degenere
    if (eq.a == 0) {
        std::cout << "Attenzione: si tratta di una equazione degenere!" << std::endl;
        double x = 0.0;
        equazione_1 e1;
        e1.a = eq.b;
        e1.b = eq.c;
        int r = risolvi_primo_grado(e1, x);
        switch (r) {
            case 1:
                std::cout << "La soluzione e' x = " << x << std::endl;
                break;
            case 0:
                std::cout << "L'equazione e' verificata per qualunque x" << std::endl;
                break;
            case -1:
                std::cout << "Non esiste x che verifichi l'equazione" << std::endl;
                break;
        }
    }
    // Caso non degenere
    else {
        soluzione s;
        int r = risolvi_secondo_grado(eq, s);
        switch (r) {
            case 1:
                std::cout << "L'equazione ha due soluzioni reali e distinte" << std::endl;
                std::cout << "x1 = " << s.x1 << std::endl;
                std::cout << "x2 = " << s.x2 << std::endl;
                break;
            case 0:
                std::cout << "L'equazione ha due soluzioni reali e coincidenti" << std::endl;
                std::cout << "x1 = x2 = " << s.x1 << std::endl;
                break;
            case -1:
                std::cout << "L'equazione non ha soluzioni reali" << std::endl;
                break;
        }
    }

    return 0;
}
