#include "Header.h"

int Shortest_way(int** matrix, int str, int col) 
{
	const int Big_number = 10000;

	if ((matrix == NULL) || (str < 1) || (col < 0)) 
		throw logic_error("Error description");

	int** tmp_mtrx = new int*[str];
	for (int i = 0; i < str; ++i) 
	{
		tmp_mtrx[i] = new int[col];
		for (int j = 0; j < col; ++j)
			tmp_mtrx[i][j] = Big_number;
	}

	int len = 0;

	queue<sCrd> q;

	sCrd Begin;
	Begin.string = 0;
	Begin.column = col - 1;
	q.push(Begin);
	tmp_mtrx[Begin.string][Begin.column] = 0;

	while (!q.empty())
	{
		sCrd Head = q.front();
		q.pop();
		if (Head.string > 0) 
		{
			if ((matrix[Head.string - 1][Head.column] == 1) &&
			(tmp_mtrx[Head.string - 1][Head.column] == Big_number)) 
			{
				tmp_mtrx[Head.string - 1][Head.column] = tmp_mtrx[Head.string][Head.column] + 1;
				sCrd* tmp = new sCrd;
				tmp->string = (Head.string - 1);
				tmp->column = (Head.column);
				q.push(*tmp);
			}
		}
		if (Head.string + 1 < str) 
		{
			if ((matrix[Head.string + 1][Head.column] == 1) &&
				(tmp_mtrx[Head.string + 1][Head.column] == Big_number)) 
			{
				tmp_mtrx[Head.string + 1][Head.column] = tmp_mtrx[Head.string][Head.column] + 1;
				sCrd* tmp = new sCrd;
				tmp->string = (Head.string + 1);
				tmp->column = (Head.column);
				q.push(*tmp);
			}
		}
		if (Head.column > 0) {
			if ((matrix[Head.string][Head.column - 1] == 1) &&
				(tmp_mtrx[Head.string][Head.column - 1] == Big_number))
			{
				tmp_mtrx[Head.string][Head.column - 1] = tmp_mtrx[Head.string][Head.column] + 1;
				sCrd* tmp = new sCrd;
				tmp->string = (Head.string);
				tmp->column = (Head.column - 1);
				q.push(*tmp);
			}
		}
		if (Head.column + 1 < col)
		{
			if ((matrix[Head.string][Head.column + 1] == 1) &&
				(tmp_mtrx[Head.string][Head.column + 1] == Big_number))
			{
				tmp_mtrx[Head.string][Head.column + 1] = tmp_mtrx[Head.string][Head.column] + 1;
				sCrd* tmp = new sCrd;
				tmp->string = (Head.string);
				tmp->column = (Head.column + 1);
				q.push(*tmp);
			}
		}
	}

	len = tmp_mtrx[str - 1][0];
	return len;
}