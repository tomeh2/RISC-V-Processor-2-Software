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

void init_mat(int* matrix, unsigned int rows, unsigned int cols, int init_val)
{
	for (unsigned int i = 0; i < rows * cols; i++)
	{
		matrix[i] = init_val;
	}
}

