#include <stdlib.h>
#include <stdio.h>

int factorial(int n);
void factorial_test();

void main(){
 factorial_test(); 
}

int factorial(int n){
 int answer = 1;
 
 if(n == 0){
  return answer;
 } else {
  for(int i = 0; i < n; i++){
   answer =  answer * (n - i);
  }
  return answer;
 }
 
 
}

void factorial_test(){
 for(int i = 0; i < 10; i++){
  printf("%d! = %d\n", i, factorial(i));
 }
}

