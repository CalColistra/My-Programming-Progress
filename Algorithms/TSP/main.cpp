// file  : main.cpp
// author: Cal Colistra
// desc. : this file initializes (seeds) our random number generator.
//         it also contains code that exercises/tests the following 
//         functions:
//           copy, cost, print, randomize_in_place,
//           bruteForceRandom, bruteForce5Loops
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

extern void copy(double A[][2], int n, double B[][2]);
extern double cost(double A[][2], int n);
extern void print(double A[][2], int n);
extern long fact(long n);
extern long factRecursive(long n);
extern void randomize_in_place(double A[][2], int n);

extern void bruteForceRandom(double A[][2], int n, long repeats);
extern long bruteForce5Loops(double A[][2], int n);
extern long bruteForceLoops(double A[][2], int n);

extern void swap_any_two(double A[][2], int n);
extern void invert(double A[][2], int n, int start, int len);
extern void translate(double A[][2], int n, int src, int len, int dst);


extern mt19937_64 g; //our random number generator

//---------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  //original tests:--------------------------------------
/*
  //test tour:
  const int  n = 5;  //n holds the number of cities in the tour
  double  tour[n][2] = {
    { 0.631980, 0.7925150 },
    { 0.489609, 0.2541210 },
    { 0.975682, 0.0843492 },
    { 0.414236, 0.6135660 },
    { 0.338385, 0.0315477 }
  };

  //-----------------------------------
  //test brutes.cpp:
  randomize_in_place(tour, n);
  printf("before (cost=%f) : \n", cost(tour, n));
  print(tour, n);
  bruteForce5Loops(tour, n);
  printf("after (cost=%f) : \n", cost(tour, n));
  print(tour, n);

  printf("before (cost=%f) : \n", cost(tour, n));
  print(tour, n);
  bruteForceRandom(tour, n, 10);
  printf("after (cost=%f) : \n", cost(tour, n));
  print(tour, n);
  //-------------------------------------------------------------------
  // test utes.cpp:
  double  tour2[n][2] = {
      { 0.6, 0.7 },
      { 0.4, 0.25 },
      { 0.9, 0.08 },
      { 0.4, 0.61 },
      { 0.3, 0.0317 }
  };
  //-------------------------------------------------------------------
  cout << "test copy() function:" << endl;
  cout << "before copy():" << endl;
  print(tour2, n);
  copy(tour2, n, tour);  //copy tour into tour2
  cout << "after copy():" << endl;
  print(tour2, n);
 
  cout << "test cost() function:" << endl;
  printf("(cost=%f) : \n", cost(tour, n));
  //-------------------------------------------------------------------
  cout << "test print() and randomize_in_place() function:" << endl;
  double  tour3[n][2] = 
  {
    { 0.6, 0.7 },
    { 0.4, 0.25 },
    { 0.9, 0.08 },
    { 0.4, 0.61 },
    { 0.3, 0.0317 }
  };
  cout << "before randomize_in_place():" << endl;
  print(tour3, n);
  randomize_in_place(tour3, n);
  cout << "after randomize_in_place():" << endl;
  print(tour3, n);
  //-------------------------------------------------------------------
  cout << "test fact() and factRecursive() functions :" << endl;
  cout << "5! = " << fact(5.0) << endl;
  cout << "6! = " << factRecursive(6.0) << endl;

  // test bruteForceLoops() -----------------------
  int const g = 6;
  double  tour4[6][2] = {
    { 0.631980, 0.7925150 },
    { 0.489609, 0.2541210 },
    { 0.975682, 0.0843492 },
    { 0.414236, 0.6135660 },
    { 0.338385, 0.0315477 },
    { 0.579235, 0.8079234 }
  };
  printf("before (cost=%f) : \n", cost(tour4, g));
  print(tour4, g);
  bruteForceLoops(tour4, g);
  printf("after (cost=%f) : \n", cost(tour4, g));
  print(tour4, g);
*/

/* test invert() function:
  double A[][2] = { {0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7} };
  double B[][2] = { {0,0} };
  int s = 8;
  print(A, s);
  invert(A, s, 0, 3);
  print(A, s);
*/

/*test translate() function:*/
  double C[][2] = { {0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7} };
  int n = 8;
  print(C, n);
  translate(C, 8, 7, 2, 1);
  print(C, n);

  return 0;
}
//---------------------------------------------------------------------------
