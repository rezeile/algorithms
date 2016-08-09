#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cassert>
using namespace std;
/* 
 * This file generates boiler plate code for 
 * a c++ program, that is this code itself 
 *
 * Usage: ./boilerplate -l c++ [-f filename]
 *          argv[0] | argv[1] | argv[2] | argv[3]
 * -----------------------------------------------
 *
 * Without the filename options it will generate
 * a file named program.cc
 *
 */

enum BoilerType {Default, Custom, Error};

BoilerType getBoilerType(int argc, char *argv[]);
void reportUsageError(unsigned int err);
bool validLanguage(char *lang);
string toLower(string s);

           

int main(int argc, char *argv[]) {
  string boiler_code = string("using namespace std;\n\n") +
                       "int main(int argc, char *argv[]) {\n" + 
                       "\treturn 0;\n" +
                       "}"; /* don't know if valid syntax */ 

  if(argc < 3) {
    reportUsageError(0);
  } else {
    BoilerType bt = getBoilerType(argc,argv);
    if(bt != Error) {
      /* we want to place the file in the caller's directory */
      string s = (bt == Default) ? "boiler.cc" : argv[4];
      ofstream b_file(s.c_str());
      if(b_file.is_open()) {
        b_file << boiler_code;
      } else {
        reportUsageError(1);
      }
    } else {
      reportUsageError(0);
    }
  }
}


BoilerType getBoilerType(int argc, char *argv[]) {
  assert(argc >= 3);
  if(strcmp(argv[1], "-l") != 0) {
    return Error;
  } 
  if(!validLanguage(argv[2])) {
    return Error;
  } else {
    if(argc == 5) {
      if(strcmp(argv[3],"-f") != 0) {
        return Custom;
      } 
    }
    return Default;
  }
}

void reportUsageError(unsigned int err) {
  assert(err <= 1);
  switch(err) {
    case 0:
      cerr << "Usage: ./boilerplate -l c++ [-f filename]\n";
      exit(0);
      break;
    case 1:
      cerr << "File Error in of_stream\n";
      exit(0);
      break;
  }
  
}

bool validLanguage(char *lang) {
  if(strcmp(string(lang).c_str(),"c++") == 0) 
    return true;
  return false;

}

string toLower(string s) {
  string ns = "";
  for(size_t i = 0; i < s.size(); i++) {
    ns += tolower(s[i]);
  }
  return ns;
}