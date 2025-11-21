using namespace std;

#include "linked-list.h"

#include <iostream>

struct Node* AddToStart(struct Node* head, string plate, string type, int fee) {
    auto temp = new Node();
    temp->plate_number = plate;
    temp->car_type = type;
    temp->fee = fee;
    temp->next = head;

    return temp;
}

struct Node* RemoveFromStart(struct Node* head) {
    if (head == NULL) {
        cout << "List already empty.";
    } else {
        auto temp = head;
        head = head->next;
        delete temp;
    }

    return head;
}

struct Node* AddToEnd(struct Node* head, string plate, string type, int fee) {
    auto temp = new Node();
    temp->plate_number = plate;
    temp->car_type = type;
    temp->fee = fee;
    temp->next = NULL;

    if (head == NULL) {
        return temp;
    }

    auto current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;

    return head;
}

struct Node* RemoveFromEnd(struct Node* head) {
    if (head == NULL) {
        cout << "List already empty.";
    } else if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        auto temp = head;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    return head;
}

struct Node* AddBetween(struct Node* head, string plate, string type, int fee, int index) {
    if (index == 0) {
        return AddToStart(head, plate, type, fee);
    }

    if (head == NULL) {
        auto temp = new Node();
        temp->plate_number = plate;
        temp->car_type = type;
        temp->fee = fee;
        temp->next = NULL;
        return temp;
    }

    auto temp = new Node();
    temp->plate_number = plate;
    temp->car_type = type;
    temp->fee = fee;

    auto current = head;
    for (int i = 0; i < index - 1; i++) {
        if (current->next == NULL) {
            cout << "Reached end of list, Index out of bounds." << endl;
            delete temp;
            return head;
        }
        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;

    return head;
}

struct Node* RemoveBetween(struct Node* head, int index) {
    if (head == NULL) {
        cout << "List already empty.";
        return head;
    }

    if (index == 0) {
        return RemoveFromStart(head);
    }

    auto temp = head;
    for (int i = 0; i < index - 1; i++) {
        if (temp->next == NULL) {
            cout << "Index out of bounds.";
            return head;
        }
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Index out of bounds.";
        return head;
    }

    auto nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;

    return head;
}

struct Node* SearchNode(struct Node* head, string plate) {
    auto current = head;
    while (current != NULL) {
        if (current->plate_number == plate) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
