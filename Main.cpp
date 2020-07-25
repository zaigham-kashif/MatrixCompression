#include<iostream>
#include"CompactMatrix.h"

using namespace std;

void main() {
	const int rows = 3, cols = 7;
	int m1[rows][cols] = { {3,0,0,1,0,0,0},{0,0,9,0,0,0,0},{7,12,9,0,8,2,8} };
	int m2[rows][cols] = { {0,0,0,1,2,0,8},{ 0,0,0,0,0,0,0},{ 7,0,3,0,2,0,0} };
	int* matrix1[rows]; int* matrix2[rows]; //array of pointers same as int**
	for (int i = 0; i < rows; i++) {
		matrix1[i] = m1[i];
		matrix2[i] = m2[i];
	}
	CompactMatrix compactMatrix1(matrix1, rows, cols);
	CompactMatrix compactMatrix2(matrix2, rows, cols);

	cout << "	Compact Matrix one is : " << endl;
	cout << compactMatrix1 << endl;

	cout << "	Compact Matrix two is : " << endl;
	cout << compactMatrix2 << endl;
}