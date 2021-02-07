#include "display.h"
#include "ion.h"
#include "pm.h"
#include "LL.h"






 pm ::pm(int x_locate,int y_locate){

	if(x_locate==999&&y_locate==999){
		x = rand() % 150 + 1;
   		y = rand() % 38 + 1;
	}
	else {
		x=x_locate;
		y=y_locate;
	}
	next=NULL;
	previous=NULL;
	//cout<<"Success"<<endl;

}
pm::~pm(){
//	cout<<"OUt of pm class";
}
void pm :: move_pm(){
    y++;
}


pm* pm::move_next(){
  	return next;
}
pm* pm::move_prev(){
  	return previous;
}
void pm:: show_pm(){
         cout<<"PM GPS: x= "<<x<<" y= "<<y<<endl;
 }
void pm::insert_next(pm* x){
     x->next=this;

     }
void pm::insert_previous(pm* x){
    this->previous=x;

     }



bool pm::decay_pm(LL *atmosphere) {
	return true;

}

int pm::x_location(){
	return x;

}
int pm::y_location(){
	return y;

}

void pm::display_pm() {
    //cout<<" x = "<<x<<" y = "<<y<<endl;
	cout<<"o";

}




super_pm::super_pm(int x_locate,int y_locate):pm(x_locate,y_locate){
    recieved_ion=0;
}




bool super_pm::decay_pm(LL *atmosphere) {
	recieved_ion++;
	if(recieved_ion>=3){
		
        pm*A;
		A=new pm(x,y); //create small pm
		atmosphere->add_pm(A);
		if(x==150){
		A=new pm(x-1,y);
		atmosphere->add_pm(A);
		A=new pm(x,y-1);
		atmosphere->add_pm(A);

		}
		else if(x==1){
		A=new pm(x+1,y);
		atmosphere->add_pm(A);
		A=new pm(x,y-1);
		atmosphere->add_pm(A);

		}
		else{
		A=new pm(x+1,y);
		atmosphere->add_pm(A);
		A=new pm(x-1,y);
		atmosphere->add_pm(A);
		}

		return true;
	}
	else {
		return false;
	}

}

void super_pm::display_pm() {
	textcolor(10,0);
	cout<<"X";
	resetcolor();
}

super_pm::~super_pm(){
//	cout<<"OUt of pm class";
}