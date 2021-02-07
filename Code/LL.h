#ifndef LL_h
#define LL_h
#include "pm.h"
#include "ion.h"
#include "display.h"
using namespace std;
class pm;
class LL{
      pm* hol;
      int size;
public:
       void add_pm(pm *&);
       void show_all();
       void shot(int,ion &);
       void insert_between(pm*,pm*);
       void insert_front(pm*,pm*);
       void insert_last(pm*,pm*);
       void move_all(); // create function
       void display_all_pm(ion);
       void display_all_with_ion_shot(ion);


       ~LL();
       LL();

};

#endif //LL_h