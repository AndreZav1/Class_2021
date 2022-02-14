#pragma once
#ifndef CCONTROLADORA_H
#define CCONTROLADORA_H

#include"CAsh.h"
#include"CBolas.h"

#include<vector>
#include<ctime>

using namespace System::Windows::Forms;

class CControladora {

private:
	CAsh* my_ash;
	std::vector<CBolas*>arr_bolas;

	int t;
	int my_time;

	int time_aparecer_bolas;

	void aparecer_bolas(Graphics^ gr) {

		Random r;

		if (difftime(time(0), time_aparecer_bolas) > 4) {

			for (int i = 0; i < 4; i += 1) {
				arr_bolas.push_back(new CBolas(r.Next(0, (int)gr->VisibleClipBounds.Width - 50), r.Next(0, 20)));
			}
			time_aparecer_bolas = time(0);
		}
	}
	void eliminar_bola_en(int pos) {

		arr_bolas.erase(arr_bolas.begin() + pos);
	}
	void generar_bola(Graphics^ gr) {
		Random r;
		arr_bolas.push_back(new CBolas(r.Next(0, (int)gr->VisibleClipBounds.Width - 50), r.Next(0, 20)));
	}
	void collision(Graphics^ gr) {

		for (int i = 0; i < arr_bolas.size(); i += 1) {
			if (arr_bolas.at(i)->area().IntersectsWith(my_ash->area())) {
				arr_bolas.at(i)->set_visible(false);
				my_ash->decrease_hp();
				generar_bola(gr);
			}
		}

		for (int i = 0; i < arr_bolas.size(); i += 1) {
			if (!arr_bolas.at(i)->get_visible()) {
				eliminar_bola_en(i);
			}
		}
	}
public:
	CControladora(int t, Graphics^ gr) {
		my_ash = new CAsh((gr->VisibleClipBounds.Width / 2) - 68, (gr->VisibleClipBounds.Height) - 76);

		this->t = t * 1000;

		time_aparecer_bolas = time(0);
	}
	~CControladora() {
		delete my_ash;
		for each (CBolas * _iterator in arr_bolas) {
			delete _iterator;
		}
	}
	void input(KeyEventArgs^ e, bool validate) {

		int speed = 5;

		if (validate) {

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

		aparecer_bolas(gr);
		my_ash->mover(gr);
		for each (CBolas * _iterator in arr_bolas) {
			_iterator->mover(gr);
		}
		collision(gr);
	}
	void pintar(Graphics^ gr, Bitmap^ btpAsh) {

		my_time = (t - clock()) / 1000;
		gr->DrawString("Tiempo: " + my_time, gcnew System::Drawing::Font("Times New Roman", 14), gcnew System::Drawing::SolidBrush(Color::Black), (int)gr->VisibleClipBounds.Width - 110, 0);
		gr->DrawString("Vidas: " + my_ash->get_hp(), gcnew System::Drawing::Font("Times New Roman", 14), gcnew System::Drawing::SolidBrush(Color::Black), 10, 0);

		my_ash->pintar(gr, btpAsh);
		for each (CBolas * _iterator in arr_bolas) {
			_iterator->pintar(gr);
		}
	}
	bool you_defeat() {

		if (my_ash->get_hp() == 0) {
			return true;
		}
		return false;
	}
	bool you_win() {

		if(my_time == 0){
			return true;
		}
		return false;
	}
};

#endif // CCONTROLADORA_H


