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
 using namespace std;

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