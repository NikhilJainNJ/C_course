#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

counts_t * createCounts(void) {
  counts_t * counts = malloc(sizeof(*counts));
  counts->grades = NULL;
  counts->size = 0;
  return counts;
}

int incrementCount(counts_t * c, const char * name){
  for (size_t i=0; i<c->size; i++) {
    if (strcmp(c->grades[i]->grade, name) == 0){
      c->grades[i]->count += 1;
      return 1;
    } 
  }
  return 0;
  
}

const char * newName(const char * name){
  if ( name == NULL ){
    return "<unknown>";
  }
  return name;
}

void addCount(counts_t * c, const char * name) {  
  const char * renamed = newName(name);
  
  if ( incrementCount(c, renamed) == 0 ) {
    c->grades = realloc(c->grades, (c->size+1)*sizeof(c->grades));
    one_count_t * one_count = malloc(sizeof(*one_count));
    one_count->grade = malloc((strlen(renamed)+1)*sizeof(one_count->grade));
    strcpy(one_count->grade, renamed);
    one_count->count = 1;
    c->grades[c->size] = one_count;
    c->size += 1;
  }
}

void printCounts(counts_t * c, FILE * outFile) {
  for (size_t i=0; i<c->size; i++){
    fprintf(outFile, "%s: %zu\n", c->grades[i]->grade, c->grades[i]->count);
  }
}

void freeCounts(counts_t * c) {
  for (size_t i=0; i<c->size; i++){
    free(c->grades[i]->grade);
    free(c->grades[i]);
  }
  free(c->grades);
  free(c);
}
