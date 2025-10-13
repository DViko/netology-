#include <iostream>

int** create_two_dim_array(int, int);
void fill_two_dim_array(int**, int, int);
void print_two_dim_array(int**, int, int);
void delete_two_dim_array(int**, int);

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");

	int rows{}, columns{};

	std::cout << "Введите количество строк: ";
	std::cin >> rows;
	std::cout << "Введите количество столбцов: ";
	std::cin >> columns;
	std::cout << "Таблица умножения: " << std::endl;

	int** arr = create_two_dim_array(rows, columns);
	fill_two_dim_array(arr, rows, columns);
	print_two_dim_array(arr, rows, columns);
	delete_two_dim_array(arr, rows);

    std::cout << arr << "\n";

	return EXIT_SUCCESS;
}

int** create_two_dim_array(int rows, int columns)
{
	int** array = new int* [rows];
	for (int r = 0; r < rows; r++)
	{
		array[r] = new int[columns]();
	}
	return array;
}

void fill_two_dim_array(int** array, int rows, int columns)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			array[r][c] = (c + 1) * (r + 1);
		}
	}
}

void print_two_dim_array(int** array, int rows, int columns)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			std::cout << array[r][c] << "\t";
		}
		std::cout << std::endl;
	}
}

void delete_two_dim_array(int** array, int rows)
{
	for (int r = 0; r < rows; r++)
	{
		delete[] array[r];
	}
	delete[] array;
}