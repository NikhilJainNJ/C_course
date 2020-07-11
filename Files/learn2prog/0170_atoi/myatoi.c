#include <stdio.h>
#include <stdlib.h>

long myatoiHex(const char * str){
  const char * p1 = str;
  long val = 0;
  
  while(*p1 != '\0'){
    if(*p1 >= 'a' && *p1 <= 'f') {
      switch(*p1){
      case 'a' : val = val*16 + 10; break;
      case 'b' : val = val*16 + 11; break;
      case 'c' : val = val*16 + 12; break;
      case 'd' : val = val*16 + 13; break;
      case 'e' : val = val*16 + 14; break;
      case 'f' : val = val*16 + 15; break;
      default  : val = val;
      }
      //printf("val = %ld\n", val);
    }
    else if(*p1 >= 'A' && *p1 <= 'F') {
      switch(*p1){
      case 'A' : val = val*16 + 10; break;
      case 'B' : val = val*16 + 11; break;
      case 'C' : val = val*16 + 12; break;
      case 'D' : val = val*16 + 13; break;
      case 'E' : val = val*16 + 14; break;
      case 'F' : val = val*16 + 15; break;
      default  : val = val;
      }
      //printf("val = %ld\n", val);
    }
    else if(*p1 >= '0' && *p1 <= '9'){
      val = val*16;
      val += *p1 - 48;
      //printf("val = %ld\n", val);
    }
    else {
      return val;
    }
    
    p1++;
  }
  
  return val;
}



long myatoi(const char * str){
  const char * p1 = str;
  long val = 0;
  
  while(*p1 != '\0'){
    if(*p1 >= '0' && *p1 <= '9'){
      val = val*10;
      val += *p1 - 48;
    }
    else {
      return val;
    }
    p1++;
  }
  
  return val;
}

long mystrtol(const char * str, char ** endptr, int base){
  *endptr = &str[0];
  int i = 0;

  if (base == 10) {
    while(**endptr != '\0' && (**endptr >= '0' && **endptr <= '9')){
      i++;
      *endptr = &str[i];
      }
    long val = myatoi(str);
    return val;
  }
  
  else if (base == 16){
    long val =  myatoiHex(str);
    return val;
  }
  return 0;
}
