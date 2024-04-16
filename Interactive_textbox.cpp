#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread> 
#include <chrono>
#include <string>


using namespace std::chrono_literals;
using namespace std;

HANDLE console;

//Function drawing green square.

void Draw() {
    COORD pos;                                              //Setting position of square.
    pos.X = 30;
    pos.Y = 10;


    SetConsoleTextAttribute(console, BACKGROUND_GREEN);     //Changing background to green color.

    for (int i = 0; i < 32; ++i) {                          //Drwaing square.
        SetConsoleCursorPosition(console, pos);
        std::cout << " ";
        pos.X++;
    }
}
//Function for entering and deleting characters and changing the cursor position.
void Write() {
    COORD pos;                                              //Setting positon of cursor.
    pos.X = 30;
    pos.Y = 10;
    SetConsoleCursorPosition(console, pos);
    int input = 0;
    while (input != 27)                                     //Loop to turn off program when ESC pressed.
    {
        if (_kbhit())
        {
            input = _getch();
            if ((input == 224 || input == 0) && _kbhit()==1) {      //Catching arrow keys and function keys to move cursor around. (Arrows on numpad works to, when number lock is on.)
                switch (_getch()) {                                 
                case 75:
                    if (pos.X > 30) {
                        pos.X -= 1;
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
            else {                                                                      //Printing characters.
                if ((pos.X <= 61 && 30 <= pos.X) && (32 <= input && input <= 255)) {
                    pos.X++;
                    cout << char(input);
                }
                if ((pos.X <= 62 && 31 <= pos.X) && input == 8) {                         //Making backspace work.
                    pos.X--;
                    SetConsoleCursorPosition(console, pos);
                    cout << char(32);
                    SetConsoleCursorPosition(console, pos);
                }

                if ((pos.X <= 61 && 30 <= pos.X) && input == 9) {                         //Making TAB work.
                    cout << char(9);
                    pos.X += 4;
                    SetConsoleCursorPosition(console, pos);
                }
                if (pos.X > 61 && input == 9) {
                        pos.X=62;
                    SetConsoleCursorPosition(console, pos);
                }
            }
            
            }
        }
    }
//Main function.
int main() {
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    Draw();
    Write();
}

