#ifndef display_h
#define display_h
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define textcolor(txt,back) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back*16+txt)
#define resetcolor() SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)
#include "display.h"
#include "ion.h"
#include "pm.h"
#include "LL.h"
using namespace std;
void space_out(int);
void under_lined(int);
void display_menu();
#endif //display_h