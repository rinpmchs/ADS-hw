/*
Первая строка входных данных содержит количество элементов в массиве N, N ≤ 105.
Далее идет N целых чисел, не превосходящих по абсолютной величине 109.

Выведите эти числа в порядке неубывания.
*/

#include <iostream>
#include <vector>

void merge2(std::vector<int>& v, int l, int c, int r)
{
    int n = r - l + 1;
    std::vector<int> tmp(n, 0);
    int i = l, j = c + 1;

    for (int k = 0; k < n; k++)
    {
        if (i > c)
            tmp[k] = v[j++];
        else if (j > r)
            tmp[k] = v[i++];
        else
            tmp[k] = v[i] < v[j] ? v[i++] : v[j++];
    }

    for (int i = l, k = 0; k < n; i++, k++)
        v[i] = tmp[k];
}

void mergesort(std::vector<int>& v, int l, int r)
{
    if(l >= r)
        return;
    int c = l + (r - l)/2;

    mergesort(v, l, c);
    mergesort(v, c + 1, r);

    merge2(v, l, c, r);
}


int main()
{
    int n;
    std::vector<int> v;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int el;
        std::cin >> el;
        v.push_back(el);
    }

    mergesort(v, 0, v.size() - 1);

    for (int i : v)
        std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
}