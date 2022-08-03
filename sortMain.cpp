//----------------------------------------------------------------------
//  file: sortMain.cpp
//  Author: Cal Colistra
//----------------------------------------------------------------------
#include < iostream >
#include < random >
#include < math.h >
#include < time.h >
#include < Windows.h >
extern void insertionSort (int a[], int n);
extern void printArray (int a[], int n);
using namespace std;

//  function to get CPU time, based on:
//  http://stackoverflow.com/questions/19378805/measure-cpu-time-on-windows-using-getprocesstimes
static double cpuTime(void) {
  FILETIME  createTime, exitTime, kernelTime, userTime;
    if (GetProcessTimes(GetCurrentProcess(), &createTime, &exitTime,
        &kernelTime, &userTime) != -1) {
          SYSTEMTIME  userSystemTime;

      if (FileTimeToSystemTime(&userTime, &userSystemTime) != -1) 
        return (double)userSystemTime.wHour * 3600.0 +
        (double)userSystemTime.wMinute * 60.0 +
        (double)userSystemTime.wSecond +
        (double)userSystemTime.wMilliseconds / 1000.0;
    }
    return -1;
}

int main(int argc, char* argv[]) {
  srand((unsigned int) time(NULL));  //  initialize rand num gen
//  variable for array size
  int const arraySize = 400000;
//  variable for repitions
  int const repitition = 1;
  int *a = new int [arraySize];  //  array to be sorted

//  start timing for rand num gen:
  clock_t start_r = clock();
  double startCPU_r = cpuTime();
  for (int i = 0; i < arraySize; i++) {  //  loop to initialize array with rand
    a[i] = rand();
  }

//  end and calculate timing for rand num gen:
  double  endCPU_r = cpuTime();
  clock_t end_r = clock();
  double cpuTime_r = endCPU_r - startCPU_r;
  double elapsedRand = ((double)end_r - start_r) / CLOCKS_PER_SEC;

// time the insertion sort:
  clock_t start = clock();
  double startCPU = cpuTime();
  for (int i = 1; i <= repitition; i++) {
    insertionSort(a, arraySize);
  } 

// end & calculate timing of the sort:
  double  endCPU = cpuTime();
  clock_t end = clock();
  double cpuTime = endCPU - startCPU;
  double elapsedSort = ((double)end - start) / CLOCKS_PER_SEC;
  double sort_time;   //  initialize variable for sort time
  if (elapsedSort >= elapsedRand) {  // avoid negative subtraction
    sort_time = elapsedSort - elapsedRand;
  }
  else {
    sort_time = elapsedRand - elapsedSort;
  }
  delete[] a;  //  free memory space
    
//  print statements for debugging:
//  printArray(a, arraySize); 
//  cout << "clock start time = " << start << " ";
//  cout << "clock end time = " << end << " ";
//  cout << "cpu start time = " << startCPU << " ";
//  cout << "cpu end time = " << endCPU << " ";    
//  cout << "elapsed Sort = " << elapsedSort << " ";
//  cout << "elapsedRand = " << elapsedRand << " ";
  cout << "sort time = " << sort_time << " ";
  cout << "cpu time = " << cpuTime << " ";
  return 0;                   
}