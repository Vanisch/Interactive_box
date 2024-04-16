#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread> 
#include <chrono>
#include <string>


using namespace std::chrono_literals;
using namespace std;

HANDLE console;

void Draw() {
    COORD pos;
    pos.X = 30;
    pos.Y = 10;


    SetConsoleTextAttribute(console, BACKGROUND_GREEN);

    for (int i = 0; i < 32; ++i) {
        SetConsoleCursorPosition(console, pos);
        std::cout << " ";
        pos.X++;
    }
}
void Write() {
    COORD pos;
    pos.X = 30;
    pos.Y = 10;
    SetConsoleCursorPosition(console, pos);
    int input = 0;
    while (input != 27)
    {
        if (_kbhit())
        {
            input = _getch();
            if (input == 224 || input == 0) {
                switch (_getch()) {
                case 8:
                    if (pos.X > 30) {
                        pos.X -= 1;
                    }
                    SetConsoleCursorPosition(console, pos);
                    cout << char(0);
                    break;
                case 75:
                    if (pos.X > 30) {
                        pos.X-=1;
                    }
                    SetConsoleCursorPosition(console, pos);
                    break;
                case 77:
                    if (pos.X <= 61) {
                        pos.X++;
                    }
                    SetConsoleCursorPosition(console, pos);
                    break;
                }
            }
            else {
                if (pos.X <= 61 && 30<=pos.X && 32 <= input && input <= 255) {
                    pos.X++;
                    cout << char(input);
                }
            }
        }
    }
}

int main() {
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    Draw();
    Write();
}

