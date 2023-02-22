#pragma once

void imat_add(int* matrix1, int* matrix2, int* matrix_res, unsigned int rows, unsigned int cols);
void imat_mul(int* matrix1, int* matrix2, int* matrix_res, 
			  unsigned int matrix1_rows, unsigned int matrix1_cols, 
			  unsigned int matrix2_rows, unsigned int matrix2_cols);
void igen_mat(int* matrix, unsigned int rows, unsigned int cols);
void init_mat(int* matrix, unsigned int rows, unsigned int cols, int init_val);