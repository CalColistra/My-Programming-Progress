//----------------------------------------------------------------------
//  file: sortMain.cpp
//  Author: Cal Colistra
//----------------------------------------------------------------------
#include < iostream >  //import for printing/input
#include < random >  //import for random number generation
#include < math.h >  //import for random number generation
#include < time.h >  //import for recording time
#include < Windows.h >  //import for recording time

extern void printArray(int a[], int n);
extern void merge(int a[], int p, int q, int r);
extern void sort(int a[], int p, int r);
extern void mergeSort(int a[], int r);

using namespace std;

//function to get CPU time, based on:
//http://stackoverflow.com/questions/19378805/measure-cpu-time-on-windows-using-getprocesstimes
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

int main(int argc, char* argv[]) {  //begin main
  srand((unsigned int)time(NULL));  //initialize the random number generator
  int const arraySize = 25;  //size of array size to be sorted
  int const repitition = 1;  //number of repititions to sort & initialize a[]

  double cpuTime_r = 0;  //CPU time of random number generation
  double cpu_time = 0;  //CPU time of sorting the array
  double elapsedRand = 0;  //time elapsed for random number generation
  double elapsedSort = 0;  //time elapsed for sorting the array
  double sort_time;  //official time elasped for sorting the array
  double totalCPU_time = 0;  //official CPU time for sorting the array


//for loop to repeatedly make new arrays with random numbers and call mergeSort
  for (int i = 1; i <= repitition; i++) {  //repitition = number of iterations
    clock_t start_r = 0;  //reset start clock time of random # generation
    clock_t end_r = 0;  //reset end clock time of after random # generation
    double startCPU_r = 0;  //reset start CPU time of random # generation
    double  endCPU_r = 0;  //reset end CPU time of random # generation

    clock_t start = 0;  //reset start clock time of sort
    clock_t end = 0;  //reset end clock time of sort
    double startCPU = 0;  //reset start CPU time of sort
    double  endCPU = 0;  //reset end CPU time of sort

    int* a = new int[arraySize];  //initialize array to be sorted

//--------Start timing for random number generation---------------------------
    start_r = clock();  //set start clock
    startCPU_r = cpuTime();  //set start CPU time
  
    for (int i = 0; i < arraySize; i++) {  //loop to initialize array with rand
      a[i] = rand();  //place a random number at each index of a[]
    }

    //printArray(a, arraySize);  //print unsorted array for debugging

    endCPU_r = cpuTime();  //end CPU time
    end_r = clock();  //end clock
//--------End timing for random number generation-----------------------------

//calculate CPU time & add to total
    cpuTime_r = cpuTime_r + (endCPU_r - startCPU_r);
//calculate time elapsed & add to total:
    elapsedRand = elapsedRand + (((double)end_r - start_r) / CLOCKS_PER_SEC);

//--------Start timing for Merge Sort-----------------------------------------
    start = clock();  //start clock
    startCPU = cpuTime();  //start CPU time
    mergeSort(a, arraySize);  //call mergeSort on a[]
    endCPU = cpuTime();  //end CPU time
    end = clock();  //end clock
//--------End timing for Merge Sort-------------------------------------------

//calculate CPU time & add to total
    cpu_time = cpu_time + (endCPU - startCPU);
//calculate time elapsed & add to total
    elapsedSort = elapsedSort + (((double)end - start) / CLOCKS_PER_SEC);

//Subtract time for sort by time for random number generation:
    if (elapsedSort >= elapsedRand) {  //avoid negative subtraction
      sort_time = elapsedSort - elapsedRand;
    }
    else {  //in this case: elapsedRand > elapsedSort
      sort_time = elapsedRand - elapsedSort;
    }
//Subtract CPU time for sort by CPU time for random number generation:
    if (cpu_time >= cpuTime_r) {  //avoid negative subtraction
        totalCPU_time = cpu_time - cpuTime_r;
    }
    else {  //in this case: cpuTime_r > cpu_time
        totalCPU_time = cpuTime_r - cpu_time;
    }


    //printArray(a, arraySize);  //print sortedarray for debugging

    delete[] a;  //free memory space
    a = nullptr;  //get rid of pointer
  }
/*print statements for debugging:
  cout << "Time elapsed for sorting = " << sort_time << " ";
  cout << endl;
  cout << "CPU time it took to sort = " << totalCPU_time << " ";
  cout << endl;
  */
  return 0;
}