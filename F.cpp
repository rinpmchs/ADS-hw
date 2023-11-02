/*
Реализуйте алгоритм сортировки подсчетом для произвольных чисел, по модулю не превосходящих 10000.

Формат ввода
На вход программе сначала подается значение n ⩽ 100000 – количество элементов в массиве.
В следующей строке входных данных расположены сами элементы массива – целые числа, по модулю не превосходящие 10000

Выведите отсортированный по неубыванию массив.
*/

#include <iostream>
#include <vector>

std::vector<int> countsort(std::vector<int>& v, int k)
{
    std::vector<int> freq(2 * k + 1, 0);
    for (int i = 0; i < v.size(); i++)
        freq[v[i] + k]++;
    v.clear();
    for (int i = 0; i < freq.size(); i++)
    {
        for (int j = 0; j < freq[i]; j++)
            v.push_back(i - k);
    }
    return v;
}


int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v(n);

    for (int i = 0; i < n; i++) std::cin >> v[i];
    std::vector<int> v2 = countsort(v, 10000);
    for (int i = 0; i < n; i++) std::cout << v2[i] << " ";

    return 0;
}
