/*
 * A basic enum client.
 */

 #include <stdio.h> 

 enum {
   one,
   two,
   three
 };

 typedef enum family {
 	Benjamin,
 	Eliezer,
 	Miseker,
 	Amarech,
 	Eshetu,
 } family_t;
 /* the actual (real) type of this object is 'struct School', we, if necessary
  * need to redefine this full type. */
 struct School {
 	int grade;
 	enum family mem;
 };

 typedef struct School School_t;

 int main() {
 	enum family Bob = Eshetu;
 	enum family Cheryl = Benjamin;
 	School_t  w;
 	typedef unsigned char school_grade_t;
  school_grade_t sg = 4;
  family_t f = Eliezer;
  w.grade = 5;
 	w.mem = Benjamin;
 	printf("%d\n", Eliezer);
 	if(two == Eliezer)
    printf("Hello World\n");
  return 0;
 }
