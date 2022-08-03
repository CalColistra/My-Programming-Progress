//----------------------------------------------------------------------
//file: mergeSort.cpp
//Author: Cal Colistra
#include  < limits.h >  //import for INT_MAX for sentinel value
#include  < iostream >  //import for printing/input
using namespace std;

//function to print an array of size n:
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {  //iterate from start to end of array
    cout << arr[i] << " ";  //print each value
  }
    cout << endl;  //end line to indicate end of array
}

//Merge Function: (p = beginning, q = midpoint, r = end)
void merge(int A[], int p, int q, int r) {
  int n1 = q - p + 1;  //compute length of left subarray
  int n2 = r - q;  //compute length of right subarray
  int* L = new int[n1 + 1];  //initialize left array
  int* R = new int[n2 + 1];  //initialize right array
  int i, j;  //i = index of L[], j = index of R[]

  for (i = 0; i < n1; i++) { //iterate from begining to end of L[]
    L[i] = A[p + i];  //initialize left subarray with values from A[]
  }

  for (j = 0; j < n2; j++) {  //iterate from begining to end of R[]
    R[j] = A[q + j + 1];  //initialize right subarray with values from A[]
  }

  L[n1] = INT_MAX;  //place sentinel at the end of left subarray
  R[n2] = INT_MAX;  //place sentinel at the end of right subarray
  i = 0;  //index to be incrememnted for Left subarray
  j = 0;  //index to be incrememnted for Right subarray
  int k;  //index to be incremented from A[p] to A[r]

//merge L[] and R[] back into A[]:
  for (k = p; k <= r; k++) {  //loop to iterate from beginning to end of A[]
    if (L[i] <= R[j]) {  //check if value in L[] is smaller than in R[]:
      A[k] = L[i];  //copy value from L[] back into A[]
      i = i + 1;  //increment to next value in L[]
    }
    else {  //value in R[] is smaller than value in L[]
      A[k] = R[j];  //copy value from R[] into A[]
      j = j + 1;  //increment to next value of R[]
    }
  }
  delete[] R;  //clear memory space
  L = nullptr;  //get rid of pointer
  delete[] L;  //clear memory space
  R = nullptr;  //get rid of pointer
}

//function that splits arrays, sorts them, and combines them:
void sort(int A[], int p, int r) {  //p = beggining of A[], r = end of A[]
  int q;  //variable to hold the mid point of an array
  if (p < r) {  //check if A[] has more than 1 value
    q = (p + r) / 2;  //find the mid point of A[]
    sort(A, p, q);  //recursive call for new subarrays
    sort(A, q + 1, r);  //recursive call for new subarrays
    merge(A, p, q, r);  //combine subarrays
    }
}

//mergeSort function that calls sort:
void mergeSort(int A[], int n) {  //int A[] is the array to be sorted
  sort (A, 0, n - 1);  //int n is the length of the array
}
