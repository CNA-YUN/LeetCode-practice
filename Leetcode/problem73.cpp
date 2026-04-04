#include <malloc.h>
#include <memory>
void setZeroes_voilent(int** matrix, int matrixSize, int* matrixColSize) {
	int* hash_row = (int*)malloc(sizeof(int) * matrixSize);
	//hash_row = { 0 };
	memset(hash_row, 0, matrixSize * sizeof(int));	
	int* hash_col = (int*)malloc(*matrixColSize * sizeof(int));
	//hash_col = { 0 };
	memset(hash_col, 0, *matrixColSize * sizeof(int));
	for (int row = 0;row < matrixSize;row++) {
		for (int col = 0;col < *matrixColSize;col++) {
			if (matrix[row][col] == 0) {
				hash_row[row] += 1;
				hash_col[col] += 1;
			}
		}
	}
	for (int row = 0;row< matrixSize;row++) {
		if (hash_row[row] != 0) {
			for (int col = 0;col < *matrixColSize;col++) {
				matrix[row][col] = 0;
			}
		}
	}
	for (int col = 0;col < *matrixColSize;col++) {
		if (hash_col[col] != 0) {
			for (int row = 0;row < matrixSize;row++) {
				matrix[row][col] = 0;
			}
		}
	}
}
//void problem73() {
//	int matrix[][3] = {{1, 1, 1} ,{1, 0, 1},{1, 1, 1}};
//	int* p = *matrix;
//	int matrixSize = sizeof(matrix) / sizeof(int);
//	int* matrixColsize = 0;
//	//setZeroes_voilent(matrix, matrixSize, matrixColsize);
//}