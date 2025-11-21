#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

using namespace std;

struct Node {
    string plate_number;
    string car_type;
    int fee;
    struct Node* next;
};

struct Node* AddToStart(struct Node* head, string plate, string type, int fee);
struct Node* RemoveFromStart(struct Node* head);
struct Node* AddToEnd(struct Node* head, string plate, string type, int fee);
struct Node* RemoveFromEnd(struct Node* head);
struct Node* AddBetween(struct Node* head, string plate, string type, int fee, int index);
struct Node* RemoveBetween(struct Node* head, int index);
struct Node* SearchNode(struct Node* head, string plate);

#endif
