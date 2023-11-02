/*
Вам даны пары чисел (ai, bi), Вам необходимо построить декартово дерево, такое что i-ая вершина имеет ключи (ai, bi),
вершины с ключом ai образуют бинарное дерево поиска, а вершины с ключом bi образуют кучу.

Формат ввода
В первой строке записано число N — количество пар. Далее следует N (1⩽N⩽1000) пар (ai, bi).
Для всех пар |ai|, |bi| ⩽ 30000.

Формат вывода
Если декартово дерево с таким набором ключей построить возможно, выведите в первой строке YES,
в противном случае выведите NO. В случае ответа YES, выведите N строк, каждая из которых должна описывать вершину.
Описание вершины состоит из трёх чисел: номер предка, номер левого сына и номер правого сына.
Если у вершины отсутствует предок или какой-либо из сыновей, то выводите на его месте число 0.

Если подходящих деревьев несколько, выведите любое.
 */

#include <iostream>
#include <algorithm>

class Node
{
public:
    int key, prior, id;
    Node* left;
    Node* right;
    Node() { }
    Node (int key, int prior, int id) : key(key), prior(prior), id(id), left(nullptr), right(nullptr) { }
};

void split (Node* t, int key, Node* &l, Node* &r)
{
    if (t == nullptr)
        l = r = nullptr;
    else if (key < t->key)
        split (t->left, key, l, t->left), r = t;
    else
        split (t->right, key, t->right, r), l = t;
}

bool insert (Node* &t, Node* it) {
    if (t == nullptr)
    {
        t = it;
        return true;
    }
    else if (it->prior > t->prior)
        split (t, it->key, it->left, it->right), t = it;
    else
        insert (it->key < t->key ? t->left : t->right, it);
    return false;
}

void merge (Node* & t, Node* l, Node* r)
{
    if (l == nullptr || r == nullptr)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->right, l->right, r), t = l;
    else
        merge (r->left, l, r->left), t = r;
}

void erase (Node* & t, int key) {
    if (t->key == key)
        merge (t, t->left, t->right);
    else
        erase (key < t->key ? t->left : t->right, key);
}

Node* unite (Node* l, Node* r) {
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  std::swap (l, r);
    Node* lt;
    Node* rt;
    split (r, l->key, lt, rt);
    l->left = unite (l->left, lt);
    l->right = unite (l->right, rt);
    return l;
}

int main ()
{
    int n;
    std::cin >> n;
    Node* root = nullptr;

    for (int i = 0; i < n; i++)
    {
        int key, priority;
        std::cin >> key >> priority;
        Node* new_node = new Node(key, priority, i + 1);
        bool f = insert(root, new_node);
        if (!f)
        {
            std::cout << "NO";
            return 0;
        }
    }

    std::cout << "YES" << std::endl;
    for (int i = 1; i < n; i++)
    {
        //print parent id, left child id, right child id
        //std::cout << parent id << " " << root->left->id << " " << root->right->id;
    }
    return 0;
}
