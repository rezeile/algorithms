/* 
 * A program to shift a string 
 * by a an integer. For example
 * if we have the string 
 * 
 * AWESOME
 *
 * A shift by 1 will turn it to the following
 *
 * WESOMEA
 *
 * A shift by 2 will turn it to
 * 
 * ESOMEAW
 *
 * A shift by 4
 * 
 * OMEAWES
 *
 * A shift by 7 will turn the string back to the original
 *
 * AWESOME
 *
 * A shfit by 8 is the same as a shift by 1
 *
 * WESOMEA
 *
 */

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

string shift_by_n(string s, unsigned int n);

int main() {
  cout << "Enter a string s: ";
  string s;
  getline(cin,s);
  cout << "Enter an ingeger N: ";
  unsigned int N;
  while(cin >> N) {
    cout << s << " shifted by " << N << " is: " << shift_by_n(s,N) << endl;
    cout << "Enter an ingeger N: ";
  }
	return 0;
}

string shift_by_n(string s, unsigned int n) {
  if(s.size() <= 1) return s;
  string shifted_str;
  unsigned int shift_val = n % s.size();
  // base case
  if(shift_val == 0) return s;
  
  // shift the first element to the end of the string
  // i.e. ABC --> BCA
  shifted_str = s.substr(shift_val,s.size()) + s.substr(0,shift_val);
  return shifted_str;

}
