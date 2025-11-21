using namespace std;
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "linked_list.h"
#include "util.h"

Node* AddVehicle(Node* head) {
    string plate_number, car_type;
    int fee;

    cout << "\033[?25h";  // show cursor

    cout << "--- ARAÇ EKLEME EKRANI ---" << endl;

    cout << "Arabanın plakasını yazınız: ";
    cin >> plate_number;
    cout << "Arabanın plakasını tipini yazınız (SUV, Sedan, etc.): ";
    cin >> car_type;
    cout << "Arabanın park ücretini yazınız: ";
    cin >> fee;

    head = AddToEnd(head, plate_number, car_type, fee);
    cout << "Araç başarıyla eklendi!" << endl;

    cout << "\033[?25l";  // hide cursor

    return head;
}

void ListVehicles(Node* head) {
    Node* current = head;

    cout << "------- KAYITLI ARAÇLAR -------" << endl;

    int i = 1;
    while (current != NULL) {
        cout << "  1." << current->plate_number << " (" << current->car_type << ") - " << current->fee << " TL" << endl;
        current = current->next;
        i++;
    }

    if (head == NULL) {
        cout << "Otoparkta araç bulunmamaktadır." << endl;
    }
}

Node* RemoveVehicle(Node* head) {
    if (head == NULL) {
        cout << "------- ARAÇ ÇIKARMA EKRANI -------" << endl;
        cout << "Otoparkta araç bulunmamaktadır." << endl;
        return head;
    }

    // Count vehicles
    size_t vehicle_count = 0;
    Node* current = head;
    while (current != NULL) {
        vehicle_count++;
        current = current->next;
    }

    size_t selected = 0;
    bool selecting = true;

    cout << "\033[?25l";  // hide cursor
    while (selecting) {
        ClearScreen();

        cout << "------- ARAÇ ÇIKARMA EKRANI -------" << endl;
        cout << "Ok tuşları ile araç seçin, Enter'a basarak çıkarın, ESC ile iptal edin\n" << endl;

        current = head;
        size_t i = 0;
        while (current != NULL) {
            if (i == selected) {
                cout << "\033[32m> " << current->plate_number << " (" << current->car_type << ") - " << current->fee << " TL\033[0m" << endl;
            } else {
                cout << "  " << current->plate_number << " (" << current->car_type << ") - " << current->fee << " TL" << endl;
            }
            current = current->next;
            i++;
        }

        int key = GetKeyPress();

        if (key == KEY_UP) {
            if (selected == 0) {
                selected = vehicle_count - 1;
            } else {
                selected--;
            }
        } else if (key == KEY_DOWN) {
            selected++;
            if (selected >= vehicle_count) selected = 0;
        } else if (key == KEY_ENTER) {
            head = RemoveBetween(head, selected);
            cout << "\033[?25h";  // show cursor
            cout << "\nAraç başarıyla çıkarıldı!" << endl;
            selecting = false;
        } else if (key == 27) {  // ESC key
            cout << "\nİptal edildi." << endl;
            selecting = false;
        }
    }

    return head;
}

void CountVehicles(Node* head) {
    cout << "------- ARAÇLARI SAYMA -------" << endl;

    int count = 0;

    Node* current = head;
    while (current != NULL) {
        current = current->next;
        count++;
    }

    cout << (count == 0 ? "Otoparkta araç bulunmuyor" : "Otoparkta " + to_string(count) + " Adet araç bulunuyor") << endl;
}

void CountVehicleFees(Node* head) {
    cout << "------- ARAÇ ÜCRETLERİNİ SAYMA -------" << endl;

    int fees = 0;

    Node* current = head;
    while (current != NULL) {
        fees += current->fee;
        current = current->next;
    }

    cout << (fees == 0 ? "Otoparkta araç bulunmuyor" : "Otoparktaki araçların toplam park ücreti: " + to_string(fees)) << endl;
}

void ExportVehicles(Node* head) {
    cout << "------- ARAÇLARI DOSYAYA ÇIKARTMA -------" << endl;

    filesystem::path file_path = "./export.log";
    ofstream file(file_path);

    Node* current = head;
    while (current != NULL) {
        if (file.is_open()) {
            file << (current->plate_number + "|" + current->car_type + "|" + to_string(current->fee) + "\n");
        }
        current = current->next;
    }
    file.close();
    cout << "Dosya oluşturuldu: " << file_path << endl;
}

Node* ImportVehicles(Node* head) {
    cout << "------- DOSYADAN ARAÇ YÜKLEME -------" << endl;

    filesystem::path file_path = "./export.log";

    if (!filesystem::exists(file_path)) {
        cout << "Hata: export.log dosyası bulunamadı!" << endl;
        return head;
    }

    ifstream file(file_path);
    if (!file.is_open()) {
        cout << "Hata: Dosya açılamadı!" << endl;
        return head;
    }

    int count = 0;
    string line;
    while (getline(file, line)) {
        size_t first_pipe = line.find('|');
        size_t second_pipe = line.find('|', first_pipe + 1);

        if (first_pipe != string::npos && second_pipe != string::npos) {
            string plate = line.substr(0, first_pipe);
            string type = line.substr(first_pipe + 1, second_pipe - first_pipe - 1);
            int fee = stoi(line.substr(second_pipe + 1));

            head = AddToEnd(head, plate, type, fee);
            count++;
        }
    }

    file.close();
    cout << count << " araç başarıyla yüklendi!" << endl;
    return head;
}