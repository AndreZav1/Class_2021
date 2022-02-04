#pragma once

#include"CCuadrado.h"
#include"CCirculo.h"

#include<vector>

using namespace System::Windows::Forms;

class CControladora {

private:
	std::vector<CCuadrado*>arr_cuadr;
	std::vector<CCirculo*>arr_cir;

public:
	CControladora() {
	}
	~CControladora() {
	}
	void create_figure(MouseEventArgs^ me) {

		Random r;

		int n = r.Next(0, 2);
		if (n == 0) {
			arr_cuadr.push_back(new CCuadrado(me->X, me->Y));
		}
		else {
			arr_cir.push_back(new CCirculo(me->X, me->Y));
		}
	}
	void Mover(Graphics^ g) {

		for (int i = 0; i < arr_cuadr.size(); i += 1) {
			arr_cuadr.at(i)->Mover(g);
		}
		for (int i = 0; i < arr_cir.size(); i += 1) {
			arr_cir.at(i)->Mover(g);
		}
	}
	void Pintar(Graphics^ g) {

		for (int i = 0; i < arr_cuadr.size(); i += 1) {
			arr_cuadr.at(i)->Pintar(g);
		}
		for (int i = 0; i < arr_cir.size(); i += 1) {
			arr_cir.at(i)->Pintar(g);
		}
	}
};