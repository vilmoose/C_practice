#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>

int recursive_factorial(int n);
void factorial_test();

void main(){
 factorial_test(); 
 printf("%d\n", recursive_factorial(12));
 recursive_factorial(13);
}

int recursive_factorial(int n){
 int answer = 1; 
 if(n == 0){
  return answer = 1;
 }else if(n > 12){
  printf("!!Warning!! Any integer over 12 will cause overflow in C\n");
  printf("!!Warning!! This function only handles up to 12!\n");
 }else {
  answer = n * recursive_factorial(n - 1);
  return answer;
 }
}

void factorial_test(){
 for(int i = 0; i < 10; i++){
  printf("%d! = %d\n", i, recursive_factorial(i));
 }
}

