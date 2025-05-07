#include <stdlib.h>
#include <stdio.h>

#define LINEFEED printf("\n");
#define MAX 5;

int input_matrix(int rows, int columns);
void print_matrix(int **a, int rows, int columns);
int add_matrix(int **a, int  **b, int rows, int columns);
int multiply_matrix(int **a, int **b, int rows, int columns);
void free_matrix(int **a, int rows, int columns);

void main(){
 int rows = MAX; int columns = MAX;
 int **arr = input_matrix(rows, columns);
 print_matrix(arr, rows, columns);
}

int input_matrix(int rows, int columns){
 printf("Enter # of rows: ");
 scanf("%d ", &rows);
 LINEFEED;
 printf("Enter # of columns: ");
 scanf("%d ", &columns); 
 LINEFEED;
 
 int **matrix = malloc (rows * sizeof(int*));
 for (int i = 0; i < rows; i++){
  matrix[i] = malloc ( columns * sizeof(int*));
 }
 
 printf("Enter %d elements: \n", rows * columns);
 for(int i = 0; i < rows; i++){
  for(int j = 0; j < columns; j++){
   printf("Element [%d][%d]", i, j);
   scanf("%d", &matrix[i][j]);
  }
 }
 LINEFEED;
 return matrix;
}

void print_matrix(int **a, int rows, int columns){
 printf("Matrix: \n");
 for(int i = 0; i < rows; i++){
  for(int j =  0; j < columns; j++){
   printf("%d ", a[i][j]);
  }
  LINEFEED;
 }
}

void free_matrix(int **a, int rows, int columns){
 for(int i = 0; i < rows; i++){
  free(a[i]);
 }
 free(a);
}
