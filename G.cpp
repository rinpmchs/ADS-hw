/*
Дан массив случайных целых чисел, нужно отсортировать его.
В этой задаче очень небольшой запас по времени. Если она не сдается, это нормально.
Предполагается решение через или BucketSort, RadixSort.

На первой строке количество тестов t (1≤t≤200) и число n (1 ≤ n ≤ 50000) — размер массива в каждом из тестов.
На второй строке пара целых чисел a, b от 1 до 10^9, используемая в генераторе случайных чисел.

unsigned int cur = 0; // беззнаковое 32-битное число
unsigned int nextRand24()
{
    cur = cur * a + b; // вычисляется с переполнениями
    return cur » 8; // число от 0 до 2^24−1
}
unsigned int nextRand32()
{
    unsigned int a = nextRand24(), b = nextRand24();
    return (a « 8) ^ b; // число от 0 до 2^32−1
}
Тесты генерируются последовательно. Элементы массива генерируются последовательно. xi = nextRand32();

Для каждого теста выведите на отдельной строке ∑ni = 1xi * i
*/

#include <iostream>
#include <vector>


void counting_sort(std::vector<unsigned int>& v, int place, int d)
{
    std::vector<unsigned int> bucket(d);
    std::vector<unsigned int> count(10);
    for (int i = 0; i < 10; ++i)
        count[i] = 0;
    for (int i = 0; i < d; i++)
        count[(v[i] / place) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = d - 1; i >= 0; i--)
    {
        bucket[count[(v[i] / place) % 10] - 1] = v[i];
        count[(v[i] / place) % 10]--;
    }
    for (int i = 0; i < d; i++)
        v[i] = bucket[i];
}


void radix_sort(std::vector<unsigned int>& v, int d, unsigned int max)
{
    for (int place = 1; max / place > 0; place *= 10)
        counting_sort(v, place, d);
}

void radixsort(std::vector<unsigned int>& v, int d)
{
    for (int j = 0; j < d; j++)
    {

    }
}

void print_result(std::vector<unsigned int>& v)
{
    unsigned long long sum = 0;
    for (int i = 0; i < v.size(); i++)
        sum += (unsigned long long)(i + 1) * (unsigned long long)v[i];
    std::cout << sum << std::endl;
}

unsigned int cur;
unsigned int a, b;

unsigned int nextRand24()
{
    cur = cur * a + b;
    return cur >> 8;
}

unsigned int nextRand32()
{
    unsigned int a = nextRand24(), b = nextRand24();
    return (a << 8) ^ b;
}

int main()
{
    int t, n;
    std::cin >> t >> n;

    for (int i = 0; i < t; i++)
    {
        cur = 0;
        std::cin >> a >> b;
        std::vector<unsigned int> v;
        unsigned int max = 0;
        for (int j = 0; j < n; j++)
        {
            unsigned int el = nextRand32();
            max = std::max(max, el);
            v.push_back(el);
        }

        int d = sizeof(v) / sizeof(max);
        radix_sort(v, d, max);
        print_result(v);
    }
    return 0;
}
