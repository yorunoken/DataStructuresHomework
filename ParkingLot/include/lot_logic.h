#ifndef LOT_LOGIC_H
#define LOT_LOGIC_H

#include "linked_list.h"

Node* AddVehicle(Node* head);
void ListVehicles(Node* head);
Node* RemoveVehicle(Node* head);
void CountVehicles(Node* head);
void CountVehicleFees(Node* head);
void ExportVehicles(Node* head);
Node* ImportVehicles(Node* head);

#endif