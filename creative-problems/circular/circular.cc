/*
 * Program: circular.cc 
 * Author: Eliezer Abate
 * Date: Aug 6 2016
 * --------------------------------------------------------------
 * This program checks whether two given strings s and t are 
 * circular rotations of one another. 
 * 
 * A string s is a circular rotation of a string t if it matches
 * when the characters are circularly shifted by any number of 
 * positions; e.g., ACTGACG is a circular shift of 
 * TGACGAC, and vice versa. [this definition is taken verbatim 
 * from Introduction to Algorithms 4th edition, Sedgewick & Wayne, 
 * exercise 1.2.6].
 */

 #include <string>
 #include <iostream>
 using namespace std;

bool isCircularRotation(string &t, string &s);

int main(int argc, char *argv[]) {
    cout << "Enter a string s: ";
    string s; 
    getline(cin,s);
    cout << "Enter a string t: ";
    string t;
    while(getline(cin,t)) {
      if(t == "") break;
      if(isCircularRotation(t,s)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      cout << "Enter another string t (or press enter to end): ";
    }
    return 0;
 }

 bool isCircularRotation(string &t, string &s) {
  return false;
 }

