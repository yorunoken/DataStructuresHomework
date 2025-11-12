#include <iostream>
#include <locale.h>
#include "util.h"
using namespace std;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

struct node *addToStart(struct node *head, int key)
{
    if (head == NULL)
    {
        auto temp = new node();
        temp->data = key;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        auto temp = new node();
        temp->data = key;
        temp->next = head;
        head = temp;
    }

    return head;
}

struct node *removeFromStart(struct node *head)
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

struct node *addToEnd(struct node *head, int key)
{
    if (head == NULL)
    {
        auto temp = new node();
        temp->data = key;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        auto temp = new node();
        temp->data = key;
        temp->next = NULL;

        auto temp2 = head;
        while (temp2->next != NULL)
            temp2 = temp2->next;

        temp2->next = temp;
    }

    return head;
}

struct node *removeFromEnd(struct node *head)
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

struct node *addBetween(struct node *head, int key, int index)
{
    if (index == 0)
    {
        return addToStart(head, key);
    }

    if (head == NULL)
    {
        auto temp = new node();
        temp->data = key;
        temp->next = NULL;
        return temp;
    }

    auto temp = new node();
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

struct node *removeBetween(struct node *head, int index)
{
    if (head == NULL)
    {
        cout << "List already empty.";
        return head;
    }

    if (index == 0)
    {
        return removeFromStart(head);
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

struct node *searchNode(struct node *head, int key)
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
