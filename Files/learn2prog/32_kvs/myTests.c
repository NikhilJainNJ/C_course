#include "kv.c"

int main(int argc, char ** argv){
  if (argc != 2){
    fprintf(stderr, "Usage : kv inputFileName");
    return EXIT_FAILURE;
  }

  kvarray_t * pairs = NULL;
  if ( (pairs=readKVs(argv[1])) == NULL ){
    fprintf(stderr, "Could not read KVs");
    return EXIT_FAILURE;
  }

  const char * key = "banana";
  printKVs(pairs);
  printf("%s\n", lookupValue(pairs, key));
  freeKVs(pairs);
  return EXIT_SUCCESS;
}
