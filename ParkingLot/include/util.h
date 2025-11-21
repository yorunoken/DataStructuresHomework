#ifndef UTIL_H
#define UTIL_H

enum MenuOptions { ADD_VEHICLE = 0, REMOVE_VEHICLE, LIST_VEHICLES, VEHICLE_COUNT, TOTAL_FEE, EXPORT_TO_LOG, IMPORT_SAVED_VEHICLES, EXIT };

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
    #define KEY_UP 72
    #define KEY_DOWN 80
    #define KEY_ENTER 13
#else
    #include <termios.h>
    #include <unistd.h>
    #define KEY_UP 65
    #define KEY_DOWN 66
    #define KEY_ENTER 10
#endif

int GetKeyPress();
void ClearScreen();

#endif