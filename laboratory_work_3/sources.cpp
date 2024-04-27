#include "sources.hpp"

void laba_part_1_static()
{
    srand(time(0));
    int n, array[100], sum = 0;
    std::cout << "Enter the size of the array:";
    std::cin >> n;
    std::cout << "Array: ";
    for (size_t i = 0; i < n; i++)
    {
        array[i] = rand() % 10;
        sum += array[i];
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl
        << "The sum of the array elements:" << sum << std::endl;
}

void laba_part_1_dynamic()
{
    srand(time(0));
    int n, sum = 0;
    std::cout << "Enter the size of the array:";
    std::cin >> n;
    int* array = new int[n];
    std::cout << "array: ";
    for (size_t i = 0; i < n; i++)
    {
        array[i] = rand() % 10;
        sum += array[i];
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl
        << "The sum of the array elements:" << sum << std::endl;
    delete[] array;
}

void laba_part_2_dynamic()
{
    srand(time(0));
    int n, m;
    std::cout << "Enter the dimension of the matrix (n x m):";
    std::cin >> n >> m;
    int** matrix = new int* [m];
    int* vector = new int[m];
    int* result_vector = new int[n];
    std::cout << "matrix:" << std::endl;
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
        for (size_t j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 10;
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    std::cout << "vector: ";
    for (size_t i = 0; i < m; i++)
    {
        vector[i] = rand() % 10;
        std::cout << vector[i] << ' ';
    }
    std::cout << std::endl;

    for (size_t i = 0; i < n; i++)
    {
        result_vector[i] = 0;
        for (size_t j = 0; j < m; j++)
        {
            result_vector[i] += matrix[i][j] * vector[j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] vector;

    std::cout << "The result of multiplying a matrix by a vector is a vector: ";
    for (size_t i = 0; i < n; i++)
    {
        std::cout << result_vector[i] << ' ';
    }
    std::cout << std::endl;
    delete[] result_vector;
}

void laba_part_2_vector()
{
    srand(time(0));
    int n, m;
    std::cout << "Enter the dimension of the matrix (n x m):";
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    std::vector<int> vector(m);
    std::vector<int> result_vector(n);
    std::cout << "matrix:" << std::endl;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 10;
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    std::cout << "vector: ";
    for (size_t i = 0; i < m; i++)
    {
        vector[i] = rand() % 10;
        std::cout << vector[i] << ' ';
    }
    std::cout << std::endl;

    for (size_t i = 0; i < n; i++)
    {
        result_vector[i] = 0;
        for (size_t j = 0; j < m; j++)
        {
            result_vector[i] += matrix[i][j] * vector[j];
        }
    }

    std::cout << "The result of multiplying a matrix by a vector is a vector: ";
    for (size_t i = 0; i < n; i++)
    {
        std::cout << result_vector[i] << ' ';
    }
    std::cout << std::endl;
}