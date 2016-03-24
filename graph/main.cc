/* * Simple file to test the car class */

#include <iostream>
#include "car.hh"

int main(int argc, char *argv[]) {
	std::cout << "Hello World" << std::endl;
	std::string make = std::string("Honda");
	std::string model = std::string("Civic");
	Car c(make,model, 2000);
	std::cout << c.getModel() << std::endl;
	return 0;
}
