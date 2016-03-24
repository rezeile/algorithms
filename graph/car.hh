/*
 * Sample implementation of car class
 * to test c++ file modularity.
 */

 #include <string>

 class Car {
	 public: 
	 	/* constructor */
		Car(std::string &make, std::string &model, int year);
		
		/* accessors */
		std::string getMake();
		std::string getModel();
		int getYear();

		/* mutators */
		void setMake(std::string &make);
		void setModel(std::string &model);
		void setYear(int year);

	private:
		std::string p_make;
		std::string p_model;
		int p_year;
 };

