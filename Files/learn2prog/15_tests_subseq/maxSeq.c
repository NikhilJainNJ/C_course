#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

size_t maxSeq(int * array, size_t n){
  printf("\n----------------------------------------\n");
  //printf("Array : ");
  for (size_t j = 0; j<n; j++){
    printf("%d ", array[j]);
  }
  printf("\n");
  
  if (n <= 0) { printf("maxLength = %d\n", 0); return 0; }
  if (n == 1) { printf("maxLength = %d\n", 1); return 1; }

  size_t maxLength = 1;
  size_t currentLength = 1;

  int * lastNumber = &array[0];
  int * currentNumber = &array[0];
  
  for (size_t i=1; i<n; i++) {
    currentNumber = &array[i];
    if (*currentNumber > *lastNumber){
      currentLength += 1;
      if (currentLength > maxLength) {
	maxLength = currentLength;
      }
    }
    else {
      currentLength = 1;
    }
    lastNumber = currentNumber; 
  }

  printf("maxLength = %zu\n", maxLength);
  return maxLength;
}

