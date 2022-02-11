#pragma once

#include"CFigura.h"

class CCuadrado : public CFigura {

public:
	CCuadrado(int x, int y)
		:CFigura(x, y) {
	}
	~CCuadrado() {
	}
	void pintar(Graphics^ g) {

		Pen^ pen = gcnew Pen(Color::FromArgb(_r, _g, _b));
		g->DrawRectangle(pen, x, y, width, width);
	}
};