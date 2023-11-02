/*
Дан список целых чисел.
Выведите все элементы этого списка в порядке невозрастания значений. Выведите новый список на экран.

Решите эту задачу при помощи алгоритма сортировки выбором. Решение оформите в виде функции SelectionSort(A).

В алгоритме сортировки выбором мы находим наибольший элемент в списке и ставим его на первое место,
затем находим наибольший элемент из оставшихся и ставим его на второе место и т.д.
*/

#include <iostream>
#include <vector>
#include <sstream>

void selectionsort(std::vector<int>& A)
{
    int n = A.size();
    for (int i = 0; i < n - 1; i++)
    {
        int max_i = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] > A[max_i])
                max_i = j;
        }
        if (max_i > i) std::swap(A[i], A[max_i]);
    }
}

void selectionSort(int A[])
{
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < n-1; i++)
    {
        int max_i = i;
        for (int j = i+1; j < n; j++)
        {
            if (A[j] > A[max_i])
                max_i = j;
        }
        int tmp = A[max_i];
        A[max_i] = A[i];
        A[i] = tmp;
    }
}


int main()
{
    std::string str;
    std::vector<int> A;
    std::getline(std::cin, str);
    std::istringstream iss(str);
    int el;
    while (iss >> el)
    {
        A.push_back(el);
    }
    selectionsort(A);
    for (int i = 0; i < 5; i++) std::cout << A[i] << " ";

    return 0;
}