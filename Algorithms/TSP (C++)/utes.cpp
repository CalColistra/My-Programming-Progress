//file  : utes.cpp
//author: Cal Colistra
//desc. : this file contains the following utility functions:
//            copy, cost, fact, factRecursive, print, and randomize_in_place.
#include <assert.h>
#include <iostream>
#include <math.h>
#include <random>
#include <time.h>

using namespace std;

mt19937_64 g;  //our random number generator

//---------------------------------------------------------------------------
//this function copies the tour in src (of length n) into tour dst (also of
//length n. the caller must properly init and allocate the tours. this is
//useful for keeping a copy of the best so far.
void copy ( double dst[][2], int n, double src[][2] ) {
  for(int i = 0; i < n; i++){  //loop to access each element of src[]
    dst[i][0] = src[i][0];  //copy 1st coordinate of city in src[] to dst[]
    dst[i][1] = src[i][1];  //copy 2nd coordinate of city in src[] to dst[]
  }
}
//---------------------------------------------------------------------------
//this functions returns the cost of tour A (of length n).
// don't forget that the distance from the end back to the start must be 
// included.
double cost ( double A[][2], int n ) {
  double totalCost = 0;  //initialize totalCost to 0
  for (int i = 0; i < n - 1; i++) {  //outer loop to access through each city
    double x, y; //x is the first coordinate and y is the second
    //calculate euclidean distance for x coordinate:
    x = (A[i][0] - A[i + 1][0]) * (A[i][0] - A[i + 1][0]);
    //calculate euclidean distance for y coordinate:
    y = (A[i][1] - A[i + 1][1]) * (A[i][1] - A[i + 1][1]);
    totalCost = totalCost + sqrt(x + y);  //add to the total cost
  }
  //calculate distance from last city to the first city:
  double x = (A[0][0] - A[n - 1][0]) * (A[0][0] - A[n - 1][0]);
  double y = (A[0][1] - A[n - 1][1]) * (A[0][1] - A[n - 1][1]);
  totalCost = totalCost + sqrt(x + y);  //add to the toal cost
  return totalCost;
}
//---------------------------------------------------------------------------
//non-recursive version of n factorial.  n! is returned.
long fact ( long n ) {
  long ans = 1.0;  //initalize ans to 1.0
  if (n < 0) {  //check if n is negative
    cout << "you can't calculate factorial of a negative number" << endl;
  }
  else {  //in this case n is greater than -1
    for (int i = 1; i <= n; ++i) {  //loop from 1 to n
      ans *= i;  //multiply ans by i and save in ans
    }
  }
  return ans;
}
//---------------------------------------------------------------------------
//recursive version of n factorial.  n! is returned.
long factRecursive ( long n ) {
  if (n > 1) {  //n does not equal 0
    return n * factRecursive(n - 1);  //recursively call and multiply to n
  }
  else { //base case: n = 0
    return 1;  //0! = 1 so return 1 if n = 0
  }
  return 0;
}
//---------------------------------------------------------------------------
//pretty print (to cout or stdout) tour A of length n.
void print ( double A[][2], int n ) {
  cout << "Tour:" << endl;  //label prior to printing coordinates
  cout << "    {" << endl;  //begin outter braces
  for (int i = 0; i < n; i++) {  //loop through every city in A
    //print coordinates for each city:
    cout << "    {" << A[i][0] << ", " << A[i][1] << "}," << endl;
  }
  cout << "    }" << endl;  //end outter braces
}
//---------------------------------------------------------------------------
//randomize tour A of length n in place
void randomize_in_place(double A[][2], int n) {
  random_device rd;  //obtain a random number from hardware
  mt19937 gen(rd());  //seed the generator
  uniform_int_distribution<> distr(0, n - 1);  //define the range (0-n)
  int* randoms = new int[n];  //new ptr array to hold random #'s between 1 to n
  //initialize randoms[] with random numbers with no duplicates:
  for (int i = 0; i < n; i++) {  //loop through beginning to end of randoms
    randoms[i] = distr(gen);  //place random number at index i
    for (int j = 0; j < i; j++) {  //loop from beginning to index i of randoms[]
      if (randoms[j] == randoms[i]) i--;  //if there are duplicates go back
    }
  }
  double(*B)[2] = new double[n][2];  //B is a ptr to pairs of doubles
  for (int i = 0; i < n; i++) {  //loop through to assign the new tour to B[]
    int index = randoms[i];  //index = the new indexes of the new tour
    //place the coordinates of the randomized tour in B[]:
    B[i][0] = A[index][0];
    B[i][1] = A[index][1];
    }
  for (int i = 0; i < n; i++) {  //loop from beginning to end of A[]
    //place new tour back into A[]:
    A[i][0] = B[i][0];
    A[i][1] = B[i][1];
  }
  delete[] randoms;  //delete randoms pointer
  delete[] B;  //delete B pointer
}
//---------------------------------------------------------------------------

/**(add to your existing utes.cpp file.)
 * pick any two (they must be different) and swap them.
 *
 * ex. before A = { {1,5}, {2,7}, {9,4},  {12,7}, {2,8}, {13,3}, {6,16}, {5,25} }
 *     swap_any_two( A, 8 );
 *     after  A = { {1,5}, {2,7}, {5,25}, {12,7}, {2,8}, {13,3}, {6,16}, {9,4}  }
 *
 * @param A is the list of locations (x,y) of the cities in the current tour.
 * @param n is the number of cities in A.
 */
void swap_any_two(double A[][2], int n) {
  if(n < 1){
    cout << "function: swap_any_two cannot be called on an array of size less than 1" << endl;
    return;
  }
  random_device rd;  //obtain a random number from hardware
  mt19937 gen(rd());  //seed the generator
  uniform_int_distribution<> distr(0, n - 1);  //define the range (0-n)
  int index1 = distr(gen);  //get index of first city to swap
  int index2 = distr(gen);  //get index of second city to swap
  while (index1 == index2) {  //check if both indexes are the same
    index2 = distr(gen);  //get index of second city to swap
  }
  double x1 = A[index1][0];  //store the x coordinate of the first point
  double x2 = A[index1][1];  //store the y coordinate of the first point
  A[index1][0] = A[index2][0];  //place x coordinate of index2 into index1
  A[index1][1] = A[index2][1];  //place y coordinate of index2 into index1
  A[index2][0] = x1;  //place index1's x coordinate in index2
  A[index2][1] = x2;  //place index1's y coordinate in index2
}
//---------------------------------------------------------------------------
/**(add to your existing utes.cpp file.)
 * This function performs an invert (or inversion or flip).
 *
 * double A[][2] = { {0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7} };
 * call invert( A, 8, 3, 4 ):               A      B      C      D
 * after:          { {0,0}, {1,1}, {2,2}, {6,6}, {5,5}, {4,4}, {3,3}, {7,7} }
 *                                          D      C      B      A
 *
 * for full credit, this function should be able to handle inverts that extend
 * beyond the end of the array and wrap around to the beginning. for example,
 * double X[][2] = { {0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7} };
 *                     C      D                                  A      B
 * call invert( X, 8, 6, 4 ):
 * after:          { {7,7}, {6,6}, {2,2}, {3,3}, {4,4}, {5,5}, {1,1}, {0,0} };
 *                     B      A                                  D      C
 * generous partial credit will be given for implementing the core/basic
 * functionality.
 *
 * @param A is the list of locations (x,y) of the cities in the current tour.
 * @param n is the number of cities in A.
 * @param start is the index of the beginning of the section to be inverted.
 * @param len is the length of the segment to invert.
 */
void invert(double A[][2], int n, int start, int len) {
  //check if n is less than 1:
  if(n < 1){
    cout << "function: invert() cannot be called on an array of size less than 1" << endl;
    return;
  }
  //check if variable start is in the range of A[]:
  if ((start < 0)  || (start > (n - 1))) {
    cout << "function: invert() cannot be called because start is not in the array index range" << endl;
    return;
  }
  //check if variable len is in the range of A[]:
  if ((len < 0) || (len > n)) {
    cout << "function: invert() cannot be called because len is not in the array index range" << endl;
    return;
  }
  int index1 = start;  //stores the index of the start
  int swaps = len / 2;  //keep track of how many swaps need to be executed
  len = len - 1;  //subtract 1 from len to account for index 0
  int index2 = index1 + len;  //find index of 1st city to be swapped
  while (swaps != 0) {  //keep going until we have executed all necessary swaps
    if (index2 > n - 1) {  //check for overlap over end of array
      index2 = index2 - n;
    }
    if (index1 > n - 1) {  //check if index1 walked off the end of array
      index1 = index1 - n;  //subtract index 1 by size to set it to the front
    }
    double x = A[index1][0];  //hold the x coordinate of original city
    double y = A[index1][1];  //hold the y coordinate of original city
    A[index1][0] = A[index2][0];  //swap x coordinate
    A[index1][1] = A[index2][1];  //swap y coordinate
    A[index2][0] = x;  //give index2 original x coordinate of index1
    A[index2][1] = y;  //give index2 original y coordinate of index1
    index1 = index1 + 1;  //increment index1 to next city
    index2 = index2 - 1;  //increment index2 to prior city
    if (index2 < 0) {  //check if index2 went under 0
      index2 = n + index2;  //fix index2 to be set at the end of array
    }
    swaps = swaps - 1;  //decrement swaps after executing a swap
  }
}
//---------------------------------------------------------------------------
/**add to your existing utes.cpp file.
 * translate moves a sequence around.
 *
 * double A[][2] = { {0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7} };
 *                          ^dst                          A      B      C
 * call translate( A, 8, 5, 3, 1 ):
 * after:          { {0,0}, {5,5}, {6,6}, {7,7}, {1,1}, {2,2}, {3,3}, {4,4} };
 *                            A      B      C
 *
 * for full credit, this function should be able to handle translations that
 * extend beyond the end of the array and wrap around to the beginning.
 * generous partial credit will be given for implementing the core/basic
 * functionality.
 *
 * @param A is the list of locations (x,y) of the cities in the current tour.
 * @param n is the number of cities in A.
 * @param src is the index of the beginning of the section to be translated (moved).
 * @param len is the length of the segment to translate.
 * @param dst is the index of the beginning of the target of moving.
 */
void translate(double A[][2], int n, int src, int len, int dst) {
  //the following 3 if statements check for valid inputs, if they are invalid 
  //it will return and exit the function:
  if ((src < 0) || (src > (n - 1))) {  //check if src is a valid input
    cout << "function: translate() cannot be called because src is not in the array index range" << endl;
    return;
  }
  if ((len < 0) || (len > (n - 1))) {  //check if len is a valid input
    cout << "function: translate() cannot be called because len is not in the array index range" << endl;
    return;
  }
  if ((dst < 0) || (dst > (n - 1))) {  //check if dst is a valid input
    cout << "function: translate() cannot be called because dst is not in the array index range" << endl;
    return;
  }
  //copy A[] into B[]:
  double(*B)[2] = new double[n][2];  //B is a ptr to pairs of doubles
  for (int i = 0; i < n; i++) {  //loop through to copy the tour B[]
    B[i][0] = A[i][0];  //copy x coordinate
    B[i][1] = A[i][1];  //copy y coordinate
  }
  //place segment into intended spot:
  int index = dst;  //start of intended spot for segment
  int index2 = src;  //start of the segment to be moved
  for (int i = 0; i < len; i++) {  //loops through beginning to end of dst 
    A[index][0] = B[index2][0];  //place x coordinate of segment into dst
    A[index][1] = B[index2][1];  //place y coordinate of segment into dst
    index2 = index2 + 1;  //incerement index of segment
    index = index + 1;  //increment index of dst
    if (index > (n - 1)) {  //if dst index goes over the end of A[]:
      index = index - n;  //make it wrap around to front of array
    }
    if (index2 > (n - 1)) {  //if src index goes over the end of A[]:
      index2 = index2 - n;  //make it wrap around to front of array:
    }
  }
  int replace = n - len;  //keeps track of how many replaces to do
  int beg = dst;  //holds beginning of segment
  int end = dst + (len - 1);  //holds end of segment
  if (end > (n - 1)) end = end - n;  //fix end to wrap around to front if needed
  //new array to hold the index of array values that are not part of the segment:
  int* ar = new int[replace];
  int srcBeg = src;  //keeps track of start of segment
  int srcEnd = src + (len - 1);  //keeps track of end of segment
  //fix srcEnd to wrap around to front if needed:
  if (srcEnd > (n - 1)) srcEnd = srcEnd - n;
  int replace2 = replace;  //a copy of replace to be used in while loop
  //keeps track of index of values in A[] that are not part of segment:
  int ind = 0;
  int ind2 = 0;//variable to be incremented to step through every element of A[]
  //keep looping until all necessary indexes have been placed into ar[]:
  while (replace2 != 0) {
    //fix ind2 to wrap around to front if needed
    if (ind2 > (n - 1)) ind2 = ind2 - n;
    //fix ind to wrap around to front if needed
    if (ind > (n - 1)) ind = ind - n;
    //in this case the beginning of segment is greater than the end and ind is
    //pointing to a value in A[] that is not part of the segment:
    if ((ind < srcBeg) && (ind > srcEnd) && (srcBeg > srcEnd)) {
      //place the index of the value in that sits at A[ind] into ar[]:
      ar[ind2] = ind;
      replace2 = replace2 - 1;  //decrement replace2 after placing value in ar[]
      ind2 = ind2 + 1;  //increment ind2 to next spot of ar[]
    }
    //in this case the beginning of the segment is less than the end and ind
    //is pointing to a value in A[] that is after the segment:
    else if ((ind > srcEnd) && (srcBeg < srcEnd)) {
      //place the index of the value in that sits at A[ind] into ar[]:
      ar[ind2] = ind;
      replace2 = replace2 - 1;  //decrement replace2 after placing value in ar[]
      ind2 = ind2 + 1;  //increment ind2 to next spot of ar[]
    }
    //in this case the beginning of the segment is less than the end and ind
    //is pointing to a value in A[] that is before the segment:
    else if ((ind < srcBeg) && (srcBeg < srcEnd)) {
      //place the index of the value in that sits at A[ind] into ar[]:
      ar[ind2] = ind;
      replace2 = replace2 - 1;  //decrement replace2 after placing value in ar[]
      ind2 = ind2 + 1;  //increment ind2 to next spot of ar[]
    }
    ind = ind + 1;  //increment ind to next spot of A[]
  }
  //ind3 keeps track of index of values in A[] that are not part of dst:
  int ind3 = 0;
  //ind4 keeps track of index in ar[] and ar[] holds the indexes of values in 
  //A[] that are not part of the segment:
  int ind4 = 0;
  //keep looping until all replaces have been placed into A[]:
  while (replace != 0) {
    //fix ind3 to wrap around to front of A[] if needed:
    if (ind3 > (n - 1)) ind3 = ind3 - n;
    //fix ind4 to wrap around to front of A[] if needed:
    if (ind4 > (n - 1)) ind4 = ind4 - n;
    //in this case ind3 is pointing to a value in A[] that are not part of dst:
    if ((ind3 < beg) && (ind3 > end) && (beg > end)) {
      //place the x & y coordinates of the value that ar[] points to into the
      //correct spot of A[]:
      A[ind3][0] = B[ar[ind4]][0];
      A[ind3][1] = B[ar[ind4]][1];
      replace = replace - 1;  //decrement replace after executing a replace
      ind4 = ind4 + 1;  //increment ind4 to next spot in ar[]
    }
    //in this case ind3 is pointing to a value in A[] that is before dst and
    //the beginning of dst is less than the end of dst:
    else if ((ind3 < beg) && (beg < end)) {
      //place the x & y coordinates of the value that ar[] points to into the
      //correct spot of A[]:
      A[ind3][0] = B[ar[ind4]][0];
      A[ind3][1] = B[ar[ind4]][1];
      replace = replace - 1;  //decrement replace after executing a replace
      ind4 = ind4 + 1;  //increment ind4 to next spot in ar[]
    }
    //in this case ind3 is pointing to a value in A[] that is after dst and
    //the beginning of dst is less than the end of dst:
    else if ((ind3 > end) && (beg < end)) {
      A[ind3][0] = B[ar[ind4]][0];
      A[ind3][1] = B[ar[ind4]][1];
      replace = replace - 1;
      ind4 = ind4 + 1;
    }
  ind3 = ind3 + 1;  //increment ind3 to the next spot in A[]
  }
  delete[] B;  //delete copy of A[]
  delete[] ar;  //delete array of indexes
}
