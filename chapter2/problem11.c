#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n);
bool get_positive_int(int n);
void pos_prime();

void main(){
 printf("%d\n", get_positive_int(10));
 printf("%d\n", get_positive_int(-10));
 printf("%d\n", is_prime(5));
 printf("%d\n", is_prime(10));
 pos_prime();
}

bool is_prime(int n){
 int count = 0;
 
 for(int i = 2; i < n - 1; i++){
  if((n % i) == 0){
   count++;
   printf("%d is not a prime number\n", n);
   return false;
  }
 }
 if(count == 0){
  printf("%d is a prime number, no factors found\n", n);
  return true;
 }
}

bool get_positive_int(int n){
 if(n < 0){
  return false;
 }else {
  return true;
 }
}

void pos_prime(){
 int input; 
 bool val;
 printf("Input a positive number to find all prime numbers less than or equal to it: ");
 scanf("%d \n", &input);

 if(get_positive_int(input)){
  for(int i = 0; i <= input; i++){
   if(is_prime(i)){
    printf("%d ", i);
   }
  }
  printf("\n");
 } else {
  printf("Input is not a positive number\n");
 }
}
