#pragma once
#include"CAsh.h"
#include"CBala.h"

#include<vector>
#include<ctime>
using namespace System::Windows::Forms;

class CControladora {

private:
	CAsh* my_ash;
	std::vector<CBala*>arr_bala;

	void eliminar_bala_en(int pos) {
		arr_bala.erase(arr_bala.begin() + pos);
	}
	void colisiones(Graphics^ gr) {

		for (int i = 0; i < arr_bala.size(); i += 1) {
			if (arr_bala.at(i)->area().IntersectsWith(my_ash->area())) {
				arr_bala.at(i)->set_visible(false);
				my_ash->decrease_hp();
			}
		}

		Random r;

		for (int i = 0; i < arr_bala.size(); i += 1) {
			if (!arr_bala.at(i)->get_visible() || arr_bala.at(i)->get_dy() == 0) {
				eliminar_bala_en(i);
				arr_bala.push_back(new CBala(gr, r.Next(0, gr->VisibleClipBounds.Width - 50), r.Next(0, 20)));
			}
		}
	}

	int t;
	int my_time;
public:
	CControladora(Graphics^ gr, int t) {
		Random r;
		my_ash = new CAsh((gr->VisibleClipBounds.Width / 2) - 68, (gr->VisibleClipBounds.Height) - 75);
		for (int i = 0; i < 5; i += 1) {
			arr_bala.push_back(new CBala(gr, r.Next(0, gr->VisibleClipBounds.Width - 50), r.Next(0, 20)));
		}
		this->t = t * 1000;
	}
	~CControladora() {
		delete my_ash;
		for each (CBala * _iterator in arr_bala) {
			delete _iterator;
		}
	}
	void input(KeyEventArgs^ e, bool validate_movement) {

		int speed = 5;

		if (validate_movement) {

			switch (e->KeyCode)
			{
			case Keys::A: {
				my_ash->set_dx(-speed);
				my_ash->set_idy(1);
			}break;

			case Keys::D: {
				my_ash->set_dx(speed);
				my_ash->set_idy(2);
			}break;

			case Keys::W: {
				my_ash->set_dy(-speed);
				my_ash->set_idy(3);
			}break;

			case Keys::S: {
				my_ash->set_dy(speed);
				my_ash->set_idy(0);
			}break;
			}
		}
		else
		{
			switch (e->KeyCode)
			{
			case Keys::A: {
				my_ash->set_dx(0);
			}break;

			case Keys::D: {
				my_ash->set_dx(0);
			}break;

			case Keys::W: {
				my_ash->set_dy(0);
			}break;

			case Keys::S: {
				my_ash->set_dy(0);
			}break;
			}
		}
	}
	void mover(Graphics^ gr) {
		colisiones(gr);

		my_ash->mover(gr);
		for each (CBala * _iterator in arr_bala) {
			_iterator->mover(gr);
		}
	}
	void pintar(Graphics^ gr, Bitmap^ btpAsh, Bitmap^ btpBala) {

		my_time = t - clock();

		gr->DrawString("Vidas: " + my_ash->get_hp(), gcnew Drawing::Font("Times New Roman", 14), gcnew Drawing::SolidBrush(Color::Black), 10, 0);
		gr->DrawString("Tiempo: " + my_time, gcnew Drawing::Font("Times New Roman", 14), gcnew Drawing::SolidBrush(Color::Black), gr->VisibleClipBounds.Width - 120, 0);

		my_ash->pintar(gr, btpAsh);
		for each (CBala * _iterator in arr_bala) {
			_iterator->pintar(gr, btpBala);
		}
	}
	bool you_win() {

		if (my_time <= 0) {
			return true;
		}
		return false;
	}
	bool you_defeat() {

		if (my_ash->get_hp() <= 0) {
			return true;
		}
		return false;
	}
};
