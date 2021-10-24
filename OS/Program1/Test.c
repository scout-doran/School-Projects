#include "Matrix.h"
#include "MMHeader.h"

matrix* read_file(char* file_name);

int main(int argc, char** argv)
{
	init_mem(4096);	//4K
	
	char* mat_1_file_name = "mat_1.txt";
	matrix* mat_1 = read_file(mat_1_file_name);
	display(mat_1);
	traverse_free_list();

	char* mat_2_file_name = "mat_2.txt";
	matrix* mat_2 = read_file(mat_2_file_name);
	display(mat_2);
	traverse_free_list();

	matrix* result = multiply(mat_1, mat_2);
	display(result);
	traverse_free_list();
	matrix_free(result);
	traverse_free_list();
	matrix_free(mat_1);
	traverse_free_list();
	matrix_free(mat_2);
	traverse_free_list();


	/*
	//Void* = its a pointer but we haven't speciied what it points to
	//ptr skips over header that is why it is 010 instead of 000
	void* ptr = mem_manager_malloc(20);

	*((int*)ptr) = 11;
	printf("%p\n", ptr);

	void* temp = ptr + 1; 
	//Note: 4 is added instead of 1 when int*, make void* and take off parenthesis on ptr if you only want to add 1. 
	printf("%p\n", temp);
	//use void* when doing pointer arithmetic

	//dangerous operation
	//%d  = used to print signed integers
	printf("%d\n", *((int*)ptr));
	mem_manager_free(ptr);
	printf("%d\n", *((int*)ptr));

	void* ptr1 = mem_manager_malloc(100);
	//%p used to print pointer addresses
	printf("%p\n", ptr1);
	void* ptr2 = mem_manager_malloc(100);
	printf("%p\n", ptr2);
	void* ptr3 = mem_manager_malloc(100);
	printf("%p\n", ptr3);
	mem_manager_free(ptr2);

	traverse_free_list();
	*/

	/*Notes:
	 *	void* ptr = "It is a pointer to something but I have not specified what it points to"
	 *  		 	"If I want it to be a pointer to an integer, you can cast it and follow that
	 * 				 with a dereference and setting it equal to 11"
	 * 			 		"i.e. *((int*)ptr)"
	 **/

	return 0;
}

matrix* read_file(char* file_name)
{
	matrix* mat = 0;
	
	int num_rows = 0;
	int num_cols = 0;
	
	FILE* f_matrix = fopen(file_name, "r");
	fscanf(f_matrix, "%d", &num_rows);
	fscanf(f_matrix, "%d", &num_cols);
	mat = matrix_malloc(num_rows, num_cols);
	
	int num_elements = num_rows*num_cols;
	for (int i = 1; i <= num_elements; i++)
	{
		double* elements = mat->elements;
		double element = 0;
		fscanf(f_matrix, "%lf", &element);
		elements[i-1] = element;
		//printf("%.2lf", element);
	}
		
	fclose(f_matrix);
	return mat;
}
           