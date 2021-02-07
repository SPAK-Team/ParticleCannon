#include "display.h"
#include "ion.h"
#include "pm.h"
#include "LL.h"
LL::LL()
{
	hol = NULL;
	size = 0;
}

LL::~LL()
{
	int i;
	pm* t;
	for (i = 0; i < size; i++)
	{
		t = hol;
		hol = hol->move_next();
		delete t;
	}
}

void LL::show_all()
{
	pm* t = hol;
	int i;
	cout << "Size : " << size << endl;
	for (i = 0; i < size; i++)
	{
		t->show_pm();
		t = t->move_next();
	}
}

void LL::insert_between(pm* t, pm* A)
{
	A->insert_next(t->move_prev());
	t->insert_next(A);
	A->insert_previous(t->move_prev());
	t->insert_previous(A);
	/*
			t->previous->next=A;
			A->next=t;
			A->previous=t->previous;
			t->previous=A;
			*/
}
void LL::insert_front(pm* t, pm* A)
{
	t->insert_next(A);
	t->insert_previous(A);
	//t=A;
	/*
			A->next=t;
			t->previous=A;
			t=A;
			*/
}
void LL::insert_last(pm* t, pm* A)
{
	A->insert_previous(t);
	A->insert_next(t);
	/*A->previous=t;
				t->next=A;*/
}

void LL::add_pm(pm*& A)
{

	pm* t = hol;

	int i, count = 0;
	while (count == 0)
	{

		if (size == 0)
		{
			hol->insert_next(A);
			A->insert_previous(hol);

			/*A->next=hol;
			A->previous=hol;*/
			hol = A;
			size++;
			count++;
		}

		else
		{

			if (A->y_location() < t->y_location() && t->move_prev() != NULL)
			{

				this->insert_between(t, A);
				size++;
				count++;
			}
			else if (A->y_location() < t->y_location() && t->move_prev() == NULL)
			{

				this->insert_front(t, A);
				size++;
				count++;
			}

			else if (A->y_location() == t->y_location())
			{
				if (A->x_location() < t->x_location() && t->move_prev() != NULL)
				{

					this->insert_between(t, A);
					size++;
					count++;
				}
				else if (A->x_location() < t->x_location() && t->move_prev() == NULL)
				{
					this->insert_front(t, A);
					size++;
					count++;
				}
				else if (A->x_location() == t->x_location())
				{
					delete A; // find how to solve about this
					count++;
				}
				else if (A->x_location() > t->x_location() && t->move_next() == NULL)
				{

					this->insert_last(t, A);
					size++;
					count++;
				}
				else
					t = t->move_next();
			}
			else if (A->y_location() > t->y_location() && t->move_next() == NULL)
			{
				this->insert_last(t, A);
				size++;
				count++;
			}
			else
				t = t->move_next();
		}
	}

	t = hol;
	while (t->move_prev() != NULL)
	{
		t = t->move_prev();
	}
	hol = t;
}

void LL::shot(int shoot, ion& me)
{

	pm* t = hol;

	int i, count = 0;

	while (t->move_next() != NULL)
	{

		t = t->move_next();
	}

	do
	{

		if (shoot == t->x_location())
		{
			++me;

			if (hol == t)
			{
				if (t->decay_pm(this)) {
					hol = t->move_next();
					delete t;
					size--;
				}
				count++;
			}
			else if (t->move_next() != NULL && t->move_prev() != NULL)
			{
				if (t->decay_pm(this)) {
					t->move_next()->insert_next(t->move_prev());
					//(t->prev)->next=t->next;
					t->move_next()->insert_previous(t->move_prev());
					//(t->next)->previous=t->pevious;
					delete t;
					size--;
				}
				count++;
			}
			else if (t->move_prev() == NULL && t->move_next() != NULL)
			{
				if (t->decay_pm(this)) {
					hol = t->move_next();
					t->move_next()->insert_previous(t->move_prev());
					//(t->next)->previous=t->previous;
					delete t;
					size--;
				}
				count++;
			}
			else if (t->move_prev() != NULL && t->move_next() == NULL)
			{
				if (t->decay_pm(this)) {
					t->move_next()->insert_next(t->move_prev());
					delete t;
					size--;
				}
				count++;

			}
			else
				t = t->move_prev();
		}
		else
			t = t->move_prev();

	} while (t->move_prev() != NULL && count == 0);
}

void LL::display_all_pm(ion me)
{
	pm* t = hol;

	int y;
	int x;

	cout << "=======||======================================================================================================================================================||===================\n";
	for (y = 1; y < 39; y++)
	{
		space_out(8);
		cout << "||";
		for (x = 1; x < 151; x++)
		{
			if (y == t->y_location() && x == t->x_location())
			{
				t->display_pm();
				if (t->move_next() != NULL)
					t = t->move_next();
			}
			else if (x == me.x_location())
			{
				textcolor(12, 0);
				cout << "|";
				resetcolor();
			}
			else
				cout << " ";
		}
		if (y == 1)
			cout << "||   a = move left   ";
		else if (y == 2)
			cout << "||   d = move right  ";
		else if (y == 3)
			cout << "||   s = shoot       ";
		else if (y == 4)
			cout << "||   c = charge      ";
		else if (y == 5)
			cout << "||   o = exit        ";
		else if (y == 6)
			cout << "||   score = " << me.show_score();
		else if (y == 7)
			cout << "||   has ion = " << me.show_amount_ion();
		else if (y == 9)
			cout << "||   AQI = " << size;
		else
			cout << "||";

		cout << endl;
	}
}

void LL::display_all_with_ion_shot(ion me)
{
	pm* t = hol;

	int y;
	int x;
	int i, j; // ion's x,y
	int y_last = 0;
	int loop;
	int a = 0;
	i = me.x_location();
	j = 35;

	while (t->move_next() != NULL)
	{
		t = t->move_next();
	}

	for (loop = 0; loop < size, y_last == 0; loop++)
	{

		if (i == (t->x_location()))
		{
			y_last = t->y_location();

			break;
		}
		else
		{
			if (t->move_prev() == NULL)
				break;

			t = t->move_prev();
			cout << t->y_location();
		}
	}

	do
	{
		t = hol;
		system("CLS");
		cout << "=======||======================================================================================================================================================||===================\n";
		for (y = 1; y < 39; y++)
		{
			space_out(8);
			cout << "||";
			for (x = 1; x < 151; x++)
			{
				if (y == t->y_location() && x == t->x_location())
				{
					t->display_pm();
					x++;
					if (t->move_next() != NULL)
					{
						t = t->move_next();
					}
				}
				if (y == j && x == i)
				{
					textcolor(14, 0);
					cout << "*";
					resetcolor();
				}

				else if (y > j && x == i)
				{
					textcolor(8, 0);
					cout << "|";
					resetcolor();
				}
				else
					cout << " ";
			}
			if (y == 1)
				cout << "||   a = move left   ";
			else if (y == 2)
				cout << "||   d = move right  ";
			else if (y == 3)
				cout << "||   s = shoot       ";
			else if (y == 4)
				cout << "||   c = charge      ";
			else if (y == 5)
				cout << "||   o = exit        ";
			else if (y == 6)
				cout << "||   score = " << me.show_score();
			else if (y == 7)
				cout << "||   has ion = " << me.show_amount_ion();
			else if (y == 9)
				cout << "||   AQI = " << size;
			else
				cout << "||";

			cout << endl;
		}
		me.display_cannon(i);
		a++;

		j--;
		system("CLS");
	} while (j > y_last);
}