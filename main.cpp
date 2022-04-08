#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

char button_text[] = " Button ";
int choice = 1;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
    ShowConsoleCursor(false);
    HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
    DWORD fdwMode;
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    if (!SetConsoleMode(h, fdwMode)) {
        fprintf(stderr, "%s\n", "SetConsoleMode");
    }
    DWORD cc;
    INPUT_RECORD irec;
    KEY_EVENT_RECORD key;
    MOUSE_EVENT_RECORD mouse;

    for (;;)
    {

        ReadConsoleInput(h, &irec, 1, &cc);
        if (irec.EventType == MOUSE_EVENT)
        {
            gotoxy(10, 6);
            color(7);
            cout << "1. " << button_text << " ";
            gotoxy(10, 7);
            color(7);
            cout << "2. " << button_text << " ";
            gotoxy(10, 8);
            color(7);
            cout << "3. " << button_text << " ";
            mouse = (MOUSE_EVENT_RECORD&)irec.Event;




            if ((mouse.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && mouse.dwMousePosition.X >= 10 &&
                 mouse.dwMousePosition.X < 10+strlen(button_text)+3 && mouse.dwMousePosition.Y == 6) ||
                (key.bKeyDown && key.wVirtualKeyCode == 0x0D && choice == 1))
            {
                choice = 1;
                gotoxy(10, 6);
                color(BACKGROUND_INTENSITY);
                cout << "1. " << button_text;
                gotoxy(10, 10);
                color(7);
                cout << "First button pressed ";
            }
            else if ((mouse.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && mouse.dwMousePosition.X >= 10 &&
                      mouse.dwMousePosition.X < 10+strlen(button_text)+3 && mouse.dwMousePosition.Y == 7) ||
                    (key.bKeyDown && key.wVirtualKeyCode == 0x0D && choice == 2))
            {
                choice = 2;
                gotoxy(10, 7);
                color(BACKGROUND_INTENSITY);
                cout << "2. " << button_text;
                gotoxy(10, 10);
                color(7);
                cout << "Second button pressed ";
            }
            else if ((mouse.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && mouse.dwMousePosition.X >= 10 &&
                      mouse.dwMousePosition.X < 10+strlen(button_text)+3 && mouse.dwMousePosition.Y == 8) ||
                     (key.bKeyDown && key.wVirtualKeyCode == 0x0D && choice == 3))
            {
                choice = 3;
                gotoxy(10, 8);
                color(BACKGROUND_INTENSITY);
                cout << "3. " << button_text;
                gotoxy(10, 10);
                color(7);
                cout << "Third button pressed ";
            }

        }
        else if (irec.EventType == KEY_EVENT)
        {
            key = (KEY_EVENT_RECORD&)irec.Event;

            if (key.bKeyDown) {
                if (key.wVirtualKeyCode == 0x26 && (choice == 2 || choice == 3)) {
                    choice--;
                } else if (key.wVirtualKeyCode == 0x28 && (choice == 1 || choice == 2)) {
                    choice++;
                }
            }
            if (choice == 1) {
                gotoxy(10, 6);
                color(7);
                cout << "1. " << button_text << "*";
                gotoxy(10, 7);
                color(7);
                cout << "2. " << button_text << " ";
                gotoxy(10, 8);
                color(7);
                cout << "3. " << button_text << " ";
            } else if (choice == 2) {
                gotoxy(10, 6);
                color(7);
                cout << "1. " << button_text << " ";
                gotoxy(10, 7);
                color(7);
                cout << "2. " << button_text << "*";
                gotoxy(10, 8);
                color(7);
                cout << "3. " << button_text << " ";
            } else if (choice == 3) {
                gotoxy(10, 6);
                color(7);
                cout << "1. " << button_text << " ";
                gotoxy(10, 7);
                color(7);
                cout << "2. " << button_text << " ";
                gotoxy(10, 8);
                color(7);
                cout << "3. " << button_text << "*";
            }


            if ((key.bKeyDown && key.wVirtualKeyCode == 0x0D && choice == 1))
            {

                gotoxy(10, 6);
                color(BACKGROUND_INTENSITY);
                cout << "1. " << button_text;
                gotoxy(10, 10);
                color(7);
                cout << "First button pressed ";
            }
            else if ((key.bKeyDown && key.wVirtualKeyCode == 0x0D && choice == 2))
            {
                gotoxy(10, 7);
                color(BACKGROUND_INTENSITY);
                cout << "2. " << button_text;
                gotoxy(10, 10);
                color(7);
                cout << "Second button pressed ";
            }
            else if ((key.bKeyDown && key.wVirtualKeyCode == 0x0D && choice == 3))
            {
                gotoxy(10, 8);
                color(BACKGROUND_INTENSITY);
                cout << "3. " << button_text;
                gotoxy(10, 10);
                color(7);
                cout << "Third button pressed ";
            }
        }

    }
}
