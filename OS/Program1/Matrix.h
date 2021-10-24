#ifndef MATRIX_H
#define MATRIX_H

#include "MMHeader.h"

typedef struct __matrix
{
	int num_rows;
	int num_cols;
	double* elements;
} matrix;

matrix* matrix_malloc(int num_rows, int num_cols);  
void matrix_free(matrix* mat);
void set_element(matrix* mat, int row, int col, double val);
double get_element(matrix* mat, int row, int col);
matrix* multiply(matrix* left, matrix* right);
void display(matrix* mat);

//TO DO: Implement the functions above with exception to multiply which is already given

//left cols has to be the same as right rows for matrix multiplication
matrix* multiply(matrix* left, matrix* right)
{
	int left_rows = left->num_rows;
	int left_cols = left->num_cols;
	int right_rows = right->num_rows;
	int right_cols = right->num_cols;
	matrix* result = matrix_malloc(left_rows, right_cols);
	
	for (int i = 1; i <= left_rows; i++)
	{
		for (int j = 1; j <= right_cols; j++)
		{
			double val = 0;
			for (int k = 1; k <= left_cols; k++)
			{
				double element_left = get_element(left, i, k);
				double element_right = get_element(right, k, j);
				double mul = element_left * element_right;
				val += mul;
			}
			set_element(result, i, j, val);
		}
	}
	
	return result;
}

//requires two mallocs -- malloc space for the struct, then malloc space for the array, 
//store the returned address for the array in the struct
matrix* matrix_malloc(int num_rows, int num_cols){
	//struct
	matrix* m = (matrix*)mem_manager_malloc(sizeof(matrix));
	m->num_rows = num_rows;
	m->num_cols = num_cols;
	//elements
	m->elements = (double*)mem_manager_malloc(num_cols * num_rows * sizeof(double));
	return m;
}  

//requires two frees
void matrix_free(matrix* mat){
	mem_manager_free(mat);
	mem_manager_free(mat->elements);

}

void set_element(matrix* mat, int row, int col, double val){
	int numColumns = mat->num_cols;
	//to convert from (row, col) to index (i)
	int i = (row-1) * numColumns + col - 1;
	mat->elements[i] = val;
}

double get_element(matrix* mat, int row, int col){
    int numColumns = mat->num_cols;
	int i = (row-1) * numColumns + col - 1;
	return mat->elements[i];
}

void display(matrix* mat){
    int numColumns = mat->num_cols;
	int numRows = mat->num_rows;

	for(int i = 1; i <= numRows; i++){
		for(int j = 1; j <= numColumns; j++){
			numColumns = mat->num_cols;
			int index = (i-1) * numColumns + (j-1);
			printf(" %f ", mat->elements[index]);
		}
	}
	printf("\n");	
}

#endif