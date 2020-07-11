#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  // create counts array
  counts_t * c = createCounts();
  
  FILE * f = fopen(filename, "r");

  if ( f == NULL ) {
    fprintf(stderr, "Could not open file '%s'\n", filename);
    return NULL;
  }

  // read it line by line
  char * curr = NULL;
  size_t sz = 0;
  size_t unknownCount = 0;
  while (getline(&curr, &sz, f) >= 0){
    char * cr = strchr(curr, '\n');
    size_t crPos = cr - curr;
    curr[crPos] = '\0';
    // iterate through pairs
    int isUnknown = 1;
    for (size_t i=0; i<kvPairs->size; i++){
      if (strcmp(curr,kvPairs->pairs[i]->key) == 0){
        addCount(c, kvPairs->pairs[i]->value);
	isUnknown = 0;
	break;
      }
    }
    if (isUnknown == 1){
      unknownCount++;
    }
    free(curr);
    curr = NULL;
  }
  free(curr);
  
  for (size_t j=0; j<unknownCount; j++){
    addCount(c, "<unknown> ");
  }

  if ( fclose(f) != 0 ){
    fprintf(stderr, "Could not close file '%s'\n", filename);
    return NULL;
  }

  return c;
}

int main(int argc, char ** argv) {
  //read the key/value pairs from the file named by argv[1] (call the result kv)
  if ( argc < 3 ){
    fprintf(stderr, "Usage : count_values kvsFileName firstListName nListName \n");
    return EXIT_FAILURE;
  }
  
  kvarray_t * kvPairs = readKVs(argv[1]);
  
  //count from 2 to argc (call the number you count i)
  for ( size_t i=2; i<argc; i++){
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    counts_t * c = countFile(argv[i], kvPairs);
    
    //compute the output file name from argv[i] (call this outName)
    char * outName = malloc( ( strlen(argv[i])+7+1 )* sizeof(*outName));
    strcpy(outName, argv[i]);
    strcat(outName, ".counts");

    FILE * f = fopen(outName, "w");

    if (f == NULL){
      fprintf(stderr, "Could not open file '%s'\n", outName);
      return EXIT_FAILURE;
    }
    
    printCounts(c, f);
    
    if ( fclose(f) != 0 ){
      fprintf(stderr, "Could not close file '%s'\n", outName);
      return EXIT_FAILURE;
    }
    
    free(outName);
    freeCounts(c);
  }

  freeKVs(kvPairs);
  return EXIT_SUCCESS;
}
