#include <stdlib.h>
#include <stdio.h>

#define LINEFEED printf("\n");

int f_to_c(int temp);
void print_temp();

void main(){
 print_temp(); 
}

int f_to_c(int temp){
 int new_temp;
 new_temp = ((temp - 32) * 0.5556);
 //printf("%d\n", new_temp);
 return new_temp;
}

void print_temp(){
 int f_temp = 32, inc = 20, max = 212, c_temp;
 
 while (f_temp <= max){
  c_temp = f_to_c(f_temp);
  printf("Temperature in F: %d f\nTemperature in C: %d C", f_temp, c_temp);
  LINEFEED; 
  f_temp += inc;
 }
}
