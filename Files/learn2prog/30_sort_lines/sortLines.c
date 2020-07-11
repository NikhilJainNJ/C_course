#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(char ** data, size_t count){
  for (int i=0; i<count; i++) {
    printf("%s", data[i]);
    free(data[i]);
  }
}

//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}



int read_from_file(char * fileName){
  FILE * f = fopen(fileName, "r");

  if ( f==NULL ) {
    fprintf(stderr, "Could not open file %s", fileName);
    return 0;
  }

  char * line = NULL;
  size_t sz;
  char ** array = NULL;
  size_t i = 0;
  while(getline(&line, &sz, f) > 0){
    array = realloc(array, (i+1) * sizeof(array));
    array[i] = line;
    line = NULL;
    i++;
  }
  free(line);
  sortData(array, i);
  print_array(array, i);
  free(array);

  
  if (fclose(f) != 0){
    fprintf(stderr, "Could not close file %s", fileName);
    return 0;
  }
  
  return 1;
}

void read_from_stdin(){
  char * line = NULL;
  size_t sz;
  char ** array = NULL;
  size_t i = 0;
  while(getline(&line, &sz, stdin) > 0){
    array = realloc(array, (i+1) * sizeof(array));
    array[i] = line;
    line = NULL;
    i++;
  }
  free(line);
  sortData(array, i);
  print_array(array, i);
  free(array);
}

int main(int argc, char ** argv) {
  
  if (argc == 1) {
    read_from_stdin();
  }
  else{
    for (int i=1; i<argc; i++){
      if ( read_from_file(argv[i]) == 0 ){
	return EXIT_FAILURE;
      }
    }
  }
  
  //WRITE YOUR CODE HERE!
  
  return EXIT_SUCCESS;
}
