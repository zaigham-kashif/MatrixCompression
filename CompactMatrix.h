#pragma once
#include<iostream>

using namespace std;

class CompactMatrix
{
	private:
		int pr_rows;
		int** pr_matrix;

	public:

		CompactMatrix();
		CompactMatrix(int **Matrix,int Row,int Col);

		friend ostream& operator<< (ostream& out, const CompactMatrix& obj_in);

		~CompactMatrix();

};

