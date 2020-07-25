#include "CompactMatrix.h"

CompactMatrix::CompactMatrix()
{
	pr_rows = 0;
	pr_matrix = nullptr;
}

CompactMatrix::CompactMatrix(int** Matrix, int Row, int Col)
{
	int no_of_elements = 0;
	int no_of_col = 0;

	pr_rows = Row;
	pr_matrix = new int* [Row];

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Matrix[i][j] != 0)
			{
				no_of_elements++;
			}
		}


		if (no_of_elements == 0)
		{
			no_of_col = no_of_elements + 1;
		}
		else
		{
			no_of_col = no_of_elements + no_of_elements + 1;
		}

		pr_matrix[i] = new int[no_of_col];
		pr_matrix[i][0] = no_of_elements;
		no_of_elements = 0;
		no_of_col = 0;
	}

	int x = 1;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Matrix[i][j] != 0)
			{
				pr_matrix[i][x] = j;
				x++;
				pr_matrix[i][x] = Matrix[i][j];
				x++;
			}
		}

		x = 1;
	}
}

CompactMatrix::~CompactMatrix()
{
	for (int i = 0; i < pr_rows; i++)
	{
		delete[]pr_matrix[i];
	}

	delete[]pr_matrix;

	pr_matrix = nullptr;
	pr_rows = 0;
}

ostream& operator<<(ostream& out, const CompactMatrix& obj_in)
{
	int col = 0;
	for (int i = 0; i < obj_in.pr_rows; i++)
	{
		col = obj_in.pr_matrix[i][0];

		if (col == 0)
		{
			col = col + 1;
		}
		else
		{
			col = col + col + 1;
		}

		cout << "	";
		for (int j = 0; j < col; j++)
		{
			cout << obj_in.pr_matrix[i][j] << " ";
		}
		cout << endl;

		col = 0;
	}

	return out;
}
