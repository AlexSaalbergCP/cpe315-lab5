
/* Array-of-Structures vs. Structure-of-Arrays */

// includes
#include <stdlib.h>
#include <stdio.h>
#include "hrt.h"

// Adjust the number of elements based on architecture
#ifdef __arm__
  #define NUMVALUES 16777216
#elif defined __x86_64__
  #define NUMVALUES 268435456
#endif

// You'll need to modifiy this struct
typedef struct nums {
  double *mydouble;
  float *myfloat;
  long long int *mylonglong;
} myNums;

void init_nums(myNums *);
void compute_averages(myNums *);

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {

  // Data structure for the program
  myNums *SoA;  // AoS will be an array of structs
                // You'll want to convert to a struct of arrays

  // Allocate and initialize the array of structs
  // This will also need to change
  SoA  = (myNums *) malloc(sizeof(myNums));
  SoA->mydouble = (double *) malloc(NUMVALUES * sizeof(double));
  SoA->myfloat = (float *) malloc(NUMVALUES * sizeof(float));
  SoA->mylonglong = (long long int *) malloc(NUMVALUES * sizeof(long long int));



  hrt_start();
  init_nums(SoA);  // time the initialization
  hrt_stop();
  fprintf(stdout, "Initialization time of three %d vectors took %s.\n",
      NUMVALUES, hrt_string());
  
  hrt_start();
  compute_averages(SoA);  // time the computation
  hrt_stop();
  fprintf(stdout, "Computation time of three %d vectors took %s.\n",
      NUMVALUES, hrt_string());

  // Free 
  free(SoA->mydouble);
  free(SoA->myfloat);
  free(SoA->mylonglong);
  free(SoA);
  return 0;
}

////////////////////////////////////////////////////////////////////////
// You'll need to modify the following two functions to adjust how
// the data structure is accessed. 

void init_nums (myNums *SoA) {
  unsigned int fseed = 2016;
  unsigned int dseed = 2017;

  for (unsigned int i = 0; i<NUMVALUES; ++i) {
    SoA->myfloat[i] = (rand_r(&fseed) / (float)RAND_MAX);
    SoA->mydouble[i] = (rand_r(&dseed) / (double)RAND_MAX);
    SoA->mylonglong[i] = (rand_r(&dseed) / (long long int)RAND_MAX);
  }
}

void compute_averages (myNums *AoS) {
  float sumf = 0.0;
  double sumd = 0.0;
  long long int sumll = 0;

  for (unsigned int i = 0; i<NUMVALUES; ++i) {
    sumf += AoS->myfloat[i]; 
  }
  fprintf(stdout, "Average of %d floats = %.5f.\n", 
      NUMVALUES, sumf/(float)NUMVALUES);

  for (unsigned int i = 0; i<NUMVALUES; ++i) {
    sumd += AoS->mydouble[i]; 
  }
  fprintf(stdout, "Average of %d doubles= %.5lf.\n", 
      NUMVALUES, sumf/(double)NUMVALUES);
  for (unsigned int i = 0; i<NUMVALUES; ++i) {
    sumll += AoS->mylonglong[i]; 
  }
  fprintf(stdout, "Average of %d long long ints= %lld.\n", 
      NUMVALUES, sumll/(long long int)NUMVALUES);
}
