#include <stdio.h>
#include <serial.h>
#include <string.h>
#include <imatrix_ops.h>
#include <gpio.h>
#include <cpu.h>

#define MAT_ROWS 48
#define MAT_COLS 48
#define SEPARATOR 's'

static char padding[] = "0000";

int uart_load_int()
{
	char buf[12];
	char loaded;
	
	buf[11] = '\0';
	unsigned int curr = 0;
	do
	{
		while(!read_byte(&loaded));
		
		if (loaded == SEPARATOR)
		{
			buf[curr] = '\0';
		}
		else
			buf[curr++] = loaded;

	} while (loaded != SEPARATOR && curr < 11);
	
	return atoi(buf);
}

void uart_load_matrix(int* matrix, unsigned int rows, unsigned int cols)
{
	unsigned int progress_bar = 1;
	gpio_write(0);
	for (unsigned int i = 0; i < rows * cols; i++)
	{ 
		matrix[i] = uart_load_int();
		//printf("Loaded %d / %d\r\n", 0, i + 1, rows * cols);
		
		if (i % ((rows * cols) / 16) == 0)
		{
			gpio_write(progress_bar);
			progress_bar = (progress_bar << 1) + 1;
		}
	}
	gpio_write(0);
}

void print_mat(int* matrix, unsigned int rows, unsigned int cols)
{
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			printf("%d ", 0, matrix[cols * i + j]);
		}
		printf("\r\n", 0);
	}
}

int main()
{
	unsigned int cycles = 0;
	unsigned int instret = 0;
	
	CSRR_READ(cycles, 0xC00);
	CSRR_READ(instret, 0xC02);
	
	printf("Cycles: %d | Instret: %d\r\n", 0, cycles, instret);
	
	int matA[MAT_ROWS * MAT_COLS];
	int matB[MAT_ROWS * MAT_COLS];
	int matC[MAT_ROWS * MAT_COLS];
	
	printf("Loading Matrix A...\r\n", 0);
	uart_load_matrix(matA, MAT_ROWS, MAT_COLS);
	//igen_mat(matA, MAT_ROWS, MAT_COLS);
	printf("Matrix A loaded!\r\n", 0);
	
	printf("Loading Matrix B...\r\n", 0);
	//igen_mat(matB, MAT_ROWS, MAT_COLS);
	uart_load_matrix(matB, MAT_ROWS, MAT_COLS);
	printf("Matrix B loaded!\r\n\r\n", 0);
	
	printf("---------- Matrix A ----------\r\n", 0);
	print_mat(matA, MAT_ROWS, MAT_COLS);
	printf("------------------------------\r\n\r\n", 0);
	printf("---------- Matrix B ----------\r\n", 0);
	print_mat(matB, MAT_ROWS, MAT_COLS);
	printf("------------------------------\r\n\r\n", 0);
	
	imat_add(matA, matB, matC, MAT_ROWS, MAT_COLS);
	printf("---------- Matrix A+B ----------\r\n", 0);
	print_mat(matC, MAT_ROWS, MAT_COLS);
	printf("--------------------------------\r\n\r\n", 0);
	
	init_mat(matC, MAT_ROWS, MAT_COLS, 0);
	imat_mul(matA, matB, matC, MAT_ROWS, MAT_COLS, MAT_ROWS, MAT_COLS);
	printf("---------- Matrix A*B ----------\r\n", 0);
	print_mat(matC, MAT_ROWS, MAT_COLS);
	printf("--------------------------------\r\n\r\n", 0);
	
	CSRR_READ(cycles, 0xC00);
	CSRR_READ(instret, 0xC02);
	
	printf("Cycles: %d | Instret: %d\r\n", 0, cycles, instret);
	
	padding[1]++;
	
	while (1);
}
