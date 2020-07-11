#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double show(int age,
	    double savings,
	    retire_info period){

  printf("Age %3d month %2d you have $%.2lf\n", age/12, age%12, savings);    
  savings =  savings*period.rate_of_return + savings + period.contribution;
  return savings;
}

void retirement(int startAge,        // in months
		double initial,      // initial savings
		retire_info working, // info about working
                retire_info retired){  // info about being retired

  int age = startAge;
  double savings = initial;
  
  for (int i = working.months+retired.months; i>0; i--) {
   
    if (working.months>0){
      retire_info period = working;
      savings = show(age, savings, period);
      working.months --;
    }
    else if (retired.months>0){
      retire_info period = retired;
      savings = show(age, savings, period);
      retired.months --;
    }
    
    age++;
  }
}


int main(void){
  retire_info working;
  retire_info retired;
  int age = 327;
  double savings = 21345;

  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  retirement(age, savings, working, retired);
  
  return EXIT_SUCCESS;
}
