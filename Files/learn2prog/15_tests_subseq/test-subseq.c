#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

size_t maxSeq(int * array, size_t n);

void further_test(){
  int arr1[] = {1, 3, 5, -2, -6, 0, 2, 4, 6};
  maxSeq(arr1, 9);

  int arr2[] = {1, 3, 5, -2, -6, -8, -12, -14, 6};
  maxSeq(arr2, 9);

  int arr3[] = {1, 3, 5, 2, 6, 0, 2, 4, 6, 7,
                2, 5, 4, 6, 7, 9, 0, 5, 6, 8,
                8, 7, 6, 5, 4, 2, 3, 1, 2, 0,
                7, 5, 6, 8, 1, 2, 3, 4, 6, 9,
                1, 3, 6, 5, 2, 3, 6, 8, 9, 7,
                8, 9, 6, 7, 5, 3, 1, 2, 5, 9,
                1, 2, 3, 4, 5, 6, 7, 8, 5, 6,
                0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                8, 5, 1, 2, 3, 0, 0, 1, 7, 6,
                6, 3, 0, 1, 2, 4, 5, 7, 6, 7,
                8};
  maxSeq(arr3, 101);

  int arr4[] = {1, 2, 3, 4, 3, 2, 0, 3, 4, 5, 6, 7, 8, 3, 2, 5, 6, 7};
  maxSeq(arr4, 18);
}

int main(void) {
  further_test();
  
  int array1[] = {};
  if (maxSeq(array1, 0) != 0) { printf("Array1 of 0 elements failed"); exit(EXIT_FAILURE);}
  
  
  int array11[] = {1};
  if (maxSeq(array11, 1) != 1) { printf("Array11 of 1 elements failed"); exit(EXIT_FAILURE);}
  
  int array2[] = {-1, 0};
  if (maxSeq(array2, 2) != 2) { printf("Array2 of 2 elements failed"); exit(EXIT_FAILURE);}

  //int array22[2] = {4, 4};
  //if (maxSeq(array22, 2) != 1) { printf("Array22 of 2 elements failed"); exit(EXIT_FAILURE);}
  
  int array222[] = {4, -1};
  if (maxSeq(array222, 2) != 1) { printf("Array222 of 2 elements failed"); exit(EXIT_FAILURE);}
  
  int array3[] = {1, 1, 2};
  if (maxSeq(array3, 3) != 2) { printf("Array3 of 3 elements failed"); exit(EXIT_FAILURE);}

  int array33[] = {1, 2, 3};
  if (maxSeq(array33, 3) != 3) { printf("Array33 of 3 elements failed"); exit(EXIT_FAILURE);}
  
  //int array4[7] = {1, 2, 1, 2, 3, 1, 2};
  //if (maxSeq(array4, 7) != 3) { printf("Array4 of 7 elements failed"); exit(EXIT_FAILURE);}
  
  return EXIT_SUCCESS;
}

