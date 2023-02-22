#include <stdio.h>
#include <imatrix_ops.h>

#define MAT_ROWS 16
#define MAT_COLS 16

static char padding[] = "00";

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
	int matA[MAT_ROWS * MAT_COLS];
	int matB[MAT_ROWS * MAT_COLS];
	int matC[MAT_ROWS * MAT_COLS];
	int matD[MAT_ROWS * MAT_COLS];
	
	igen_mat(matA, MAT_ROWS, MAT_COLS);
	igen_mat(matB, MAT_ROWS, MAT_COLS);
	imat_add(matA, matB, matC, MAT_ROWS, MAT_COLS);
	imat_mul(matA, matB, matD, MAT_ROWS, MAT_COLS, MAT_ROWS, MAT_COLS);
	
	printf("----- Matrix A -----\n\r", 0);
	print_mat(matA, MAT_ROWS, MAT_COLS);
	printf("----- Matrix B -----\n\r", 0);
	print_mat(matB, MAT_ROWS, MAT_COLS);
	printf("----- Matrix A+B -----\n\r", 0);
	print_mat(matC, MAT_ROWS, MAT_COLS);
	printf("----- Matrix A*B -----\n\r", 0);
	print_mat(matD, MAT_ROWS, MAT_COLS);
	
	
	padding[1]++;
	
	while (1);
}