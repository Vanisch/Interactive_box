#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread> 
#include <chrono>


using namespace std::chrono_literals;
using namespace std;

HANDLE console;

void Draw() {
    COORD pos;
    pos.X = 30;
    pos.Y = 10;


    SetConsoleTextAttribute(console, BACKGROUND_BLUE);

    for (int i = 0; i < 32; ++i) {
        SetConsoleCursorPosition(console, pos);
        std::cout << " ";
        pos.X++;
    }
}
void Write() {

}

int main() {
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    Draw();
    COORD pos;
    pos.X = 30;
    pos.Y = 10;
    SetConsoleCursorPosition(console, pos);
    cout << "Test";
}
