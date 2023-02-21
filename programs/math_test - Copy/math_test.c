#include <stdio.h>

#define MAT_ROWS 16
#define MAT_COLS 16

static char padding[] = "0000";

void imat_add(int* matrix1, int* matrix2, int* matrix_res, unsigned int rows, unsigned int cols)
{
	for (unsigned int i = 0; i < rows * cols; i++)
	{
		matrix_res[i] = matrix1[i] + matrix2[i];
	}
}

void imat_mul(int* matrix1, int* matrix2, int* matrix_res, 
			  unsigned int matrix1_rows, unsigned int matrix1_cols, 
			  unsigned int matrix2_rows, unsigned int matrix2_cols)
{
	for (unsigned int i = 0; i < matrix1_rows; i++)
	{
		for (unsigned int j = 0; j < matrix1_cols; j++)
		{
			for (unsigned int k = 0; k < matrix1_cols; k++)
			{
				matrix_res[i * matrix1_cols + j] += matrix1[i * matrix1_cols + k] * matrix2[k * matrix2_cols + j];
			}
		}
	}
}

void igen_mat(int* matrix, unsigned int rows, unsigned int cols)
{
	for (unsigned int i = 0; i < rows * cols; i++)
	{
		matrix[i] = i;
	}
}

void init_mat(int* matrix, unsigned int rows, unsigned int cols)
{
	for (unsigned int i = 0; i < rows * cols; i++)
	{
		matrix[i] = 0;
	}
}

void print_mat(int* matrix, unsigned int rows, unsigned int cols)
{
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			printf("%d ", matrix[cols * i + j]);
		}
		printf("\n\r");
	}
}

int main()
{
	int matA[MAT_ROWS * MAT_COLS];
	int matB[MAT_ROWS * MAT_COLS];
	int matC[MAT_ROWS * MAT_COLS];
	int matD[MAT_ROWS * MAT_COLS];
	
	init_mat(matC, MAT_ROWS, MAT_COLS);
	init_mat(matD, MAT_ROWS, MAT_COLS);
	
	igen_mat(matA, MAT_ROWS, MAT_COLS);
	igen_mat(matB, MAT_ROWS, MAT_COLS);
	imat_add(matA, matB, matC, MAT_ROWS, MAT_COLS);
	imat_mul(matA, matB, matD, MAT_ROWS, MAT_COLS, MAT_ROWS, MAT_COLS);
	
	printf("----- Matrix A -----\n\r");
	print_mat(matA, MAT_ROWS, MAT_COLS);
	printf("----- Matrix B -----\n\r");
	print_mat(matB, MAT_ROWS, MAT_COLS);
	printf("----- Matrix C -----\n\r");
	print_mat(matC, MAT_ROWS, MAT_COLS);
	printf("----- Matrix D -----\n\r");
	print_mat(matD, MAT_ROWS, MAT_COLS);
	
	
	padding[1]++;
	
	while (1);
}