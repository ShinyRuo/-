#include "Matrix.h"

inline int ** createMatrix(int n)
{
	int** arr = new int*[n];
	for (int i = 0; i < n; ++i) arr[i] = new int[n];
	return arr;
}

int ** initializationMatrix(int n)
{
	int** arr = createMatrix(n);
	int j;
	for (int i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			arr[i][j] = 1 + rand() % 10;//随机填入一个1~10的数
	return arr;
}



void deleteMatrix(int ** a, int n)
{
	for (int i = 0; i < n; ++i)
		delete[] a[i];
	delete[] a;
}

int ** ADD(int ** MatrixA, int ** MatrixB, int n)
{
	int j,**result = createMatrix(n);
	for (int i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			result[i][j] = MatrixA[i][j] + MatrixB[i][j];
	return result;
}

int ** MergeMatrix(int ** a, int ** b, int ** c, int ** d, int n)
{
	int j, ** result = createMatrix(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		for (j = 0; j < 2 * n; j++) {
			if (i < n) {
				if (j < n) {
					result[i][j] = a[i][j];
				}
				else
					result[i][j] = b[i][j - n];
			}
			else {
				if (j < n) {
					result[i][j] = c[i - n][j];
				}
				else {
					result[i][j] = d[i - n][j - n];
				}
			}
		}
	}
	return result;
}

int ** BruteForce(int ** a, int ** b,int MatrixSize)
{
	int** result = createMatrix(MatrixSize);
	int j, k;
	for (int i = 0; i<MatrixSize; ++i)
	{
		for ( j = 0; j<MatrixSize; ++j)
		{
		    result[i][j] = 0;
			for ( k = 0; k<MatrixSize; ++k)
			{
				result[i][j] = result[i][j] + a[i][k] * b[k][j];
			}
		}
	}
	return result;
}



void printMatrix(int** a,int MatrixSize)
{
	int j;
	for(int i=0;i<MatrixSize;++i)
	{
		cout << endl;
		for (j = 0; j < MatrixSize; ++j)
			cout << a[i][j] << " ";
	}
	cout << endl;
		
}

int** DivideAndConquer(int ** MatrixA, int ** MatrixB,  int MatrixSize)
{
	int** result = createMatrix(MatrixSize);
	if (MatrixSize == 2)
	{
		result=BruteForce(MatrixA, MatrixB,  MatrixSize);
	}
	else
	{
		int halfSize = MatrixSize / 2;

		int** A11 = QuarterMatrix(MatrixA, MatrixSize, 1);
		int** A12 = QuarterMatrix(MatrixA, MatrixSize, 2);
		int** A21 = QuarterMatrix(MatrixA, MatrixSize, 3);
		int** A22 = QuarterMatrix(MatrixA, MatrixSize, 4);

		int** B11 = QuarterMatrix(MatrixB, MatrixSize, 1);
		int** B12 = QuarterMatrix(MatrixB, MatrixSize, 2);
		int** B21 = QuarterMatrix(MatrixB, MatrixSize, 3);
		int** B22 = QuarterMatrix(MatrixB, MatrixSize, 4);

		int** C11 = QuarterMatrix(result, MatrixSize, 1);
		int** C12 = QuarterMatrix(result, MatrixSize, 2);
		int** C21 = QuarterMatrix(result, MatrixSize, 3);
		int** C22 = QuarterMatrix(result, MatrixSize, 4);

		C11 = ADD(DivideAndConquer(A11, B11, halfSize), DivideAndConquer(A12, B21, halfSize), halfSize);
		C12 = ADD(DivideAndConquer(A11, B12, halfSize), DivideAndConquer(A12, B22, halfSize), halfSize);
		C21 = ADD(DivideAndConquer(A21, B11, halfSize), DivideAndConquer(A22, B21, halfSize), halfSize);
		C22 = ADD(DivideAndConquer(A21, B12, halfSize), DivideAndConquer(A22, B22, halfSize), halfSize);

		result = MergeMatrix(C11, C12, C21, C22, halfSize);

		deleteMatrix(A11, halfSize);
		deleteMatrix(A12, halfSize);
		deleteMatrix(A21, halfSize);
		deleteMatrix(A22, halfSize);
		deleteMatrix(B11, halfSize);
		deleteMatrix(B12, halfSize);
		deleteMatrix(B21, halfSize);
		deleteMatrix(B22, halfSize);
		deleteMatrix(C11, halfSize);
		deleteMatrix(C12, halfSize);
		deleteMatrix(C21, halfSize);
		deleteMatrix(C22, halfSize);

	}
	return result;
}

int** QuarterMatrix(int ** MatrixBy, int MatrixSize, int part)
{
	int halfSize = MatrixSize / 2;
	int** result = createMatrix(halfSize);
	switch (part)
	{
	case 1:
	{
		for (int i = 0; i<halfSize; i++) {
			for (int j = 0; j<halfSize; j++) {
				result[i][j] = MatrixBy[i][j];
			}
		}
		break;
	}

	case 2:
	{
		for (int i = 0; i<halfSize; i++) {
			for (int j = 0; j<MatrixSize - halfSize; j++) {
				result[i][j] = MatrixBy[i][j + halfSize];
			}
		}
		break;
	}

	case 3:
	{
		for (int i = 0; i<MatrixSize - halfSize; i++) {
			for (int j = 0; j<halfSize; j++) {
				result[i][j] = MatrixBy[i + halfSize][j];
			}
		}
		break;
	}
	
	case 4:
	{
		for (int i = 0; i<MatrixSize - halfSize; i++) {
			for (int j = 0; j<MatrixSize - halfSize; j++) {
				result[i][j] = MatrixBy[i + halfSize][j + halfSize];
			}
		}
		break;
	}

	default:
		break;

	}
	return result;
}
