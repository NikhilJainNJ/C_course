#include <stdio.h>
#include <stdlib.h>

void print_matrix(char matrix[10][10]){
  for (int y = 0; y<10; y++){
    for (int x = 0; x<10; x++){
      printf("%c", matrix[y][x]);
    }
    printf("\n");
  }
}

void rotate(char matrix[10][10]){
  char mat_cp[10][10];
  int s = 10;
  
  for (int y = 0; y<s; y++){
    for (int x = 0; x<s; x++){
      mat_cp[y][x] = matrix[y][x];
    }
  }

  
  char * p1 = &mat_cp[0][0];
  
  for (int y=0; y<s; y++){
    for (int x=0; x<s; x++){
      p1 = &mat_cp[y][x];
      matrix[x][s-1-y] = *p1; 
    }
  }
  
  return;
}
