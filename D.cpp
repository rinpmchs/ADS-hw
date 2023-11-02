/*
Реализуйте сбалансированное двоичное дерево поиска.

Формат ввода
Входной файл содержит описание операций с деревом, их количество не превышает 100000.
В каждой строке находится одна из следующих операций.

insert x – добавить в дерево ключ x. Если ключ x уже в дереве, то ничего делать не надо.
delete x – удалить из дерева ключ x. Если ключа x в дереве нет, то ничего делать не надо.
exists x – если ключ x есть в дереве, выведите «true», иначе «false»
Все числа во входном файле целые и по модулю не превышают 109.

Формат вывода
Выведите последовательно результат выполнения всех операций exists. Следуйте формату выходного файла из примера.
 */

#include<iostream>
#include <sstream>
#include <string>

class Node
{
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return(node);
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(Node* N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{
    if (node == nullptr)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);
    // LL
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    // RR
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    // LR
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

bool exists(Node* root, int key) {
    if (root == nullptr)
        return false;
    else
    {
        Node* temp = root;
        while (temp != nullptr)
        {
            if (key == temp->key)
                return true;
            else if (key < temp->key)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return false;
    }
}


Node*  minValueNode(Node* node)
{
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int key)
{
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if((root->left == nullptr) || (root->right == nullptr))
        {
            Node* temp = root->left ?
                         root->left :
                         root->right;
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else* root =* temp;
            free(temp);
        }
        else
        {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    // LL
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}


int main()
{
    Node* root = nullptr;
    std::string func_name, str;
    int key;

    while (std::getline(std::cin, str))
    {
        std::stringstream ss(str);
        if(ss >> func_name >> key)
        {
            if (func_name == "insert")
                root = insert(root, key);
            else if (func_name == "exists")
                std::cout << (exists(root, key) ? "true" : "false") << std::endl;
            else if (func_name == "delete")
                root = deleteNode(root, key);
        }
        else break;
    }
    return 0;
}
