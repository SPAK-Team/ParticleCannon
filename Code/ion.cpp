#include "display.h"
#include "ion.h"
#include "pm.h"
#include "LL.h"
ion ::ion(int e,int s){
	amount_ion=e;
   	x = 1;
  	y = 39;
  	score=s;

  	//system(plasue)
  	//cannon(x);
}
int ion::show_amount_ion(){
    return amount_ion;

}
int ion::show_score(){
	
    return score;
}

void ion::operator++(){
    score=score+1;
}
int ion::x_location(){
    return x;
}

int ion::  shoot_ion(){
	   amount_ion--;
	   return x;


}

void ion:: move_ion(char input){
	   if(input=='a'&&x>1){
	   	x--;





	   }
	   else if (input=='d'&&x<150){
	   	x++;





	   }
}

void ion:: charge_ion(){
        if(score>=10){
	   	amount_ion+=20;
	   	score=score-10;
        }
	   }


ion::~ion(){
	//cout<<endl<<" x="<<x<<" y="<<y<<endl;
}


void ion::display_cannon(int x){

	
	cout<<endl;
	space_out(x);
   	cout<<"        _|_ "<<endl;
   		space_out(x);
	cout<<"       (   )"<<endl;
		space_out(x);
	cout<<"        | |"<<endl;
		space_out(x);
	cout<<"        | |"<<endl;
		space_out(x);
	cout<<"      __|_|__"<<endl;
		space_out(x);
	cout<<"     / [O O] \\"<<endl;
		space_out(x);
	cout<<"  __/_________\\__"<<endl;
		space_out(x);
	cout<<" /    _______    \\"<<endl;
		space_out(x);
	cout<<"/  _ |_______| _  \\ "<<endl;
		space_out(x);
	cout<<"|_/ \\_| H_H |_/ \\_|"<<endl;
		space_out(x);
	cout<<"  |_|---------|_|"<<endl;


}