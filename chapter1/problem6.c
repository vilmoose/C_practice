#include <stdlib.h>
#include <stdio.h>

void num_to_text();

void main(){
 num_to_text();
}

void num_to_text(){
 int input, num, i = 0, j, x;
 int arr[50], rev[50];
 printf("Input number to be converted to text:");
 scanf("%d", &input);
 
 num = input;
 while(num > 0){
  int last_digit = num % 10;
  //printf("%d\n", last_digit);
  rev[i] = last_digit;
  printf("digit: %d\n", rev[i]); 
  i++;
  num = num / 10;
 }
 
 j = i;

 //reverse array
 for(x = 0; x < j; x++, i--){
  arr[x] = rev[i-1];
  printf("%d\n", arr[x]);
 }
 
 printf("The number %d in text is: ", input);
 for(int k = 0; k < j; k++){
  if (arr[k]  == 0){
    printf("zero ");
  }else if (arr[k] == 1){
    printf("one ");
  }else if (arr[k] == 2){
    printf("two ");
  }else if (arr[k] == 3){
    printf("three ");
  }else if (arr[k] == 4){
    printf("four ");
  }else if (arr[k] == 5){
    printf("five ");
  }else if (arr[k] == 6){
    printf("six ");
  }else if(arr[k] == 7){
    printf("seven ");
  }else if(arr[k] == 8){
    printf("eight ");
  }else if (arr[k] == 9){
    printf("nine ");
  }
 }
 printf("\n");
 
}
