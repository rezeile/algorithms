/*
 * Implementation of the member functions
 * exported by the car.hh file.
 *
 * @author Eliezer Abate
 * @date 2016/03/23
 *
 */

 #include "car.hh"

 /* constructor */
 Car::Car(std::string &make, std::string &model, int year) {
 	p_make = make;
	p_model = model;
	p_year = year;
 }

 /* acessors */
 std::string Car::getMake() {
	 return p_make;
 }

 std::string Car::getModel() {
	 return p_model;
 }

 int Car::getYear() {
	 return p_year;
 }

 /* settors */
void Car::setMake(std::string &make) {
	p_make = make;
}

void Car::setModel(std::string &model) {
	p_model = model;
}

void Car::setYear(int year) {
	p_year = year;
}
