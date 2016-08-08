#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
/* 
 * This file generates boiler plate code for 
 * a c++ program, that is this code itself 
 *
 * Usage: ./boilerplate -l c++ [-f filename]
 * -----------------------------------------
 *
 * Without the filename options it will generate
 * a file named program.cc
 *
 */

enum BoilerType {Default, Custom, Error};

BoilerType getBoilerType(int argc);
void reportUsageError();
bool validLanguage(char *lang);

int main(int argc, char *argv[]) {
  if(argc < 3) {
    reportUsageError();
  } else {
    if()
  }

}

BoilerType getBoilerType(int argc, char *argv[]) {
  if(argv[1] != "-l") {
    reportUsageError();
  }
}

void reportUsageError() {
  cerr << "Usage: ./boilerplate -l c++ [-f filename]\n";
  exit(0);
}

bool validLanguage(char *lang) {
  string s(lang);
  string c++ = "c++";
  if(toLower(s) == "c++") 
    return true;
  return

}

string toLower(string s) {
  string ns = "";
  for(size_t i = 0; i < s.size(); i++) {
    ns += tolower(s[i]);
  }
  return ns;
}