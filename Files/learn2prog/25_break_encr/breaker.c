#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int find_offset(int c){
  int char_position = c - 97;
  if (char_position<0 || char_position>25) {
    fprintf(stderr, "Dammmn !\n");
    return EXIT_FAILURE;
  }
  
  int offset = (char_position + 22) % 26;

  //printf("The position of e (%c here) is %d\n", c, char_position);
  //printf("The e is now : %c\n", c);
  //printf("Offset = %d\n", offset);
  return offset; 
}

int find_most_repeted(int * let_ptr, int * rep_ptr, int n){
  int maxReps = 0;
  int c = '?';

  for (int i=0; i<n; i++){
    if (rep_ptr[i] > maxReps){
      maxReps = rep_ptr[i];
      c = let_ptr[i];
    }
  }

  return c;
}

void print_arrays(int * let_ptr, int * rep_ptr, int n){
  for (int i=0; i<n; i++){
    printf("%c  ", let_ptr[i]);
  }
  printf("\n");
  
  for (int i=0; i<n; i++){
    printf("%d ", rep_ptr[i]);
    if (rep_ptr[i] < 9){
      printf(" ");
    }
  }
  printf("\n\n");
}

void update_rep_array(int c, int * let_ptr, int * rep_ptr, int n){
  for (int i=0; i<n; i++){
    if (let_ptr[i] == c){
      rep_ptr[i] += 1;
      break;
    }
  }
}

int isAlpha(int c){
  c = tolower(c);
  if (c>=97 && c<97+26){
    return 1;
  }
  return 0;
}

void read_file_and_count_reps(FILE * f, int * let_ptr, int * rep_ptr, int n){
  int c = 0;
  while ( (c=fgetc(f)) != EOF) {
    if ( isAlpha(c) ){
      update_rep_array(c, let_ptr, rep_ptr, n);
    }
      // printf("%c", c);
      // }
  }
  //printf("\n");
}

int main(int argc, char ** argv){
  if (argc != 2) {
    fprintf(stderr, "Usage: decipher inputFileName\n");
    return EXIT_FAILURE;
  }
  
  FILE * f = fopen(argv[1], "r");
  
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  } 

  int n = 26;  
  int letters[26] = {0};
  for (int i = 0; i<n; i++) {
    letters[i] = i+97;
  }
  int reps[26] = {0};

  //print_arrays(letters, reps, n);
  read_file_and_count_reps(f, letters, reps, n);

  //print_arrays(letters, reps, n); 
  int c = find_most_repeted(letters, reps, n);
  
  //print_arrays(letters, reps, n);
  int key = find_offset(c);
  printf("%d\n",key);

  if (fclose(f) != 0){
    perror("Failed to close the input file!");
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}
