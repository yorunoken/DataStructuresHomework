using namespace std;

#include "util.h"

#include <iostream>

int GetKeyPress() {
    int c = 0;
#ifdef _WIN32
    c = _getch();
    if (c == 0 || c == 224) {
        c = _getch();
    }
#else
    // no idea how this part works, i just copy pasted from the internet :P
    struct termios old_settings, new_settings;
    tcgetattr(STDIN_FILENO, &old_settings);
    new_settings = old_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);

    c = getchar();
    // handling sequences for arrow keys
    if (c == 27) {
        getchar();  // skip [
        c = getchar();
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
#endif
    return c;
}

void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
