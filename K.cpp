/*
Отсортируйте данный массив, используя пирамидальную сортировку.

Формат ввода
Первая строка входных данных содержит количество элементов в массиве N, N ≤ 105.
Далее идет N целых чисел, не превосходящих по абсолютной величине 109.

Формат вывода
Выведите эти числа в порядке неубывания.
*/

#include <iostream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[max]) max = left;
    if (right < n && arr[right] > arr[max]) max = right;
    if (max != i)
    {
        std::swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}


void heapSort(std::vector<int>& arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    heapSort(arr);
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    return 0;
}
