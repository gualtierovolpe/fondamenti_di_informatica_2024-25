#include <iostream>

int main() {

	double a = 0.0, b = 0.0, c = 0.0, d = 0.0;
	double x = 0.0, y = 0.0;

	// Inserimento coordinate del punto
	std::cout << "Inserire le coordinate (x, y) di un punto" << std::endl;
	std::cout << "x: ";
	std::cin >> x;
	std::cout << "y: ";
	std::cin >> y;
	std::cout << std::endl;

	// Inserimento coordinate vertice in alto a sinistra del rettangolo
	std::cout << "Inserire le coordinate (a, b) del vertice in alto a sinistra di un rettangolo" << std::endl;
	std::cout << "a: ";
	std::cin >> a;
	std::cout << "b: ";
	std::cin >> b;
	std::cout << std::endl;

	// Inserimento coordinate vertice in basso a destra del rettangolo
	std::cout << "Inserire le coordinate (c, d) del vertice in basso a destra di un rettangolo" << std::endl;
	std::cout << "c: ";
	std::cin >> c;
	std::cout << "d: ";
	std::cin >> d;
	std::cout << std::endl;

	// Verifica della validita' delle coordinate dei vertici
	if ((a >= c) || (d >= b)) {
		std::cout << "Attenzione: il rettangolo inserito non e' valido" << std::endl << std::endl;
		return 0;
	}

	// Verifica dell'appartenenza del punto al rettangolo
	if (((x > a) && (x < c)) && ((y > d) && (y < b))) {
		std::cout << "Il punto appartiene al rettangolo" << std::endl;
	}
	else {
		std::cout << "Il punto non appartiene al rettangolo" << std::endl;
	}

	return 0;
}
