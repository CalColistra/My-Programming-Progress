//file  : brutes.cpp
//author: Cal Colistra
//desc. : this file contains the functions bruteForceRandom, and bruteForce5Loops.
#include <assert.h>
#include <iostream>
#include <algorithm>  //import for next_permutation()

using namespace std;

extern void copy(double A[][2], int n, double B[][2]);
extern double cost(double A[][2], int n);
extern void print(double A[][2], int n);
extern void randomize_in_place(double A[][2], int n);
extern long fact(long n);

//---------------------------------------------------------------------------
//this function (hopefully - no guarantees) finds the optimal solution by
//repeatedly calling randomize_in_place while keeping track of the best
//solution.
//
//repeats is the number of repeats.
//A is the initial tour and n is its length.
//this function returns the best solution in A.
void bruteForceRandom(double A[][2], int n, long repeats) {
  double (*tmp)[2] = new double[n][2];  //tmp is a ptr to pairs of doubles
  double cost1 = cost(A, n);  //cost1 = the cost of the original tour
  double cost2 = 0.0;  //intialize cost2 for comparing different tours
  copy(tmp, n, A);  //give tmp coordinates from original tour (A)

  while (repeats >= 0) {  //keep going until repeats = 0
    randomize_in_place(A, n);  //randomize the order of the cities
    cost2 = cost(A, n);  //calculate the new cost of the new tour
    if (cost1 > cost2) {  //check if the cost is less than previous tour
      copy(tmp, n, A);  //if so, update tmp with the better tour
      cost1 = cost2;  //update cost1 with better cost
    }
  repeats = repeats - 1;  //decrement repeats
  }
  copy(A, n, tmp);  //put the coordinates of the best tour into A[]
  delete[] tmp;  //delete tmp ptr
}
//---------------------------------------------------------------------------
//this function generates (exactly) all permutations of the tour A.
// this is hard-coded to only work for an array of length 5.
// the optimal tour should be returned in A.  the number of permutations
// tested should be returned.
long bruteForce5Loops(double A[][2], int n) {
  assert(n == 5);  //only works for n=5
  long f = 120;  //find the amount of permutations
  int perms[] = { 0, 1, 2, 3, 4 };  //initialize array for indexes to be permuted
  double(*B)[2] = new double[n][2];  //B is a ptr to pairs of doubles
  double(*tmp)[2] = new double[n][2];  //tmp is a ptr to pairs of doubles
  double cost1 = cost(A, n);  //cost1 = the cost of the original tour
  double cost2 = 0.0;  //intialize cost2 for comparing cost of different tours
  copy(tmp, n, A);  //give tmp coordinates from original tour (A)
  
  for (int j = 0; j < f; j++) {  //loop from 0 to f (f = # of permutations)
    //alter perms[] by generating next permutation:
    next_permutation(perms, perms + n);

    for (int i = 0; i < n; i++) {  //loop through to assign the new tour to B[]
        int index = perms[i];  //index = the new indexes of the new tour
        //place the coordinates of the new tour in B[]:
        B[i][0] = A[index][0];
        B[i][1] = A[index][1];
    }
    for (int i = 0; i < n; i++) {  //loop from beginning to end of A[]
      //place coordinates of new tour back into A[]:
      A[i][0] = B[i][0];
      A[i][1] = B[i][1];
    }
    cost2 = cost(A, n);  //calculate the new cost of the new tour
    if (cost1 > cost2) {  //check if the new cost is less than previous cost
      copy(tmp, n, A);  //if so, update tmp with the better tour
      cost1 = cost2;  //update cost1 with better cost
    }
  }
  copy(A, n, tmp);  //put the coordinates of the best tour into A[]
  delete[] B;  //delete B pointer
  delete[] tmp;  //delete tmp ptr
  return f;  //returns number of permutations
}
//---------------------------------------------------------------------------
//this function generates all permutations of the tour A.
// this work for tours of any size.
// the optimal tour should be returned in A.  the number of permutations
// tested should be returned.
long bruteForceLoops(double A[][2], int n) {
  long f = fact(n);  //find the amount of permutations
  int* perms= new int[n];  //initialize array for indexes to be permuted
  for (int i = 0; i < n; i++) {  //loop from 0 to end of perms[]
    perms[i] = i;  //give perms index 0 to (n - 1)
  }
  double(*B)[2] = new double[n][2];  //B is a ptr to pairs of doubles
  double(*tmp)[2] = new double[n][2];  //tmp is a ptr to pairs of doubles
  double cost1 = cost(A, n);  //cost1 = the cost of the original tour
  double cost2 = 0.0;  //intialize cost2 for comparing cost of different tours
  copy(tmp, n, A);  //give tmp coordinates from original tour (A)
  
  for (int j = 0; j < f; j++) {  //loop from 0 to f (f = # of permutations)
    //alter perms[] by generating next permutation:
    next_permutation(perms, perms + n);

    for (int i = 0; i < n; i++) {  //loop through to assign the new tour to B[]
        int index = perms[i];  //index = the new indexes of the new tour
        //place the coordinates of the new tour in B[]:
        B[i][0] = A[index][0];
        B[i][1] = A[index][1];
    }
    for (int i = 0; i < n; i++) {  //loop from beginning to end of A[]
      //place coordinates of new tour back into A[]:
      A[i][0] = B[i][0];
      A[i][1] = B[i][1];
    }
    cost2 = cost(A, n);  //calculate the new cost of the new tour
    if (cost1 > cost2) {  //check if the new cost is less than previous cost
      copy(tmp, n, A);  //if so, update tmp with the better tour
      cost1 = cost2;  //update cost1 with better cost
    }
  }
  copy(A, n, tmp);  //put the coordinates of the best tour into A[]
  delete[] B;  //delete B pointer
  delete[] tmp;  //delete tmp ptr
  delete[] perms;  //delete perms ptr
  //tell the user how many permutations were made:
  cout << "Number of permutations = " << f << endl;
  return f;  //returns number of permutations
}
//---------------------------------------------------------------------------
