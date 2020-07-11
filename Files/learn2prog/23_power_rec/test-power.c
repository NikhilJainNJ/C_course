#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned power(unsigned x, unsigned y);


int main(void){
  printf("Power of 0 by 0 = %u\n", power(0, 0));
  assert(power(0, 0)==1);//ok*

  printf("Power of 5 by 0 = %u\n", power(5, 0));
  assert(power(5, 0)==1);
  

  printf("Power of 1 by 1 = %u\n", power(1, 1));
  assert(power(1, 1)==1);
  
  ////assert(power(-1, 1)==-1);

  printf("Power of 0 by 2 = %u\n", power(0, 2));
  assert(power(0, 2)==0);//ok

  printf("Power of 1 by 2 = %u\n", power(1, 2));
  assert(power(1, 2)==1);

  printf("Power of 2 by 2 = %u\n", power(2, 2));
  assert(power(2, 2)==4);//ok

  printf("Power of 3 by 2 = %u\n", power(3, 2));
  assert(power(3, 2)==9);

  printf("Power of -2 by 2 = %u\n", power(-2, 2));
  assert(power(-2, 2)==4);//ok

  printf("Power of -3 by 3 = %d\n", power(-3, 3));
  assert(power(-3, 3)==-27);//ok*
  
  return EXIT_SUCCESS;
}
