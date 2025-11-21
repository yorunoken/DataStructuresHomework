#ifndef UTIL_H
#define UTIL_H

struct Node
{
    int data;
    struct Node *next;
};

void ClearScreen();
void PrintAllNodes(struct Node *head);
int CountNodes(struct Node *head);
struct Node *AddToStart(struct Node *head, int key);
struct Node *RemoveFromStart(struct Node *head);
struct Node *AddToEnd(struct Node *head, int key);
struct Node *RemoveFromEnd(struct Node *head);
struct Node *AddBetween(struct Node *head, int key, int index);
struct Node *RemoveBetween(struct Node *head, int index);
struct Node *SearchNode(struct Node *head, int key);

#endif