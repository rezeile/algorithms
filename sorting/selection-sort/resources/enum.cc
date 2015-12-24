/*
 * A basic enum client.
 */

 #include <iostream>

 enum family {
 	Benjamin,
 	Eliezer,
 	Miseker,
 	Amarech,
 	Eshetu,
 };

 struct School {
 	int grade;
 	family mem;
 };

 int main() {
 	enum family Bob = Eshetu;
 	family Cheryl = Benjamin;
 	School w;
 	w.grade = 5;
 	w.mem = Benjamin;
 	if(Bob == 5) {
 		std::cout << "Works on first try" << std::endl;
 	}
 	return 0;
 }
