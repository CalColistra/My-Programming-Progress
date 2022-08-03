//----------------------------------------------------------------------
//file: insertionSort.cpp
//Author: Cal Colistra
//----------------------------------------------------------------------
#include  < iostream >
using namespace std;

// function to perform insertion sort on an array of size n:
void insertionSort (int A[], int n) {
  int i, key, j;
  for (j = 1; j < n; j++) {  //needs comments here
    key = A[j];
    i = j - 1;
    while (i >= 0 && A[i] > key) {  //need comments here
      A[i + 1] = A[i];
      i = i - 1;
    }
    A[i + 1] = key;
  }
}

// function to print an array of size n:
void printArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
}
