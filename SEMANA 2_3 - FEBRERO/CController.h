#pragma once
#ifndef CCONTROLLER_H
#define CCONTROLLER_H

#include"CRectangle.h"
#include"CCircle.h"
#include"CDiamond.h"

using System::Windows::Forms::KeyEventArgs;
using System::Windows::Forms::Keys;

class CController {

private:
	CRectangle* rec;
	CCircle* cir;
	CDiamond* diam_;

	int cont;
	int carreras;

	void iniciar_nueva_carrera() {

		/*Reseteo rectangulo*/
		rec->set_llego(false);
		rec->set_x(0); rec->set_place(0);

		/*Reseteo circulo*/
		cir->set_llego(false);
		cir->set_x(0); cir->set_place(0);

		/*Reseteo rombo*/
		diam_->set_llego(false);
		diam_->set_x(0); diam_->set_place(0);

		cont = 0;
	}
public:
	CController() {
		srand(time(NULL));

		rec = new CRectangle(0, 50);
		cir = new CCircle(0, 210);
		diam_ = new CDiamond(0, 350);

		cont = 0;
		carreras = 5;
	}
	~CController() {
		delete rec;
		delete cir;
		delete diam_;
	}
	void input(KeyEventArgs^ e) {

		if (e->KeyCode == Keys::D && carreras != 0) {
			iniciar_nueva_carrera();
			carreras -= 1;
		}
	}
	void mover(Graphics^ gr) {

		if (rec->get_llego()) {
			rec->set_place(++cont);
			if (rec->get_place() == 1) {
				rec->incrementar_victoria();
			}
		}
		else {
			rec->mover(gr);
		}

		if (cir->get_llego()) {
			cir->set_place(++cont);
			if (cir->get_place() == 1) {
				cir->incrementar_victoria();
			}
		}
		else {
			cir->mover(gr);
		}

		if (diam_->get_llego()) {
			diam_->set_place(++cont);
			if (diam_->get_place() == 1) {
				diam_->incrementar_victoria();
			}
		}
		else {
			diam_->mover(gr);
		}
	}
	void pintar(Graphics^ gr) {

		/*Pintando la meta*/
		Pen^ pen = gcnew Pen(Color::Yellow, 4);
		gr->DrawLine(pen, 700, 0, 700, 500);
		/*Pintando figuras.*/
		rec->pintar(gr);
		cir->pintar(gr);
		diam_->pintar(gr);
	}
	bool terminar_carrera() {

		if (carreras == 0) {
			return true;
		}
		return false;
	}
	CRectangle* get_rectangle() {
		return rec;
	}
	CCircle* get_circle() {
		return cir;
	}
	CDiamond* get_diamond() {
		return diam_;
	}
};

#endif // !CCONTROLLER_H

