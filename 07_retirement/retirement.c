#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void retirement(int startAge, //in months
		double initial, //initial savings in dollars
		retire_info working, //info about working
		retire_info retired) //info about being retired
{
  
  double balance_monthly = initial;
  int total_period = startAge + working.months + retired.months;
  for(int i = startAge; i<total_period; i++){
    int age_years = (i/12);
    int age_months = i - (age_years*12);
    printf("Age %3d month %2d you have $%.2f\n", age_years, age_months, balance_monthly);
    if(i<(startAge+working.months)){
      balance_monthly = balance_monthly+(balance_monthly*(working.rate_of_return/12)*0.01) + working.contribution;
      }
    else if((i>=(startAge+working.months))&&(i<(total_period))){
      balance_monthly = balance_monthly+(balance_monthly*(retired.rate_of_return/12)*0.01) + retired.contribution;
      }
    }
}

int main(){
  
  int startAge = 327;
  double initial = 21345;
  retire_info working = {489,1000,4.5};
  retire_info retired = {384,-4000,1};
  retirement(startAge,initial,working,retired);
}
