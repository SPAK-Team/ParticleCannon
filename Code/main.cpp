#include "display.h"
#include "ion.h"
#include "LL.h"
#include "pm.h"
int main(int argc, char *argv[])
{
    int i;

    LL atmosphere;
    pm *A;
    for(i=0;i<10;i++){
        A=new pm;
        atmosphere.add_pm(A);

    }

	A = new super_pm(3,35);
	atmosphere.add_pm(A);
    ion me;
    int out=0;

char choose;

do{
        display_menu();

        choose=_getch();
        switch (choose)
        {
        case '1' :
            system("CLS");
            do{

        char choose='0';

        if (_kbhit) {
                system("CLS");
                //atmosphere.show_all();
                atmosphere.display_all_pm(me);
                me.display_cannon(me.x_location());



        choose = _getch();
        //cout<<"  "<<endl<<flush; //flush forces the printing to the screen before it pauses
		//system ("CLS"); //pause displays a message and waits for the user to hit a key


            switch(choose)
            {

            	case 'a':
            	case 'd': me.move_ion(choose);break;
            	case 's':
				    atmosphere.display_all_with_ion_shot(me);
            	    atmosphere.shot(me.shoot_ion(),me);
            	break;
            	case 'c' : me.charge_ion(); break;
            	case 'o' : out=1;break;


            	default : break;
			}
			
			
			 


        }//end if

	}while(out==0);
	out=0; 
	break;

        case '2' : out=1; break;
            default: break;
        }






system("CLS");



}while(out==0);


out=0;

     return 0;;
}


