#ifndef pm_h
#define pm_h
#include "LL.h"
using namespace std;
class LL;
class pm{
		protected :

      		int x;
            int y;
            pm* next;
            pm* previous;

      	public :
      		pm(int=999,int=999);
      		virtual void move_pm();
      		virtual bool decay_pm(LL*);
			virtual void show_pm();
        	void insert_next(pm*);
        	void insert_previous(pm*);
        	pm* move_next();
        	pm* move_prev();
        	int x_location();
        	int y_location();
        	virtual void display_pm();
			void check() const throw();
            virtual ~pm();
	};

class super_pm:public pm{
	private:
		int recieved_ion;

	public:
		super_pm(int=999,int=999);
		bool decay_pm(LL*);
		void display_pm();
		~super_pm();

};
#endif //pm_h