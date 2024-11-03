#include <iostream>
#include <cmath>

int main ()
{
	double a, b, c;
	double p = 0, area = 0;

	std::cout << "Inserire le lunghezze dei tre lati di un triangolo: " << std::endl;
	std::cout << "Primo lato: ";
	std::cin >> a;
	std::cout << "Secondo lato: ";
	std::cin >> b;
	std::cout << "Terzo lato: ";
	std::cin >> c;

	// Calcolo del semiperimetro
	p = (a + b + c) / 2;

	// Calcolo dell'area
	area = sqrt(p * (p - a) * (p - b) * (p - c));

	std::cout << "La area del triangolo vale: " << area << std::endl;

	return 0;
}

