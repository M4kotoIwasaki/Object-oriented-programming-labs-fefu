#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>

constexpr int rows = 6;
constexpr int cols = 5;

int IntRandomGenerator() 
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(10, 99);

    return dist(mt);
}


int main()
{    
    setlocale(LC_ALL, "");

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new int[cols];


    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            matrix[i][j] = IntRandomGenerator();
    }


    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "\n\n";

    int maxElemntRow {};
    int maxElement { 0 };
    int maxElementInRow {};

    for (int i = 0; i < rows; ++i)
    {
        maxElementInRow = *std::max_element(matrix[i], matrix[i] + cols);
        if (maxElementInRow > maxElement)
        {
            maxElement = maxElementInRow;
            maxElemntRow = i;
        }
    }
    std::cout << "Строка с макс. эл-том: " << maxElemntRow + 1 << "\n";

    int minElemntRow {};
    int minElement { 100 };
    int minElementInRow {};

    for (int i = 0; i < rows; ++i)
    {
        minElementInRow = *std::max_element(matrix[i], matrix[i] + cols);
        if (minElementInRow < minElement)
        {
            minElement = minElementInRow;
            minElemntRow = i;
        }
    }
    std::cout << "Строка с мин. эл-том: " << minElemntRow + 1 << "\n";
    std::cout << "\n\n";

    if (maxElemntRow != maxElemntRow)
    {
        std::swap(matrix[maxElemntRow], matrix[maxElemntRow]);
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }

    for (int i = 0; i < cols; ++i)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}


//14. В матрице размером NxM поменять местами строку, 
// содержащую элемент с наибольшим значением, со строкой, содержащей элемент с наименьшим значением.