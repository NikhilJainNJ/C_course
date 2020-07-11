#include <stdio.h>
#include <stdlib.h>

/*
unsigned power(unsigned x, unsigned y){
  if(y==0) { return 1; }
  if(y==1) { return x; }

  unsigned ans = x;
  int i = 1;
  
  while ( i < y){
    ans *= x;
    i++;
  }

  return ans;
}
*/


unsigned power_helper(unsigned x, unsigned y, unsigned ans){
  if(y==0) { return ans; }
  return power_helper(x, y-1, ans*x);
}

unsigned power(unsigned x, unsigned y){
  return power_helper(x, y, 1);
}
