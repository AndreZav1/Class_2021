#pragma once

#include"CFigura.h"

class CCuadrado : public CFigura {

public:
	CCuadrado(int x, int y)
		:CFigura(x, y) {
	}
	~CCuadrado() {
	}
	void Pintar(Graphics^ g) {

		Pen^ p = gcnew Pen(Brushes::Cyan, 4);
		g->DrawRectangle(p, x, y, width, height);
	}
};
