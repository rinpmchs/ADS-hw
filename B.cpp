/*
Глеб обожает шоппинг. Как-то раз он загорелся идеей подобрать себе майку и штаны так,
чтобы выглядеть в них максимально стильно.
В понимании Глеба стильность одежды тем больше, чем меньше разница в цвете элементов его одежды.
В наличии имеется N (1 ≤ N ≤ 105) маек и M (1 ≤ M ≤ 105) штанов,
про каждый элемент известен его цвет (целое число от 1 до 107).
Помогите Глебу выбрать одну майку и одни штаны так, чтобы разница в их цвете была как можно меньше.

Сначала вводится информация о майках: в первой строке целое число N
и во второй N целых чисел от 1 до 107 — цвета имеющихся в наличии маек.
Гарантируется, что номера цветов идут в возрастающем порядке (в частности, цвета никаких двух маек не совпадают).
Далее в том же формате идёт описание штанов: их количество M
и в следующей строке M целых чисел от 1 до 107 в возрастающем порядке — цвета штанов.
*/

#include <iostream>
#include <vector>


std::pair<int, int> get_best_pair(std::vector<int>& s, std::vector<int>& p)
{
    std::pair<int, int> ans;
    ans.first = s[0];
    ans.second = p[0];
    int dif = std::abs(s[0] - p[0]);
    int i = 0, j = 0;
    while (i < s.size() && j < p.size())
    {
        int current_dif = std::abs(s[i] - p[j]);
        if (current_dif < dif)
        {
            dif = current_dif;
            ans.first = s[i];
            ans.second = p[j];
        }
        if (s[i] < p[j]) i++;
        else j++;
    }
    return ans;
}


int main()
{
    int n, m;
    std::vector<int> s, p;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s_color;
        std::cin >> s_color;
        s.push_back(s_color);
    }
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        int p_color;
        std::cin >> p_color;
        p.push_back(p_color);
    }
    std::pair<int, int> ans = get_best_pair(s, p);
    std::cout << ans.first << " " << ans.second;
}