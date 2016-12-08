#include <gtest/gtest.h>
#include "Header.h"

TEST(Shortest_way, throw_if_matrix_is_not_exist)
{
	int** matrix = NULL;
	EXPECT_ANY_THROW(Shortest_way(matrix, 4, 2));
}

TEST(Shortest_way, throw_if_first_parameter_is_too_small)
{
	int **matrix = new int*[3];
	for (int i = 0; i < 4; i++)
		matrix[i] = new int[2];
	ASSERT_ANY_THROW(Shortest_way(matrix, -3, 2));
}

TEST(Shortest_way, throw_if_second_parameter_is_too_small)
{
	int **matrix = new int*[3];
	for (int i = 0; i < 4; i++)
		matrix[i] = new int[2];
	ASSERT_ANY_THROW(Shortest_way(matrix, 3, -2));
}

TEST(Shortest_way, correct_search_the_shortest_way) 
{
	int str = 5, col = 5;
	int** matrix = new int*[str];
	for (int i = 0; i < str; ++i) {
		matrix[i] = new int[col];
		for (int j = 0; j < col; ++j)
			matrix[i][j] = 1;
	}
	matrix[1][1] = 0;
	matrix[2][1] = 0;
	matrix[3][1] = 0;
	matrix[4][1] = 0;
	matrix[0][3] = 0;
	matrix[1][3] = 0;
	matrix[2][3] = 0;
	matrix[3][3] = 0;

	int res = Shortest_way(matrix, str, col);
	EXPECT_EQ(16, res);
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}