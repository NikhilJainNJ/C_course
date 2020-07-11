#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long myatoi(const char * str);
long myatoiHex(const char * str);
long mystrtol(const char * str, char ** endptr, int base);

int test_mystrtol(){
  char * p1;
  char * p2;
  const char * str1 = "123a456";
  printf("----------------\n");
  printf("Input    = '%s'\n", str1);
  printf("Expected =  %ld", strtol(str1, &p1, 10));
  printf("  |  Pointer = %s\n", p1);
  printf("Output   =  %ld", mystrtol(str1, &p2, 10));
  printf("  |  Pointer = %s\n", p2);

  const char * str2 = "a123456";
  printf("----------------\n");
  printf("Input    = '%s'\n", str2);
  printf("Expected =  %ld", strtol(str2, &p1, 10));
  printf("  |  Pointer = %s\n", p1);
  printf("Output   =  %ld", mystrtol(str2, &p2, 10));
  printf("  |  Pointer = %s\n", p2);

  const char * str3 = "1235.";
  printf("----------------\n");
  printf("Input    = '%s'\n", str3);
  printf("Expected =  %ld", strtol(str3, &p1, 10));
  printf("  |  Pointer = %s\n", p1);
  printf("Output   =  %ld", mystrtol(str3, &p2, 10));
  printf("  |  Pointer = %s\n", p2);
  
  printf("\n");
}

int test_myatoiHex(){
  const char * str1 = "AF";
  printf("----------------\n");
  printf("Input    = '%s'\n", str1);
  printf("Expected =  %ld\n", strtol(str1, NULL, 16));
  printf("Output   =  %ld\n", myatoiHex(str1));

  const char * str2 = "af";
  printf("----------------\n");
  printf("Input    = '%s'\n", str2);
  printf("Expected =  %ld\n", strtol(str2, NULL, 16));
  printf("Output   =  %ld\n", myatoiHex(str2));

  const char * str3 = "7af9";
  printf("----------------\n");
  printf("Input    = '%s'\n", str3);
  printf("Expected =  %ld\n", strtol(str3, NULL, 16));
  printf("Output   =  %ld\n", myatoiHex(str3));

  const char * str4 = "af.5";
  printf("----------------\n");
  printf("Input    = '%s'\n", str4);
  printf("Expected =  %ld\n", strtol(str4, NULL, 16));
  printf("Output   =  %ld\n", myatoiHex(str4));

  const char * str5 = "zaf";
  printf("----------------\n");
  printf("Input    = '%s'\n", str5);
  printf("Expected =  %ld\n", strtol(str5, NULL, 16));
  printf("Output   =  %ld\n", myatoiHex(str5));
  
  const char * str6 = "91+B";
  printf("----------------\n");
  printf("Input    = '%s'\n", str6);
  printf("Expected =  %ld\n", strtol(str6, NULL, 16));
  printf("Output   =  %ld\n", myatoiHex(str6));
  
  printf("\n");
}

int test_myatoi(){
  const char * str1 = "123";
  printf("----------------\n");
  printf("Input    = '%s'\n", str1);
  printf("Expected =  %d\n", atoi(str1));
  printf("Output   =  %ld\n", myatoi(str1));
  
  const char * str2 = "123a";
  printf("----------------\n");
  printf("Input    = '%s'\n", str2);
  printf("Expected =  %d\n", atoi(str2));
  printf("Output   =  %ld\n", myatoi(str2));

  const char * str3 = "a123";
  printf("----------------\n");
  printf("Input    = '%s'\n", str3);
  printf("Expected =  %d\n", atoi(str3));
  printf("Output   =  %ld\n", myatoi(str3));

  const char * str4 = "123a456";
  printf("----------------\n");
  printf("Input    = '%s'\n", str4);
  printf("Expected =  %d\n", atoi(str4));
  printf("Output   =  %ld\n", myatoi(str4));

  const char * str5 = "1.23";
  printf("----------------\n");
  printf("Input    = '%s'\n", str5);
  printf("Expected =  %d\n", atoi(str5));
  printf("Output   =  %ld\n", myatoi(str5));

  const char * str6 = "123+456";
  printf("----------------\n");
  printf("Input    = '%s'\n", str6);
  printf("Expected =  %d\n", atoi(str6));
  printf("Output   =  %ld\n", myatoi(str6));

  printf("\n");
}

int main(void){
  test_mystrtol();
  //test_myatoiHex();
  //test_myatoi();
  return EXIT_SUCCESS;
}
