/* 
 * This program accepts two inputs M and N from the user, where
 * M represents the step in the josephus problem and N is the 
 * number of people in the problem.
 * 
 * The Josephus problem is named after the Jewish historian 
 * Josephus who lived in the first century A.D., and described 
 * an event where he and a group of people devised a strategy 
 * to slowly kill themselves.The mathematical problem is 
 * adopted from his anecdote.
 *
 * It describes a group of men sitting in a circle and, beginning
 * starting with a person chosen at random (in our case the first
 * will always be in index 0) every Mth person will be killed.
 * The last remaining person will not be killed.
 *
 * Thus, the goal of this program, is to compute the order in 
 * which the people sitting in the circle will be killed and in 
 * doing so we can find the best position to sit at if one wants
 * to remain alive.
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
	cout << "Enter two values [M] [N]: ";
	string s;
	getline(cin,s);
	int M, N;
	ss >> M; // every Mth person is killed
	ss >> N; // positions of people




