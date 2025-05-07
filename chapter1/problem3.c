#include <stdlib.h>
#include <stdio.h>

void factors();

void main(){
 factors();
}

void factors(){
 int num;
 printf("Enter a number to find its factors:");
 scanf("%d", &num);
 
 for(int i = 1; i < num; i++){
  if((num % i) == 0){
   printf("%d is a factor\n", i);
  }
 }
}
