#include <iostream>
#include <locale.h>
#include "util.h"
using namespace std;

int main()
{
    struct node *head = NULL;
    int num, selection, index;

    while (true)
    {
        cout << endl;
        cout << "tek yonlu bagli liste uygulamasi\n\n";
        cout << "1-- basa eleman ekleme" << endl;
        cout << "2-- sona eleman ekleme" << endl;
        cout << "3-- ortaya eleman ekleme" << endl
             << endl;

        cout << "4-- bastan eleman silme" << endl;
        cout << "5-- sondan eleman silme" << endl;
        cout << "6-- ortadan eleman silme" << endl
             << endl;

        cout << "7-- eleman arama" << endl
             << endl;

        cout << "8-- listedeki tum bilgileri yazdir" << endl;
        cout << "9-- listedeki dugumleri say" << endl
             << endl;

        cout << "0-- cikis" << endl;
        cin >> selection;

        clearScreen();
        switch (selection)
        {
        case 1:
            cout << "basa eklenecek sayi: " << endl;
            cin >> num;
            head = addToStart(head, num);
            break;
        case 2:
            cout << "sona eklenecek sayi: " << endl;
            cin >> num;
            head = addToEnd(head, num);
            break;
        case 3:
            cout << "ortaya eklenecek sayi: " << endl;
            cin >> num;
            cout << "indeks girin: " << endl;
            cin >> index;
            head = addBetween(head, num, index);
            break;
        case 4:
            head = removeFromStart(head);
            break;
        case 5:
            head = removeFromEnd(head);
            break;
        case 6:
            cout << "silinecek elemanin indeksi: " << endl;
            cin >> index;
            head = removeBetween(head, index);
            break;
        case 7:
        {
            cout << "aranacak sayi: " << endl;
            cin >> num;
            auto node = searchNode(head, num);
            cout << "Node: [" << node->data << "] -> " << node->next << endl;
            break;
        }
        case 8:
            printAllNodes(head);
            break;
        case 9:
        {
            int nodeCount = countNodes(head);
            cout << "listede ki dugum adeti: " << nodeCount << endl;
            break;
        }
        case 0:
            cout << "cikis";
            return 0;
        default:
            cout << "hatali secim yaptiniz";
            break;
        }
    }

    return 0;
}
