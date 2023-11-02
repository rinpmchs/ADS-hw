/*
Фирма OISAC выпустила новую версию калькулятора.
Этот калькулятор берет с пользователя деньги за совершаемые арифметические операции.
Стоимость каждой операции в евро равна 5 процентов от числа, которое является результатом операции.
На этом калькуляторе требуется вычислить сумму N натуральных чисел (числа известны).
Нетрудно заметить, что от того, в каком порядке мы будем складывать эти числа, иногда зависит,
в какую сумму денег нам обойдется вычисление суммы чисел
(тем самым оказывается нарушен классический принцип “от перестановки мест слагаемых сумма не меняется”).
Например, пусть нам нужно сложить числа 10, 11, 12 и 13.
Тогда если мы сначала сложим 10 и 11 (это обойдется нам в 1.05 €), потом результат с 12 (1.65 €),
и затем с 13 (2.3 €), то всего мы заплатим 5 €, если же сначала отдельно сложить 10 и 11 (1.05 €),
потом 12 и 13 (1.25 €) и, наконец, сложить между собой два полученных числа (2.3 €),
то в итоге мы заплатим лишь 4.6 €. Напишите программу, которая будет определять,
за какую минимальную сумму денег можно найти сумму данных N чисел.

Формат ввода
Первая строка входных данных содержит число N (2 ≤ N ≤ 105).
Во второй строке заданы N натуральных чисел, каждое из которых не превосходит 10000.

Формат вывода
Определите, сколько денег нам потребуется на нахождения суммы этих N чисел.
Результат должен быть выведен с двумя знаками после десятичной точки.
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


double count_price(std::vector<int>& v)
{
    double price = 0.0;
    while (v.size() > 1)
    {
        int a = v[0];
        int b = v[1];
        price += (a + b) * 0.05;

        v.erase(v.begin(), v.begin() + 2);
        int idx = std::lower_bound(v.begin(), v.end(), a + b) - v.begin();
        v.insert(v.begin() + idx, a + b);
    }
    return price;
}


int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v(n);

    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    mergesort(v, 0, v.size() - 1);

    double price = count_price(v);
    std::cout.precision(2);
    std::cout << std::fixed << price << std::endl;
    return 0;
}
