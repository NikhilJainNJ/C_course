#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_matrix(int matrix[10][10]){
  for (int y = 0; y<10; y++){
    for (int x = 0; x<10; x++){
      printf("%c", matrix[y][x]);
    }
    printf("\n");
  }
}


void rotate(int matrix[10][10]){
  int mat_cp[10][10];
  int s = 10;

  for (int y = 0; y<s; y++){
    for (int x = 0; x<s; x++){
      mat_cp[y][x] = matrix[y][x];
    }
  }


  int * p1 = &mat_cp[0][0];

  for (int y=0; y<s; y++){
    for (int x=0; x<s; x++){
      p1 = &mat_cp[y][x];
      matrix[x][s-1-y] = *p1;
    }
  }

  return;
}

int extract_matrix(char * fileName, int width, int height){

  int matrix[height][width]; 
  int c = 0;
  int pos = 0;
  int line = 0;
  
  FILE * f = fopen(fileName, "r");
  
  if ( f==NULL ){
    fprintf(stderr, "Damn!! Could not open file\n\n");
    return 0;
  }

  while ( (c=fgetc(f)) != EOF ) {
    if ( c != '\n' ){   
      if ( pos > 9 ) {
        line++;
        pos = 0;
      }
      // if not new_line
      matrix[line][pos] = c;
      pos++;
    }
  }
  //print_matrix(matrix);
  //printf("\n");
  rotate(matrix);
  print_matrix(matrix);

  if (fclose(f) != 0){
    perror("Failed to close the input file!");
    return 0;
  }
  return 1;
}


int is_n_by_n_matrix(char * fileName, int width, int height){
  FILE * f = fopen(fileName, "r");
  
  if ( f==NULL ){
    fprintf(stderr, "Could not open file\n\n");
    return 0;
  }

  int c = 0;
  int pos = 0;
  int line = 0;
  int error = 0;
  
  while ( (c=fgetc(f)) != EOF ) {
    if ( line >= 10 ){
      fprintf(stderr, "Too much lines\n");
      error = 1;
      break;
    }

    if ( pos > 10 ){
      fprintf(stderr, "Line is too long\n");
      error = 1;
      break;
    }
    
    if ( c == '\n') {
      if ( pos < 10 ) {
	fprintf(stderr, "Line is too short\n");
	error = 1;
        break;
      }
      line++;
      pos = 0;
    }
    else{
      pos++;
    }
  }
  
  

  if (fclose(f) != 0){
    perror("Failed to close the input file!");
    return 0;
  }

  if (error == 1){
    return 0;
  }
  
  if (line < 10){
    fprintf(stderr, "Not enough lines\n");
    return 0;
  }
  
  return 1;
}



int main(int argc, char ** argv){  
  if (argc != 2){
    fprintf(stderr, "Usage : rotateMatrix inputFileName\n");
    return EXIT_FAILURE;
  }
  
  if ( is_n_by_n_matrix(argv[1], 10, 10)==1 ) {
    extract_matrix(argv[1], 10, 10);
  }
  else {
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}







/*
void trim_fileName(char * fileName, size_t index, char * trimed_name ){
  if ( index == 0 ){
    return;
  } 
  for (size_t i=0; i<index-1; i++){
    trimed_name[i] = fileName[i];
  }
  trimed_name[index-1] = '\0';
  printf("%s\n", trimed_name);  
}


size_t find_rtrim_index(char * fileName){
  char * null_term;
  size_t index = 0;
  null_term = strchr(fileName, '\0');
  if (null_term){
    index = null_term - fileName;
    printf("Index of null term : %zu\n", index);
  }
  else{
    fprintf(stderr, "Could not find null terminator\n");
  }
  return index;
}
*/



/*
int main(int argc, char ** argv){  
  if (argc != 2){
    fprintf(stderr, "Usage : rotateMatrix inputFileName\n");
    return EXIT_FAILURE;
  }
  
  FILE * f = fopen(argv[1], "r");
  
  if ( f==NULL ){
    fprintf(stderr, "Could not open file %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  
  char line[50] = {0};
  while ( fgets(line, 50, f) != NULL ){
      if ( strchr(line, '\n') == NULL ){
	  fprintf(stderr, "Argument line is too long\n");
          return EXIT_FAILURE;
	}
      if ( strchr(line, ' ') != NULL ){
	  fprintf(stderr, "Too many arguments\n");
          return EXIT_FAILURE;
	}
      printf("%s", line);

      size_t trim_index = find_rtrim_index(line);
      char trimed_name[trim_index];
      trim_fileName(line, trim_index, trimed_name);
     
      if ( is_n_by_n_matrix(trimed_name, 10, 10) == 1 ) {
	extract_matrix(trimed_name, 10, 10);
      }
      printf("\n");
    }

  if (fclose(f) != 0){
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
*/
