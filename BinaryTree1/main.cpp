#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *insertNode(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

bool searchNode(Node *root, int value)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == value)
    {
        return true;
    }

    if (value < root->data)
    {
        return searchNode(root->left, value);
    }
    else
    {
        return searchNode(root->right, value);
    }
}

Node *findMin(Node *node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // yaprak node
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

void printTree(Node *root, int space = 0)
{
    if (root == nullptr)
    {
        return;
    }

    int COUNT = 8;
    space += COUNT;

    printTree(root->right, space); // sağ dalı izle

    cout << endl;
    for (int i = COUNT; i < space; i++)
    {
        cout << " ";
    }
    cout << root->data << "\n";

    printTree(root->left, space); // sol dalı izle
}

int main()
{
    Node *root = nullptr;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    cout << "--- İkili Ağaç Yapısı ---" << endl;
    printTree(root);
    cout << endl;

    cout << "\nNode 20 siliniyor" << endl;
    root = deleteNode(root, 20);

    cout << "--- İkili Ağaç Yapısı ---" << endl;
    printTree(root);

    cout << "\nNode 70 siliniyor" << endl;
    root = deleteNode(root, 70);

    cout << "--- İkili Ağaç Yapısı ---" << endl;
    printTree(root);

    return 0;
}