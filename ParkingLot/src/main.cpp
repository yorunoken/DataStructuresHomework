using namespace std;

#include <iostream>
#include <utility>
#include <vector>

#include "linked-list.h"
#include "lot-logic.h"
#include "util.h"

vector<pair<string, MenuOptions>> options = {
    {"Araç Ekle", ADD_VEHICLE},
    {"Araç Çıkar", REMOVE_VEHICLE},
    {"Araçları Listele", LIST_VEHICLES},
    {"Araç Sayısı", VEHICLE_COUNT},
    {"Araçların Toplam Ücreti", TOTAL_FEE},
    {"Araçları .log Olarak Dışarı Çıkart", EXPORT_TO_LOG},
    {"Kayıtlı .log Dosyasından Arabaları Getir", IMPORT_SAVED_VEHICLES},
    {"Çıkış Yap", EXIT}
};

int main() {
    struct Node* head = NULL;

    size_t selected = 0;
    size_t options_size = options.size();
    bool running = true;

    cout << "\033[?25l";  // hides cursor
    while (running) {
        ClearScreen();

        cout << "-------- ANA MENÜ --------" << endl;

        for (size_t i = 0; i < options_size; i++) {
            if (i == selected) {
                // making the text colorful if it's highlighted
                cout << "\033[32m> " << options[i].first << "\033[0m" << endl;
            } else {
                cout << "  " << options[i].first << endl;
            }
        }

        int key = GetKeyPress();

        if (key == KEY_UP) {
            // becaue size_t cannot go below 0, we must make sure it's not 0
            // before extracting 1 from it.
            if (selected == 0) {
                selected = options_size - 1;
            } else {
                selected--;
            }
        } else if (key == KEY_DOWN) {
            selected++;
            if (selected >= options_size) selected = 0;  // wrap to bottom
        } else if (key == KEY_ENTER) {
            MenuOptions option = options[selected].second;

            ClearScreen();

            switch (option) {
                case ADD_VEHICLE:
                    head = AddVehicle(head);
                    break;

                case REMOVE_VEHICLE:
                    head = RemoveVehicle(head);
                    break;

                case LIST_VEHICLES:
                    ListVehicles(head);
                    break;

                case VEHICLE_COUNT:
                    CountVehicles(head);
                    break;

                case TOTAL_FEE:
                    CountVehicleFees(head);
                    break;

                case EXPORT_TO_LOG:
                    ExportVehicles(head);
                    break;

                case IMPORT_SAVED_VEHICLES:
                    head = ImportVehicles(head);
                    break;

                case EXIT:
                    running = false;
                    break;
            }

            if (running) {
                cout << "\nAna menüye dönmek için bir tuşa basın...";
                GetKeyPress();
            }
        }
    }

    cout << "\033[?25h";  // make cursor come back :3
    return 0;
}
