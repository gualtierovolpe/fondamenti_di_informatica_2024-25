#include <iostream>
#include <cmath>

int main() {
    
    double a = 0.0, b = 0.0, c = 0.0;
    double x1 = 0.0, x2 = 0.0;

    // Acquisizione coefficienti
    std::cout << "Inserire i coefficienti a, b e c di una equazione di secondo grado" << std::endl;
    std::cout << "Coefficiente a: ";
    std::cin >> a;
    std::cout << "Coefficiente b: ";
    std::cin >> b;
    std::cout << "Coefficiente c: ";
    std::cin >> c;

    // Caso degenere
    if (a == 0) {
        std::cout << "Attenzione: si tratta di una equazione degenere!" << std::endl;
        if (b == 0) {
            if (c == 0)
                std::cout << "L'equazione e' verificata per qualunque x" << std::endl;
            else
                std::cout << "Non esiste x che verifichi l'equazione" << std::endl;
        }
        else {
            x1 = -c / b;
            std::cout << "La soluzione e' x = " << x1 << std::endl;
        }
    }

    // Caso non degenere
    else {
        double delta = b * b - 4 * a * c;
        //double delta = pow(b, 2) - 4 * a * c;
        if (delta > 0) {
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            std::cout << "L'equazione ha due soluzioni reali e distinte" << std::endl;
            std::cout << "x1 = " << x1 << std::endl;
            std::cout << "x2 = " << x2 << std::endl;
        }
        else if (delta == 0) {
            x1 = -b / (2 * a);
            std::cout << "L'equazione ha due soluzioni reali e coincidenti" << std::endl;
            std::cout << "x1 = x2 = " << x1 << std::endl;
        }
        else {
            std::cout << "L'equazione non ha soluzioni reali" << std::endl;
        }
    }

    return 0;
}
