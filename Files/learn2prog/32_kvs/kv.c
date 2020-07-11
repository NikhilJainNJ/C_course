#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t * getPair(char * line, char * separator){
  size_t firstPart = separator - line;
  size_t lastPart = strchr(line, '\n') - (separator+1);

  kvpair_t * p = calloc(1, sizeof(*p));
  p->key = calloc(firstPart+1, sizeof(*p->key));
  p->value = calloc(lastPart+1, sizeof(*p->value));

  p->key = strncpy(p->key, line, firstPart);
  p->key[firstPart] = '\0';
  p->value = strncpy(p->value, line+firstPart+1, lastPart);
  p->value[lastPart] = '\0';
  
  return p;
}

kvarray_t * readKVs(const char * fname){
  FILE * f = fopen(fname, "r");

  if ( f==NULL ){
    fprintf(stderr, "Could not open file : %s\n", fname);
    return NULL;
  } 

  kvpair_t ** pairs = NULL;
  char * curr = NULL;
  size_t sz = 0;  
  size_t i = 0;
  while(getline(&curr, &sz, f) > 0){
    char * separator = NULL;
    if ( (separator=strchr(curr, '=')) != NULL) {
      kvpair_t * p = getPair(curr, separator);
      pairs = realloc(pairs, (i+1) * sizeof(*pairs));
      pairs[i] = p;
      i++;
      free(curr);
    }
    curr = NULL;
  }
  free(curr);
  
  kvarray_t * arrStruct = malloc(sizeof(*arrStruct));
  arrStruct->pairs = pairs;
  arrStruct->size = i;
  
  if ( fclose(f) != 0 ){
    fprintf(stderr, "Could not close file : %s\n", fname);
    return NULL;
  }

  return arrStruct; 
}


void freeKVs(kvarray_t * pairs) {
  for(int i=0; i<pairs->size; i++){
    free(pairs->pairs[i]->key);
    free(pairs->pairs[i]->value);
    free(pairs->pairs[i]);
  }
  free(pairs->pairs);
  free(pairs);
}


void printKVs(kvarray_t * pairs) {
  for(int i=0; i<pairs->size; i++){
    printf("key = '%s' value = '%s'\n", pairs->pairs[i]->key, pairs->pairs[i]->value);
  }
}


char * lookupValue(kvarray_t * pairs, const char * key) {
  for(int i=0; i<pairs->size; i++){
    if ( strcmp(key, pairs->pairs[i]->key) == 0 ) {
      return pairs->pairs[i]->value;
    }
  }
  return NULL;
}


