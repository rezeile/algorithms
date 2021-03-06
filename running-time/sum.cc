#include <iostream>
#include <ctime>
#include <string> /* for stoi */

/* consider the following program which calculates
 * the sume of the first n consecutive number of
 * user specified integers. */

double sum1(int n) {
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    sum += i;
  }
  return (double) n;
}

double sum2(int n) {
  double sum = (double) (n * (n + 1)) / 2;
  return n;
}


int main(int argc, char *argv[]) {
  int n = std::stoi(argv[1]);
  std::clock_t start1;
  std::clock_t start2;
  
  start1 = std::clock();
  std::cout << "sum1: " << sum1(n) << std::endl;
  double duration1 =  (std::clock() - start1) / (double) CLOCKS_PER_SEC;

  start2 = std::clock();
  std::cout << "sum2: " << sum2(n) << std::endl;
  double duration2 = (std::clock() - start2) / (double) CLOCKS_PER_SEC;

  std::cout << "Running time of sequentail: " << duration1 << "seconds" << std::endl;
  std::cout << "Running time of Gaussian: " << duration2 << " seconds" << std::endl;

  return 0;
}
