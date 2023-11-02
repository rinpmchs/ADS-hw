/*
Вы тестируете реализацию двоичного дерева поиска. У вас уже написан код, который ищет,
добавляет и удаляет ключи, а также выводит внутреннее состояние структуры данных после каждой операции.
Вам осталось проверить, что в каждый момент дерево остаётся корректным деревом поиска.
Но проверить теперь нужно более общее свойство. Дереву разрешается содержать равные ключи,
но они всегда должны находиться в правом поддереве. Формально, двоичное дерево называется деревом поиска,
если для любой вершины её ключ больше всех ключей из её левого поддерева и не меньше всех ключей из правого поддерева.
Задача из курса «Алгоритмы: теория и практика. Структуры данных»: https://stepik.org/course/1547/syllabus

Формат ввода
Первая строка содержит число вершин n. Вершины дерева пронумерованы числами от 0 до n−1.
Вершина 0 является корнем. Каждая из следующих n строк содержит информацию о вершинах
0,1,...,n−1 : i-я строка задаёт числа keyi, lefti и righti, где keyi — ключ вершины i,
lefti — индекс левого сына вершины i, а righti — индекс правого сына вершины i.
Если у вершины i нет одного или обоих сыновей, соответствующее значение равно -1.

Формат вывода
Выведите CORRECT, если дерево является корректным деревом поиска, и INCORRECT в противном случае.
 */

#include <iostream>
#include <vector>
#include <climits>

struct Node
{
    long long key;
    Node* left;
    Node* right;
};

bool isValidBST(Node* root, long long key_min, long long key_max)
{
    if (!root) return true;
    if (root->key < key_min || root->key >= key_max) return false;

    return isValidBST(root->left, key_min, root->key) &&
           isValidBST(root->right, root->key, key_max);
}

int main()
{
    int n, l_id, r_id;
    long long key;
    std::cin >> n;
    std::vector<Node> t(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> key >> l_id >> r_id;
        t[i].key = key;
        if (l_id != -1) t[i].left = &t[l_id];
        else t[i].left = nullptr;

        if (r_id != -1) t[i].right = &t[r_id];
        else t[i].right = nullptr;
    }

    if (isValidBST(&t[0], LLONG_MIN, LLONG_MAX)) std::cout << "CORRECT";
    else std::cout << "INCORRECT";
    return 0;
}
