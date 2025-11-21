#include <iostream>
#include <locale.h>
#include "util.h"
using namespace std;

void ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void PrintAllNodes(struct Node *head)
{
    if (head == NULL)
        cout << "List empty" << endl;
    else
    {
        auto temp = head;
        int i = 0;
        while (temp != NULL)
        {
            cout << "Node " << i << ": [" << temp->data << "] -> " << temp->next << endl;
            temp = temp->next;
            i++;
        }
    }
}

int CountNodes(struct Node *head)
{
    int nodeCount = 0;
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return 0;
    }
    else
    {
        auto temp = head;
        while (temp != NULL)
        {
            nodeCount++;
            temp = temp->next;
        }
        return nodeCount;
    }
}

struct Node *AddToStart(struct Node *head, int key)
{
    if (head == NULL)
    {
        auto temp = new Node();
        temp->data = key;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        auto temp = new Node();
        temp->data = key;
        temp->next = head;
        head = temp;
    }

    return head;
}

struct Node *RemoveFromStart(struct Node *head)
{
    if (head == NULL)
    {
        cout << "List already empty.";
    }
    else
    {
        auto temp = head;
        head = head->next;
        delete temp;
    }

    return head;
}

struct Node *AddToEnd(struct Node *head, int key)
{
    if (head == NULL)
    {
        auto temp = new Node();
        temp->data = key;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        auto temp = new Node();
        temp->data = key;
        temp->next = NULL;

        auto temp2 = head;
        while (temp2->next != NULL)
            temp2 = temp2->next;

        temp2->next = temp;
    }

    return head;
}

struct Node *RemoveFromEnd(struct Node *head)
{
    if (head == NULL)
    {
        cout << "List already empty.";
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        auto temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    return head;
}

struct Node *AddBetween(struct Node *head, int key, int index)
{
    if (index == 0)
    {
        return AddToStart(head, key);
    }

    if (head == NULL)
    {
        auto temp = new Node();
        temp->data = key;
        temp->next = NULL;
        return temp;
    }

    auto temp = new Node();
    temp->data = key;

    auto temp2 = head;
    for (int i = 0; i < index - 1; i++)
    {
        if (temp2->next == NULL)
        {
            cout << "Reached end of list, Index out of bounds.";
            delete temp;
            return head;
        }

        temp2 = temp2->next;
    }

    temp->next = temp2->next;
    temp2->next = temp;

    return head;
}

struct Node *RemoveBetween(struct Node *head, int index)
{
    if (head == NULL)
    {
        cout << "List already empty.";
        return head;
    }

    if (index == 0)
    {
        return RemoveFromStart(head);
    }

    auto temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        if (temp->next == NULL)
        {
            cout << "Index out of bounds.";
            return head;
        }
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Index out of bounds.";
        return head;
    }

    auto nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;

    return head;
}

struct Node *SearchNode(struct Node *head, int key)
{
    if (head == NULL)
    {
        return NULL;
    }

    auto temp = head;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    return temp; // can return null
}
