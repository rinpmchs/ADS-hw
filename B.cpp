/*
Вы тестируете реализацию двоичного дерева поиска. У вас уже написан код, который ищет, добавляет и удаляет ключи,
а также выводит внутреннее состояние структуры данных после каждой операции.
Вам осталось проверить, что в каждый момент дерево остаётся корректным деревом поиска.
Другими словами, вы хотите проверить, что для дерева корректно работает поиск, если ключ есть в дереве,
то процедура поиска его обязательно найдёт, если ключа нет — то не найдёт.
Задача из курса «Алгоритмы: теория и практика. Структуры данных»: https://stepik.org/course/1547/syllabus

Формат ввода
Первая строка содержит число вершин n. Вершины дерева пронумерованы числами от 0 до n−1.
Вершина 0 является корнем. Каждая из следующих n строк содержит информацию о вершинах
0,1,...,n−1 : i-я строка задаёт числа keyi, lefti и righti, где keyi — ключ вершины i,
lefti — индекс левого сына вершины i, а righti — индекс правого сына вершины i.
Если у вершины i нет одного или обоих сыновей, соответствующее значение равно -1.

Ограничения.
1≤n<210; −2^31 < keyi < 2^31−1; −1 ≤ leti, righti ≤ n−1.
Гарантируется, что вход задаёт корректное двоичное дерево: в частности,
если lefti≠ −1 и righti ≠ −1, то lefti ≠ righti;
никакая вершина не является сыном двух вершин; каждая вершина является потомком корня.

Формат вывода
Выведите CORRECT, если дерево является корректным деревом поиска, и INCORRECT в противном случае.
 */

#include <iostream>
#include <vector>

struct Node
{
    int key;
    Node* left;
    Node* right;
    Node(){}
    Node(int x) : key(x), left(nullptr), right(nullptr){}
};

bool isValidBST (std::vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i -1] > v[i])
            return false;
    }
    return true;
}

void sort(Node* root, std::vector<Node>& t, std::vector<int>& v)
{
    if (!root) return;
    sort(root->left, t, v);
    v.push_back(root->key);
    sort(root->right, t, v);
}

int main()
{
    int n, key, l_id, r_id;
    std::cin >> n;
    std::vector<Node> t(n);
    Node* root = &t[0];

    for (int i = 0; i < n; i++)
    {
        std::cin >> key >> l_id >> r_id;
        t[i].key = key;
        if (l_id == -1) t[i].left= nullptr;
        else t[i].left = &t[l_id];
        if (r_id == -1) t[i].right = nullptr;
        else t[i].right = &t[r_id];
    }

    std::vector<int> v(n);
    v.reserve(n);

    sort(root, t, v);
    if (isValidBST(v)) std::cout << "CORRECT";
    else std::cout << "INCORRECT";
}