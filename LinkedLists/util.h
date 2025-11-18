#ifndef UTIL_H
#define UTIL_H

struct node
{
    int data;
    struct node *next;
};

void clearScreen();
void printAllNodes(struct node *head);
int countNodes(struct node *head);
struct node *addToStart(struct node *head, int key);
struct node *removeFromStart(struct node *head);
struct node *addToEnd(struct node *head, int key);
struct node *removeFromEnd(struct node *head);
struct node *addBetween(struct node *head, int key, int index);
struct node *removeBetween(struct node *head, int index);
struct node *searchNode(struct node *head, int key);

#endif