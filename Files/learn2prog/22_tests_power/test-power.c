#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned power(unsigned x, unsigned y);


int main(void){
  assert(power(0, 0)==1);//ok

  //assert(power(1, 1)==1);
  ////assert(power(-1, 1)==-1);
  
  //assert(power(0, 2)==0);//ok
  //assert(power(1, 2)==1);
  //assert(power(2, 2)==4);//ok
  //assert(power(3, 2)==9);
  //assert(power(-2, 2)==4);//ok
  assert(power(-3, 3)==-27);//ok
  
  printf("%d\n", power(-3, 3));
  return EXIT_SUCCESS;
}
