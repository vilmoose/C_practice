#include <stdlib.h>
#include <stdio.h>

void prime();

void main(){
 prime();
}

void prime(){
 int input, count = 0;
 printf("Input an integer number to check if its prime:");
 scanf("%d", &input);
 
 for(int i = 2; i < input - 1; i++){
  if((input % i) == 0){
   count++;
   printf("Factor found: %d\n", i);
  }
 }
 if(count == 0){
  printf("%d is a prime number, no factors found\n", input);
 }
}
