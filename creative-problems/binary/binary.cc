/* 
 * Author: Eliezer Abate
 * Program: binary.c
 * ------------------------------------------------------------------
 * This program accepts an integer N from the command line and writes
 * the integers binary representation into a string and prints the 
 * output. 
 *
 *
 * Example: Given the integer 3, the program would output
 * 
 *          11
 *
 * Given   12
 *
 * Output: 1100 
 */
 
 #include <iostream>
 #include <string>
 #include <cassert>
 #include <fstream>
 #include <sstream>
 using namespace std;

 void writeToTestFile(const char *test) {
    // we will write 100 random integers between 0-50 
    // to the test file
    ofstream file(test);
    if(file.is_open()) {
      for(size_t i = 0; i < 100; i++) {
        // generate random integer
        unsigned int n = rand() % 51;
        file << n << "\n";
      }
    }  
 }  

 string binaryRep(unsigned int N);

 int main(int argc, char *argv[]) {
    if(argc <= 1) {
      cout << "Enter an integer: ";
      unsigned int N;
      while(cin >> N) {
        cout << "Binary: " << binaryRep(N) << endl;
        cout << "Enter an integer :";
      }
    } else {
      if(argc != 3) {
        cerr << "usage: ./binary [-f filename]" << endl;
        exit(0);
      } else {
        if(strncmp(argv[1],"-f",2) != 0) {
          cerr << argv[1] << " is an invalid option" << endl;
          cerr << "usage: ./binary [-f filename]" << endl;
        } else {
          string s = "test1.txt";
          writeToTestFile(s.c_str());
          ifstream i_file(argv[2]);
          string o = "output.txt";
          ofstream o_file(o.c_str());
          cout << i_file.is_open() << endl;
          stringstream ss;
          while(getline(i_file,s)) {
            //cout << s << endl;
            ss << s;
            unsigned int N;
            ss >> N;
            cout << N << endl;
            o_file << N << " = " << binaryRep(N) << "\n";
          }
          i_file.close();
          o_file.close();
        }
      }
    }
 }

 string binaryRep(unsigned int N) {
   if(N == 0)
      return "0";
   else if(N == 1) {
      return "1";
   } else {
     unsigned int q = N / 2;
     unsigned int r = N % 2;
     return binaryRep(q) + binaryRep(r);
   }
 }