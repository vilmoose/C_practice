#include <stdlib.h>
#include <stdio.h>

#define LINEFEED printf("\n");
#define MAX 5;

int **input_matrix(int rows, int columns);
void print_matrix(int **a, int rows, int columns);
int **add_matrix(int **a, int  **b, int rows, int columns);
int **multiply_matrix(int **a, int **b, int rows, int columns);
void free_matrix(int **a, int rows, int columns);

void main(){
 int rows = MAX; int columns = MAX;
 
 int **matrix1 = input_matrix(rows, columns);
 print_matrix(matrix1, rows, columns);
 
 int **matrix2 = input_matrix(rows, columns);
 print_matrix(matrix2, rows, columns);
 
 int **matrix3 = add_matrix(matrix1, matrix2, rows, columns);
 print_matrix(matrix3, rows, columns);
 
 int **matrix4 = multiply_matrix(matrix1, matrix3, rows, columns);
 print_matrix(matrix4, rows, columns);
 
 free_matrix(matrix1, rows, columns);
 free_matrix(matrix2, rows, columns);
 free_matrix(matrix3, rows, columns);
 free_matrix(matrix4, rows, columns);
 
}

int **input_matrix(int rows, int columns){
 //printf("Enter # of rows: ");
 //scanf("%d", &rows);

 //printf("Enter # of columns: ");
 //scanf("%d", &columns); 
 

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
 LINEFEED;
}

int **add_matrix(int **a, int  **b, int rows, int columns){
 int **matrix = malloc (rows * sizeof(int*));
 for(int i = 0; i < rows; i++){
  matrix[i] = malloc (columns * sizeof(int*));
 }
 
 for(int i = 0; i < rows; i++){
  for(int j = 0; j < columns; j++){
   matrix[i][j] = a[i][j] + b[i][j];
  }
 }
 return matrix;
}

int **multiply_matrix(int **a, int **b, int rows, int columns){
 int **matrix = malloc (rows * sizeof(int*));
 for(int i = 0; i < rows; i++){
  matrix[i] = malloc (columns * sizeof(int*));
 }
 
 for(int i = 0; i < rows ; i++){
  for(int j = 0; j < columns ; j++){
   matrix[i][j] = 0;
   for(int k = 0; k < rows ; k++){
    matrix[i][j] += a[i][k] * b[k][j];
   }
  }
 }
 return matrix;
}

void free_matrix(int **a, int rows, int columns){
 for(int i = 0; i < rows; i++){
  free(a[i]);
 }
 free(a);
}
