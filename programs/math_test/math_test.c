#include <stdio.h>

#define MAT_ROWS 4
#define MAT_COLS 4

static char padding[] = "0000";

void imat_add(int* matrix1, int* matrix2, int* matrix_res, unsigned int rows, unsigned int cols)
{
	for (unsigned int i = 0; i < rows * cols; i++)
	{
		matrix_res[i] = matrix1[i] + matrix2[i];
	}
}
/*
void imat_mul()
{
	
}*/

void igen_mat(int* matrix, unsigned int rows, unsigned int cols)
{
	for (unsigned int i = 0; i < rows * cols; i++)
	{
		matrix[i] = i;
	}
}

void print_mat(int* matrix, unsigned int rows, unsigned int cols)
{
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			printf("%d ", 0, matrix[cols * i + j]);
		}
		printf("\n\r", 0);
	}
}

int main()
{
	int matrix[MAT_ROWS * MAT_COLS];
	
	igen_mat(matrix, MAT_ROWS, MAT_COLS);
	print_mat(matrix, MAT_ROWS, MAT_COLS);
	
	padding[1]++;
	
	while (1);
}