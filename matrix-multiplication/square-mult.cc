#include <iostream>
#include <cstdlib>

void populateMatrix(int **mtx,int row,int col) {
  //std::cout << "row: " << row << std::endl;
  //std::cout << "col: " << col << std::endl;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      mtx[i][j] = rand() % 9 + 1;
      //std::cout << mtx[i][j] << std::endl;
      //std::cout << "[" << i << "," << j << "]" << std::endl;
    }
  }
}

void printMatrix(int **mtx, int row, int col) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(j == 0) {
        std::cout << "[" << mtx[i][j] << ",";
      } else if (j == col - 1) {
        std::cout << mtx[i][j] << "]" << std::endl;
      } else{
        std::cout << mtx[i][j] << ",";
      }
    }
  }
}

int **squareMultiply(int **mA,int **mB,int n,int rowA, int colB) {
  /* allcoate space for rows */
  int **res = (int **) malloc(rowA * sizeof(int *));
  /* allocate space for columns */
  for(int i = 0; i < rowA; i++)
    res[i] = (int *) malloc(colB * sizeof(int *));

  /* square multiplication */
  for(int i = 0; i < rowA; i++) {
    for(int j = 0; j < colB; j++) {
      for(int k = 0; k < n; k++) {
        res[i][j] = mA[rowA][k] * mB[k][colB];
      }
  }
  }
  return res;
}

int main(int argc, char *argv[]) {
  int n = 4;//rand() % 10 + 1;
  int rowA = 3; //rand() % 10 + 1;
  int colB = 5;// rand() % 10 + 1;
  int **mtxA = (int **) malloc( rowA * sizeof(int *));
  for(int k = 0; k < rowA; k++)
    mtxA[k] = (int *) malloc( n * sizeof(int *));
  int **mtxB = (int **) malloc( n * sizeof(int *));
  for(int k = 0; k < n; k++) 
    mtxB[k] = (int *) malloc( colB * sizeof(int *));
  populateMatrix(mtxA,rowA,n);
  populateMatrix(mtxB,n,colB);
  std::cout << "matrix A" << std::endl;
  printMatrix(mtxA,rowA,n);
  std::cout << "matrix B" << std::endl;
  printMatrix(mtxB,n,colB);
  int **res = squareMultiply(mtxA,mtxB,n,rowA,colB);
  std::cout << "Square Multiplied: " << std::endl;
  printMatrix(res,rowA,colB);
  return 0;
}
