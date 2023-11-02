/*
В каждой строке сначала записан номер класса (число, равное 9, 10 или 11),
затем (через пробел) – фамилия ученика. Общее число строк в файле не превосходит 100000.
Длина каждой фамилии не превосходит 50 символов.

Необходимо вывести список школьников по классам:
сначала всех учеников 9 класса, затем – 10, затем – 11.
Внутри одного класса порядок вывода фамилий должен быть таким же, как на входе.
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

void inorderTraversal(Node* root)
{
    if (root == nullptr) return;
    inorderTraversal(root->left);
    std::cout << root->key << ' ';
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root)
{
    if (root == nullptr) return;
    std::cout << root->key << ' ';
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root)
{
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->key << ' ';
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
    inorderTraversal(root);
    std::cout << std::endl;
    preorderTraversal(root);
    std::cout << std::endl;
    postorderTraversal(root);
}
