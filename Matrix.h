#pragma once
#include <iostream>
using namespace std;


int** initializationMatrix(int n);
void deleteMatrix(int **a, int n);
int** ADD(int** MatrixA, int** MatrixB, int n);
int ** MergeMatrix(int** a, int** b, int** c, int** d, int n);
int** BruteForce(int** a, int** b,int MatrixSize);
void printMatrix(int** a,int MatrixSize);
int**  DivideAndConquer(int** a, int** b,  int MatrixSize);
int** QuarterMatrix(int** MatrixBy, int MatrixSize, int part);
