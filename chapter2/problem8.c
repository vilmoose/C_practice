#include <stdlib.h>
#include <stdio.h>

int x_to_int_n(int x, int n);
void x_to_int_n_test();

void main(){
 x_to_int_n_test();
}

int x_to_int_n(int x, int n){
 int ans = 0;
 
 if(n == 0){
  return ans = 1;
 }
 
 for(int i = 0; i < n; i++){
  if(i == 0){
   ans = x;
  }else{
   ans = (ans * x);
  }
 }
 return ans;
}

void x_to_int_n_test(){
 for(int i = 1; i < 12; i++){
  for (int j = 0; j < 5; j++){
   printf("%d raised to %d is %d\n", i, j, x_to_int_n(i,j));
  }
 }
}
