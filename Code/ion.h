#ifndef ion_h
#define ion_h
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define textcolor(txt,back) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back*16+txt)
#define resetcolor() SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)
using namespace std;
	class ion{

		private:
      		int amount_ion;
      		int x;
      		int y;

      		int score;
		public:
      		ion(int=100,int=2000);
     		 int shoot_ion();
     		 int show_amount_ion();
     		 int show_score();
            int x_location();
     		 void operator++();
      		void charge_ion();
      		void move_ion(char);
      		void display_cannon(int);
      		~ion();
};
#endif //ion.h